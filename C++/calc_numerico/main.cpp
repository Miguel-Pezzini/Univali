#include <bits/stdc++.h>
using namespace std;

// -------------------------
// 1. Cálculo de Erro
// -------------------------
double erroAbsoluto(double valorReal, double valorAproximado) {
    return fabs(valorReal - valorAproximado);
}

double erroRelativo(double valorReal, double valorAproximado) {
    return fabs((valorReal - valorAproximado) / valorReal);
}

// -------------------------
// 2. Conversão Base 2 <-> Base 10
// -------------------------
int binarioParaDecimal(string bin) {
    return stoi(bin, nullptr, 2);
}

string decimalParaBinario(int n) {
    string bin = "";
    if (n == 0) return "0";
    while (n > 0) {
        bin = char((n % 2) + '0') + bin;
        n /= 2;
    }
    return bin;
}

// -------------------------
// 3. Teorema de Cauchy-Bolzano
// Verifica se f(a)*f(b) < 0 (mudança de sinal)
// -------------------------
bool cauchyBolzano(function<double(double)> f, double a, double b) {
    return (f(a) * f(b) < 0);
}

// -------------------------
// 4. Método da Bisseção
// -------------------------
double bissecao(function<double(double)> f, double a, double b, double tol, int maxIter = 1000) {
    if (f(a) * f(b) >= 0) {
        throw runtime_error("Intervalo inválido para o método da bisseção");
    }
    double c;
    for (int i = 0; i < maxIter; i++) {
        c = (a + b) / 2.0;
        if (fabs(f(c)) < tol || (b - a) / 2 < tol) {
            return c;
        }
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

// -------------------------
// 5. Método de Newton-Raphson
// -------------------------
double newtonRaphson(function<double(double)> f, function<double(double)> df, double x0, double tol, int maxIter = 1000) {
    double x = x0;
    for (int i = 0; i < maxIter; i++) {
        double fx = f(x);
        double dfx = df(x);
        if (fabs(dfx) < 1e-12) throw runtime_error("Derivada próxima de zero");
        double x1 = x - fx / dfx;
        if (fabs(x1 - x) < tol) return x1;
        x = x1;
    }
    return x;
}

// -------------------------
// 6. Regra de Cramer
// Resolve sistema Ax = b
// -------------------------
vector<double> cramer(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    double detA = 0;

    // Determinante da matriz A
    function<double(vector<vector<double>>)> determinante = [&](vector<vector<double>> M) {
        int n = M.size();
        if (n == 1) return M[0][0];
        if (n == 2) return M[0][0]*M[1][1] - M[0][1]*M[1][0];
        double det = 0;
        for (int j = 0; j < n; j++) {
            vector<vector<double>> subM(n-1, vector<double>(n-1));
            for (int i2 = 1; i2 < n; i2++) {
                int col = 0;
                for (int j2 = 0; j2 < n; j2++) {
                    if (j2 == j) continue;
                    subM[i2-1][col++] = M[i2][j2];
                }
            }
            det += pow(-1, j) * M[0][j] * determinante(subM);
        }
        return det;
    };

    detA = determinante(A);
    if (fabs(detA) < 1e-12) throw runtime_error("Sistema sem solução única");

    vector<double> x(n);
    for (int i = 0; i < n; i++) {
        vector<vector<double>> Ai = A;
        for (int j = 0; j < n; j++) {
            Ai[j][i] = b[j];
        }
        x[i] = determinante(Ai) / detA;
    }
    return x;
}

// -------------------------
// 7. Substituição retroativa
// Resolve Ux = b, U triangular superior
// -------------------------
vector<double> substituicaoRetroativa(vector<vector<double>> U, vector<double> b) {
    int n = U.size();
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double soma = 0;
        for (int j = i + 1; j < n; j++) {
            soma += U[i][j] * x[j];
        }
        if (fabs(U[i][i]) < 1e-12) throw runtime_error("Divisão por zero");
        x[i] = (b[i] - soma) / U[i][i];
    }
    return x;
}

// -------------------------
// Exemplo de uso
// -------------------------
int main() {
    // Exemplo: Erro
    cout << "Erro absoluto: " << erroAbsoluto(3.14159, 3.14) << endl;
    cout << "Erro relativo: " << erroRelativo(3.14159, 3.14) << endl;

    // Exemplo: Conversão
    cout << "Binario 1011 = " << binarioParaDecimal("1011") << endl;
    cout << "Decimal 13 = " << decimalParaBinario(13) << endl;

    // Exemplo: Bisseção (f(x) = x^2 - 2)
    auto f = [](double x){ return x*x - 2; };
    cout << "Raiz por bissecao: " << bissecao(f, 0, 2, 1e-6) << endl;

    // Exemplo: Newton-Raphson
    auto df = [](double x){ return 2*x; };
    cout << "Raiz por Newton: " << newtonRaphson(f, df, 1, 1e-6) << endl;

    // Exemplo: Regra de Cramer
    vector<vector<double>> A = {{2, -1}, {1, 2}};
    vector<double> b = {1, 3};
    auto sol = cramer(A, b);
    cout << "Solucao Cramer: x=" << sol[0] << " y=" << sol[1] << endl;

    // Exemplo: Substituição retroativa
    vector<vector<double>> U = {{2, 1}, {0, 3}};
    vector<double> b2 = {5, 9};
    auto x = substituicaoRetroativa(U, b2);
    cout << "Solucao retroativa: x=" << x[0] << " y=" << x[1] << endl;

    return 0;
}
