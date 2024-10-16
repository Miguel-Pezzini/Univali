#include "my_lib.h"

template <typename T, int MAX>
void addPersonalContact(Agenda<ContatoPessoal<T>, MAX> &agenda) {
  int sizeContatos = agenda.quantidade;
    if(MAX <= sizeContatos) {
        cout<<"Sua lista de contatos está cheia!";
        return;
    }
    cout<<"Informe o ID do contato: ";
    cin>>agenda.contatos[sizeContatos].ID;
    cout<<"Informe o CPF do contato: ";
    cin>>agenda.contatos[sizeContatos].CPF;
    cout<<"Informe o Celular do contato: ";
    cin>>agenda.contatos[sizeContatos].cel;
    cout<<"Informe o nome do contato: ";
    cin>>agenda.contatos[sizeContatos].nome;

    agenda.quantidade++;
}

template <typename T, int MAX>
void addComercialContact(Agenda<ContatoComercial<T>, MAX> &agenda) {
    int sizeContatos = agenda.quantidade;
    if(MAX >= sizeContatos) {
        cout<<"Sua lista de contatos está cheia!";
        return;
    }

    cout<<"Informe o ID do contato: ";
    cin>>agenda.contatos[sizeContatos].ID;
    cout<<"Informe o CNPJ do contato: ";
    cin>>agenda.contatos[sizeContatos].CNPJ;
    cout<<"Informe o telefone comercial do contato: ";
    cin>>agenda.contatos[sizeContatos].tel;
    cout<<"Informe o nome da empresa do contato: ";
    cin>>agenda.contatos[sizeContatos].empresa;

    agenda.quantidade++;
}

template <typename T, int MAX>
void removePersonalContact(Agenda<ContatoPessoal<T>, MAX> &agenda) {
    int choice = 0;
    int sizeContatos = agenda.quantidade;
    if(MAX <= sizeContatos) {
        cout<<"Sua lista de contatos está cheia!";
        return;
    }
    cout<<"Escolha entre remover pelo ID ou pelo nome do contato: "<<endl;
    cout<<"1. ID"<<endl;
    cout<<"2. Nome"<<endl;
    cin>>choice;

    if(choice == 1) {
        int IDContato;
        bool found = false;
        cout<<"Digite o ID do contato: ";
        cin>>IDContato;
        for(int i = 0; i < sizeContatos; i++) {
            if(agenda.contatos[i].ID == IDContato) {
                for (int j = i; j < sizeContatos - 1; j++) {
                    agenda.contatos[j] = agenda.contatos[j + 1];
                }
                agenda.quantidade--;
                found = true;
                cout << "Contato removido com sucesso!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Contato não encontrado!" << endl;
        }
    }
    if(choice == 2) {
        string nomeContato;
        bool found = false;
        cout<<"Digite o nome do contato: ";
        cin>>nomeContato;
        for(int i = 0; i < sizeContatos; i++) {
            if(agenda.contatos[i].nome == nomeContato) {
                for (int j = i; j < sizeContatos - 1; j++) {
                    agenda.contatos[j] = agenda.contatos[j + 1];
                }
                agenda.quantidade--;
                found = true;
                cout << "Contato removido com sucesso!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Contato não encontrado!" << endl;
        }
    }
}

template <typename T, int MAX>
void removeComercialContact(Agenda<ContatoComercial<T>, MAX> &agenda) {
    int choice = 0;
    int sizeContatos = agenda.quantidade;
    if(MAX <= sizeContatos) {
        cout<<"Sua lista de contatos está cheia!";
        return;
    }
    cout<<"Escolha entre remover pelo ID ou pelo nome da empresa: "<<endl;
    cout<<"1. ID"<<endl;
    cout<<"2. Nome da Empresa"<<endl;
    cin>>choice;

    if(choice == 1) {
        int IDContato;
        bool found = false;
        cout<<"Digite o ID do contato: ";
        cin>>IDContato;
        for(int i = 0; i < sizeContatos; i++) {
            if(agenda.contatos[i].ID == IDContato) {
                for (int j = i; j < sizeContatos - 1; j++) {
                    agenda.contatos[j] = agenda.contatos[j + 1];
                }
                agenda.quantidade--;
                found = true;
                cout << "Contato removido com sucesso!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Contato não encontrado!" << endl;
        }
    }
    if(choice == 2) {
        string nomeContato;
        bool found = false;
        cout<<"Digite o nome da empresa: ";
        cin>>nomeContato;
        for(int i = 0; i < sizeContatos; i++) {
            if(agenda.contatos[i].empresa == nomeContato) {
                for (int j = i; j < sizeContatos - 1; j++) {
                    agenda.contatos[j] = agenda.contatos[j + 1];
                }
                agenda.quantidade--;
                found = true;
                cout << "Contato removido com sucesso!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Contato não encontrado!" << endl;
        }
    }
}

template <typename T, int MAX>
void getPersonalContact(Agenda<ContatoPessoal<T>, MAX> agenda) {
    int choice;
    int sizeContatos = agenda.quantidade;
    if(MAX <= sizeContatos) {
        cout<<"Sua lista de contatos está cheia!";
        return;
    }

    cout<<"Escolha entre Pesquisar pelo ID ou pelo nome do contato: "<<endl;
    cout<<"1. ID"<<endl;
    cout<<"2. Nome"<<endl;
    cin>>choice;

    if(choice == 1) {
        int IDContato;
        bool found = false;
        cout<<"Digite o ID do contato: ";
        cin>>IDContato;
        for(int i = 0; i < sizeContatos; i++) {
            if(agenda.contatos[i].ID == IDContato) {
                cout<<"ID do contato: " << agenda.contatos[i].ID<<endl;
                cout<<"Nome do contato: " << agenda.contatos[i].nome<<endl;
                cout<<"CPF do contato: " << agenda.contatos[i].CPF<<endl;
                cout<<"Celular do contato: " << agenda.contatos[i].cel<<endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Contato não encontrado!" << endl;
        }
    }
    if(choice == 2) {
        string nomeContato;
        bool found = false;
        cout<<"Digite o nome do contato: ";
        cin>>nomeContato;
        for(int i = 0; i < sizeContatos; i++) {
            if(agenda.contatos[i].nome == nomeContato) {
                cout<<"ID do contato: " << agenda.contatos[i].ID<<endl;
                cout<<"Nome do contato: " << agenda.contatos[i].nome<<endl;
                cout<<"CPF do contato: " << agenda.contatos[i].CPF<<endl;
                cout<<"Celular do contato: " << agenda.contatos[i].cel<<endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Contato não encontrado!" << endl;
        }
    }
}

template <typename T, int MAX>
void getComercialContact(Agenda<ContatoComercial<T>, MAX> agenda) {
    int choice;
    int sizeContatos = agenda.quantidade;
    if(MAX <= sizeContatos) {
        cout<<"Sua lista de contatos está cheia!";
        return;
    }

    cout<<"Escolha entre Pesquisar pelo ID ou pelo nome da empresa: "<<endl;
    cout<<"1. ID"<<endl;
    cout<<"2. Nome"<<endl;
    cin>>choice;

    if(choice == 1) {
        int IDContato;
        bool found = false;
        cout<<"Digite o ID do contato: ";
        cin>>IDContato;
        for(int i = 0; i < sizeContatos; i++) {
            if(agenda.contatos[i].ID == IDContato) {
                cout<<"ID do contato: " << agenda.contatos[i].ID<<endl;
                cout<<"Nome do da empresa: " << agenda.contatos[i].empresa<<endl;
                cout<<"CNPJ do contato: " << agenda.contatos[i].CNPJ<<endl;
                cout<<"Telefone do contato: " << agenda.contatos[i].tel<<endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Contato não encontrado!" << endl;
        }
    }
    if(choice == 2) {
        string nomeContato;
        bool found = false;
        cout<<"Digite o nome do contato: ";
        cin>>nomeContato;
        for(int i = 0; i < sizeContatos; i++) {
            if(agenda.contatos[i].empresa == nomeContato) {
                cout<<"ID do contato: " << agenda.contatos[i].ID<<endl;
                cout<<"Nome do da empresa: " << agenda.contatos[i].empresa<<endl;
                cout<<"CNPJ do contato: " << agenda.contatos[i].CNPJ<<endl;
                cout<<"Telefone do contato: " << agenda.contatos[i].tel<<endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Contato não encontrado!" << endl;
        }
    }
}

template <typename T, int MAX>
void ordenarAgendaPessoal(Agenda<ContatoPessoal<T>, MAX> &agenda) {
  int sizeContatos = agenda.quantidade;
    for (int i = 0; i < sizeContatos - 1; i++) {
        for (int j = 0; j < sizeContatos - i - 1; j++) {
            if (agenda.contatos[j].nome > agenda.contatos[j + 1].nome) {
                // Troca
                ContatoPessoal<int> temp = agenda.contatos[j];
                agenda.contatos[j] = agenda.contatos[j + 1];
                agenda.contatos[j + 1] = temp;
            }
        }
    }
}

template <typename T, int MAX>
void ordenarAgendaComercial(Agenda<ContatoComercial<T>, MAX> &agenda) {
    int sizeContatos = agenda.quantidade;
    for (int i = 0; i < sizeContatos - 1; i++) {
        for (int j = 0; j < sizeContatos - i - 1; j++) {
            if (agenda.contatos[j].empresa > agenda.contatos[j + 1].empresa) {
                // Troca
                ContatoComercial<int> temp = agenda.contatos[j];
                agenda.contatos[j] = agenda.contatos[j + 1];
                agenda.contatos[j + 1] = temp;
            }
        }
    }
}

template <typename T, int MAX>
void getAllPersonalContacts(Agenda<ContatoPessoal<T>, MAX> agenda) {
  int sizeContatos = agenda.quantidade;
    for (int i = 0; i < sizeContatos; i++) {
        cout<<"--------------------------------------"<<endl;
        cout<<"ID do contato: " << agenda.contatos[i].ID<<endl;
        cout<<"Nome do contato: " << agenda.contatos[i].nome<<endl;
        cout<<"CPF do contato: " << agenda.contatos[i].CPF<<endl;
        cout<<"Celular do contato: " << agenda.contatos[i].cel<<endl;
        cout<<"--------------------------------------"<<endl;
    }
}

template <typename T, int MAX>
void getAllComercialContacts(Agenda<ContatoComercial<T>, MAX> agenda) {
    int sizeContatos = agenda.quantidade;
    for (int i = 0; i < sizeContatos; i++) {
        cout<<"--------------------------------------"<<endl;
        cout<<"ID do contato: " << agenda.contatos[i].ID<<endl;
        cout<<"Nome do da empresa: " << agenda.contatos[i].empresa<<endl;
        cout<<"CNPJ do contato: " << agenda.contatos[i].CNPJ<<endl;
        cout<<"Telefone do contato: " << agenda.contatos[i].tel<<endl;
        cout<<"--------------------------------------"<<endl;
    }
}

template void addPersonalContact<int, 999>(Agenda<ContatoPessoal<int>, 999>&);
template void addComercialContact<int, 999>(Agenda<ContatoComercial<int>, 999>&);
template void removePersonalContact<int, 999>(Agenda<ContatoPessoal<int>, 999> &);
template void removeComercialContact<int, 999>(Agenda<ContatoComercial<int>, 999> &);
template void getPersonalContact<int, 999>(Agenda<ContatoPessoal<int>, 999> );
template void getComercialContact<int, 999>(Agenda<ContatoComercial<int>, 999> );
template void ordenarAgendaPessoal<int, 999>(Agenda<ContatoPessoal<int>, 999> &);
template void ordenarAgendaComercial<int, 999>(Agenda<ContatoComercial<int>, 999> &);
template void getAllPersonalContacts<int, 999>(Agenda<ContatoPessoal<int>, 999> );
template void getAllComercialContacts<int, 999>(Agenda<ContatoComercial<int>, 999> );