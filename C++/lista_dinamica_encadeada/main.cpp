#include <iostream>
#include <fstream>
#include "lib.h"

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
    ListaE listaDeProdutos;
    inicializa_lista(listaDeProdutos);
    
    carregar_lista(listaDeProdutos);
    
    int opt;
    int cod;
    while(opt != 6 && opt != 5) {
        Produto *prod = new Produto;
        cout<<"Selecione a sua opção: "<<endl;
        cout<<"1. ADICIONAR PRODUTO"<<endl;
        cout<<"2. REMOVER PRODUTO"<<endl;
        cout<<"3. PESQUISAR PRODUTO"<<endl;
        cout<<"4. LISTA DE TODOS OS PRODUTOS"<<endl;
        cout<<"5. SALVAR LISTA EM ARQUIVO"<<endl;
        cout<<"6. SAIR"<<endl;
        cin>>opt;
        
        switch(opt) {
            case 1:
                prod = criar_produto();
                if(insere_elemento_lista(listaDeProdutos, prod)) {
                    cout<<"Produto inserido com Sucesso!"<<endl<<endl;
                } else {
                    cout<<"ERRO! Código digitado já existente!"<<endl<<endl;
                }
            break;
            case 2:
                cout<<"Insira o código do produto que você deseja deletar: ";
                cin>>cod;
                if(deleta_elemento_lista(listaDeProdutos, cod)) {
                    cout<<"O elemento foi deletado com sucesso!"<<endl<<endl;
                } else {
                    cout<<"ERRO! O código inserido é inválido!"<<endl<<endl;
                };
            break;
            case 3:
                cout<<"Insira o código do produto que você deseja pesquisar: ";
                cin>>cod;
                if(!pesquisar_elemento_lista(listaDeProdutos, cod)) {
                     cout<<"ERRO! O código inserido é inválido!"<<endl<<endl;
                } 
            break;
            case 4:
                if(!pesquisar_todos_elementos_lista(listaDeProdutos)) {
                    cout<<"Lista está vazia!"<<endl<<endl;
                }
            break;
            case 5:
                salvar_lista(listaDeProdutos);
            break;
        }
    }

    return 0;
}