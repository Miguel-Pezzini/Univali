#include <iostream>
#include <windows.h> 
#include <string> 
#include "my_lib.h"

template <typename T, int MAX>
bool insere(Agenda<T, MAX>& agenda, T contato) {
    if (agenda.quantidade < MAX) { 
        agenda.contatos[agenda.quantidade] = contato;
        agenda.quantidade++;
        return true;
    }
    return false;
}

template <typename T, int MAX>
void addContact(Agenda<ContatoPessoal<T>, MAX> &agenda) {
    ContatoPessoal<T> contato;
    int sizeContatos = agenda.quantidade;
    if(MAX <= sizeContatos) {
        cout<<"Sua lista de contatos está cheia!";
        return;
    }
    cout<<"Informe o ID do contato: ";
    cin>>contato.ID;
    cout<<"Informe o CPF do contato: ";
    cin>>contato.CPF;
    cout<<"Informe o Celular do contato: ";
    cin>>contato.cel;
    cout<<"Informe o nome do contato: ";
    cin>>contato.nome;

    if(insere(agenda, contato)) {
        cout<<"Contato inserido com sucesso";
    } else {
        cout<<"Agenda está cheia";
    }
}

template <typename T, int MAX>
void addContact(Agenda<ContatoComercial<T>, MAX> &agenda) {
    ContatoComercial<T> contato;
    int sizeContatos = agenda.quantidade;
    if(MAX <= sizeContatos) {
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

    if(insere(agenda, contato)) {
        cout<<"Contato inserido com sucesso";
    } else {
        cout<<"Agenda está cheia";
    }
}

template <typename T, int MAX>
void removeContact(Agenda<ContatoPessoal<T>, MAX> &agenda) {
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
void removeContact(Agenda<ContatoComercial<T>, MAX> &agenda) {
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
void getContact(Agenda<ContatoPessoal<T>, MAX>const &agenda) {
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
        (void)system("cls");
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
        (void)system("cls");
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
void getContact(Agenda<ContatoComercial<T>, MAX>const &agenda) {
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
        (void)system("cls");
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
        (void)system("cls");
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

template <typename T>
bool operator > (ContatoPessoal<T> contatoUm, ContatoPessoal<T> contatoDois) {
  if(contatoUm.nome > contatoDois.nome) {
    return true;
  } 

  return false;
}

template <typename T, int MAX>
void ordenarAgenda(Agenda<ContatoPessoal<T>, MAX> &agenda) {
  int sizeContatos = agenda.quantidade;
    for (int i = 0; i < sizeContatos - 1; i++) {
        for (int j = 0; j < sizeContatos - i - 1; j++) {
            if (agenda.contatos[j] > agenda.contatos[j + 1]) {
                // Troca
                ContatoPessoal<int> temp = agenda.contatos[j];
                agenda.contatos[j] = agenda.contatos[j + 1];
                agenda.contatos[j + 1] = temp;
            }
        }
    }
}

template <typename T>
bool operator > (ContatoComercial<T> contatoUm, ContatoComercial<T> contatoDois) {
  if(contatoUm.empresa > contatoDois.empresa) {
    return true;
  } 

  return false;
}

template <typename T, int MAX>
void ordenarAgenda(Agenda<ContatoComercial<T>, MAX> &agenda) {
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
void getAllContacts(Agenda<ContatoPessoal<T>, MAX>const  &agenda) {
  int sizeContatos = agenda.quantidade;
  (void)system("cls");
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
void getAllContacts(Agenda<ContatoComercial<T>, MAX>const  &agenda) {
    int sizeContatos = agenda.quantidade;
    (void)system("cls");
    for (int i = 0; i < sizeContatos; i++) {
        cout<<"--------------------------------------"<<endl;
        cout<<"ID do contato: " << agenda.contatos[i].ID<<endl;
        cout<<"Nome do da empresa: " << agenda.contatos[i].empresa<<endl;
        cout<<"CNPJ do contato: " << agenda.contatos[i].CNPJ<<endl;
        cout<<"Telefone do contato: " << agenda.contatos[i].tel<<endl;
        cout<<"--------------------------------------"<<endl;
    }
}

void agendaPessoalOuComercial() {
    (void)system("cls");
    cout<<"Qual agenda você gostaria de realizar a operação?"<<endl;
    cout<<"1. Agenda Pessoal"<<endl;
    cout<<"2. Agenda Comercial"<<endl;
    cout<<"Digite sua opção: ";
}

int main() {
    (void)system("cls");
    SetConsoleOutputCP(CP_UTF8);
    const int MAX_AGENDA_PESSOAL = 999;
    const int MAX_AGENDA_COMERCIAL = 999;

    int opt = 0;

    bool isRunning = true;

    Agenda <ContatoPessoal<int>, MAX_AGENDA_PESSOAL> agendaPessoal;
    Agenda <ContatoComercial<int>, MAX_AGENDA_COMERCIAL> agendaComercial;

    while(isRunning) {
        cout<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"O que você gostaria de fazer?"<<endl;
        cout<<"1. Inserir um novo contato na agenda"<<endl;
        cout<<"2. Remover contato na agenda"<<endl;
        cout<<"3. Pesquisar um contato na agenda"<<endl;
        cout<<"4. Ordenar a agenda por nome"<<endl;
        cout<<"5. Mostrar todos os contatos da agenda"<<endl;
        cout<<"6. SAIR"<<endl;
        cout<<"-------------------------------"<<endl;
        cin >> opt;
        switch(opt) {
            case 1:
                agendaPessoalOuComercial();
                cin >> opt;
                (void)system("cls");
                if(opt == 1) addContact(agendaPessoal);
                if(opt == 2) addContact(agendaComercial);
            break;
            case 2:
                agendaPessoalOuComercial();
                cin >> opt;
                (void)system("cls");
                if(opt == 1) removeContact(agendaPessoal);
                if(opt == 2) removeContact(agendaComercial);
            break;
            case 3:
                agendaPessoalOuComercial();
                cin >> opt;
                (void)system("cls");
                if(opt == 1) getContact(agendaPessoal);
                if(opt == 2) getContact(agendaComercial);
            break;
            case 4:
                agendaPessoalOuComercial();
                cin >> opt;
                (void)system("cls");
                if(opt == 1) ordenarAgenda(agendaPessoal);
                if(opt == 2) ordenarAgenda(agendaComercial);
            break;
            case 5:
                agendaPessoalOuComercial();
                cin >> opt;
                (void)system("cls");
                if(opt == 1) getAllContacts(agendaPessoal);
                if(opt == 2) getAllContacts(agendaComercial);
            break;
            case 6:
                isRunning = false;
            break;
        }
    }

    delete[] agendaPessoal.contatos;
    delete[] agendaComercial.contatos;

    return 0;
}
