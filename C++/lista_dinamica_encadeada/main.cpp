#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include "lib.h"
#include <locale.h>

using namespace std;

Produto* criar_produto() {
    Produto *prod = new Produto;
    int cod;
    string nome;
    float preco;

    cout<<"Insira o código do Produto: ";
    cin>>prod->Codigo;
    cout<<"Insira o nome do produto: ";
    cin>>prod->Nome;
    cout<<"Insira o preço do produto: ";
    cin>>prod->Preco;

    return prod;
}

int main() {
    setlocale(LC_ALL, "portuguese");
    ListaE listaDeProdutos;
    inicializa_lista(listaDeProdutos);

    carregar_lista(listaDeProdutos);

    int opt;
    int cod;
    while(opt != 7 && opt != 5) {
        Produto *prod = new Produto;
        cout<<"Selecione a sua opção: "<<endl;
        cout<<"1. ADICIONAR PRODUTO"<<endl;
        cout<<"2. REMOVER PRODUTO"<<endl;
        cout<<"3. PESQUISAR PRODUTO"<<endl;
        cout<<"4. LISTA DE TODOS OS PRODUTOS"<<endl;
        cout<<"5. SALVAR LISTA EM ARQUIVO"<<endl;
        cout<<"6. SOBRE O TRABALHO"<<endl;
        cout<<"7. SAIR"<<endl;
        cin>>opt;

        switch(opt) {
            case 1:
                (void)system("cls");
                prod = criar_produto();
                if(insere_elemento_lista(listaDeProdutos, prod)) {
                    cout<<"Produto inserido com Sucesso!"<<endl<<endl;
                } else {
                    cout<<"ERRO! Código digitado já existente!"<<endl<<endl;
                }
            break;
            case 2:
                (void)system("cls");
                cout<<"Insira o código do produto que você deseja deletar: ";
                cin>>cod;
                if(deleta_elemento_lista(listaDeProdutos, cod)) {
                    cout<<"O elemento foi deletado com sucesso!"<<endl<<endl;
                } else {
                    cout<<"ERRO! O código inserido é inválido!"<<endl<<endl;
                };
            break;
            case 3:
                (void)system("cls");
                cout<<"Insira o código do produto que você deseja pesquisar: ";
                cin>>cod;
                pesquisar_elemento_lista(listaDeProdutos, cod);
            break;
            case 4:
                (void)system("cls");
                if(!pesquisar_todos_elementos_lista(listaDeProdutos)) {
                    cout<<"Lista está vazia!"<<endl<<endl;
                }
            break;
            case 5:
                (void)system("cls");
                salvar_lista(listaDeProdutos);
            break;
            case 6:
                (void)system("cls");
                cout<<"Trabalho Feito por: Miguel Pezzini Kuhr, Rafael de Souza Barbosa, Eduarda Mendes Amorim e Victoria de Souza Rocha"<<endl<<endl;
            break;
        }
    }

    return 0;
}
