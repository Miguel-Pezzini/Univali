#include <iostream>
#include <fstream>
using namespace std;

struct Produto {
    int Codigo;
    string Nome;
    float Preco;
    Produto *proximo;
};

//estrutura da lista
struct ListaE {
    Produto * inicio;
};
//inicializa lista
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
//Protótipo da inserção
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
        lista.inicio = prodTemp->proximo;  // Atualiza a cabeça da lista
        delete prodTemp;  // Libera a memória
        return true;
    }

    // Caso o produto não seja o primeiro, percorre a lista
    while (prodTemp != NULL && prodTemp->Codigo != cod) {
        produtoAnterior = prodTemp;
        prodTemp = prodTemp->proximo;
    }

    // Caso o produto não tenha sido encontrado
    if (prodTemp == NULL) {
        return false; // Produto não encontrado
    }

    // Desconecta o nó da lista e deleta
    produtoAnterior->proximo = prodTemp->proximo;
    delete prodTemp;  // Libera a memória

    return true;
}

bool pesquisar_elemento_lista(ListaE &lista, int cod) {
    if(verificar_codigo_existente(lista, cod)) {
        return false;
    }
    
    Produto *temp = lista.inicio;
    
    while(temp != NULL) {
        if(temp->Codigo == cod) {
            cout<<"PREÇO DO PRODUTO: "<<temp->Preco<<endl;
        }
        temp = temp->proximo;
    }
    
    return true;
}

bool pesquisar_todos_elementos_lista(ListaE &lista) {
    if(lista.inicio == NULL) {
        return false;
    }
    
    Produto *temp = lista.inicio;
    
    while(temp != NULL) {
        cout<<"Código do produto: "<<temp->Codigo<<endl;
        cout<<"Nome do produto: "<<temp->Nome<<endl;
        cout<<"Preço do produto: "<<temp->Preco<<endl<<endl;
        
        temp = temp->proximo;
    }
    
    return true;
}

void salvar_lista(ListaE &lista) {
    ofstream arquivo("produtos.txt");
    Produto* p = lista.inicio;
    while (p != nullptr) {
        arquivo << p->Codigo << "\n" << p->Nome << "\n" << p->Preco << "\n";
        p = p->proximo;
    }
    arquivo.close();
}

void carregar_lista(ListaE &lista) {
    ifstream arquivo("produtos.txt");
    while (arquivo) {
        Produto* prod = new Produto;
        arquivo >> prod->Codigo;
        arquivo.ignore();  // Ignora a nova linha após o código
        getline(arquivo, prod->Nome);
        arquivo >> prod->Preco;
        arquivo.ignore();  // Ignora a nova linha após o preço

        if (arquivo) {
            insere_elemento_lista(lista, prod);
        }
    }
    arquivo.close();
}

int main()
{
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
                cout<<"Insira o código do Produto: ";
                cin>>prod->Codigo;
                cout<<"Insira o nome do produto: ";
                cin>>prod->Nome;
                cout<<"Insira o preço do produto: ";
                cin>>prod->Preco; 
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