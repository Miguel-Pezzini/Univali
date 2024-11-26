#ifndef lib_h
#define lib_h

#include <iostream>
#include <vector>

using namespace std;

struct Produto {
    int Codigo;
    string Nome;
    float Preco;
    Produto *proximo;
};

struct ListaE {
    Produto * inicio;
};

bool inicializa_lista (ListaE &lista){
    lista.inicio = NULL;
    return true;
}

bool verificar_codigo_existente(ListaE const &lista, int cod) {
    Produto *temp = lista.inicio;

    while(temp != NULL) {
        if(temp->Codigo == cod) {
            return false;
        }
        temp = temp->proximo;
    }
    return true;
}

bool insere_elemento_lista(ListaE &lista, Produto *prod) {

    if(verificar_codigo_existente(lista, prod->Codigo)) {
        prod->proximo = lista.inicio;
        lista.inicio = prod;
        return true;
    }

    return false;
};

bool deleta_elemento_lista(ListaE &lista, int cod) {
    if (lista.inicio == NULL || verificar_codigo_existente(lista, cod)) { // Lista vazia
        return false;
    }

    Produto *prodTemp = lista.inicio;
    Produto *produtoAnterior = NULL;

    // Caso o produto a ser deletado seja o primeiro da lista
    if (prodTemp->Codigo == cod) {
        lista.inicio = prodTemp->proximo;  // Atualiza a cabe�a da lista
        delete prodTemp;  // Libera a mem�ria
        return true;
    }

    // Caso o produto n�o seja o primeiro, percorre a lista
    while (prodTemp != NULL && prodTemp->Codigo != cod) {
        produtoAnterior = prodTemp;
        prodTemp = prodTemp->proximo;
    }

    // Caso o produto n�o tenha sido encontrado
    if (prodTemp == NULL) {
        return false; // Produto n�o encontrado
    }

    // Desconecta o n� da lista e deleta
    produtoAnterior->proximo = prodTemp->proximo;
    delete prodTemp;  // Libera a mem�ria

    return true;
}

void pesquisar_elemento_lista(ListaE &lista, int cod) {
    if(verificar_codigo_existente(lista, cod)) {
        cout<<"PRE�O DO PRODUTO: 0"<<endl<<endl;
    }

    Produto *temp = lista.inicio;

    while(temp != NULL) {
        if(temp->Codigo == cod) {
            cout<<"PRE�O DO PRODUTO: "<<temp->Preco<<endl<<endl;
        }
        temp = temp->proximo;
    }
}

bool pesquisar_todos_elementos_lista_recursiva(Produto * &inicio) {
    if (inicio == NULL) {
        return true;
    }
    Produto* temp = inicio;

    cout<<"C�digo do produto: "<<temp->Codigo<<endl;
    cout<<"Nome do produto: "<<temp->Nome<<endl;
    cout<<"Pre�o do produto: "<<temp->Preco<<endl<<endl;


    return pesquisar_todos_elementos_lista_recursiva(inicio->proximo);
}

bool pesquisar_todos_elementos_lista(ListaE &lista) {
    if(lista.inicio == NULL) {
        return false;
    }
    return pesquisar_todos_elementos_lista_recursiva(lista.inicio);
}



void salvar_lista(ListaE &lista) {
    ofstream arquivo("produtos.txt");
    Produto* p = lista.inicio;
    while (p != NULL) {
        arquivo << p->Codigo << "\n" << p->Nome << "\n" << p->Preco << "\n";
        p = p->proximo;
    }
    arquivo.close();
}

void carregar_lista(ListaE &lista) {
    ifstream arquivo("produtos.txt");

    // Vetor tempor�rio para armazenar os produtos
    vector<Produto*> produtos_temp;

    // L� o arquivo normalmente (do in�cio para o fim)
    while (arquivo) {
        Produto* prod = new Produto;
        arquivo >> prod->Codigo;
        arquivo.ignore();  // Ignora a nova linha ap�s o c�digo
        getline(arquivo, prod->Nome);
        arquivo >> prod->Preco;
        arquivo.ignore();  // Ignora a nova linha ap�s o pre�o

        if (arquivo) {
            produtos_temp.push_back(prod); // Armazena o produto no vetor
        }
    }

    // Insere os produtos na lista na ordem inversa
    for (int i = produtos_temp.size() - 1; i >= 0; --i) {
        insere_elemento_lista(lista, produtos_temp[i]);
    }

    arquivo.close();
}

#endif
