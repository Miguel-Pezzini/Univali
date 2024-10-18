#include <iostream>
#include <windows.h> 
#include "my_lib.h"

void apresentarMenu() {
    cout<<"-------------------------------"<<endl;
    cout<<"O que você gostaria de fazer?"<<endl;
    cout<<"1. Inserir um novo contato na agenda"<<endl;
    cout<<"2. Remover contato na agenda"<<endl;
    cout<<"3. Pesquisar um contato na agenda"<<endl;
    cout<<"4. Ordenar a agenda por nome"<<endl;
    cout<<"5. Mostrar todos os contatos da agenda"<<endl;
    cout<<"6. SAIR"<<endl;
    cout<<"-------------------------------"<<endl;
}

void agendaPessoalOuComercial() {
    (void)system("cls");
    cout<<"Qual agenda você gostaria de realizar a operação?"<<endl;
    cout<<"1. Agenda Pessoal"<<endl;
    cout<<"2. Agenda Comercial"<<endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const int MAX_AGENDA_PESSOAL = 999;
    const int MAX_AGENDA_COMERCIAL = 999;

    int opt = 0;

    bool isRunning = true;

    Agenda <ContatoPessoal<int>, MAX_AGENDA_PESSOAL> agendaPessoal;
    Agenda <ContatoComercial<int>, MAX_AGENDA_COMERCIAL> agendaComercial;

    while(isRunning) {
        apresentarMenu();
        cin >> opt;
        switch(opt) {
            case 1:
                agendaPessoalOuComercial();
                cin >> opt;
                if(opt == 1) addContact(agendaPessoal);
                if(opt == 2) addContact(agendaComercial);
            break;
            case 2:
                agendaPessoalOuComercial();
                cin >> opt;
                if(opt == 1) removeContact(agendaPessoal);
                if(opt == 2) removeContact(agendaComercial);
            break;
            case 3:
                agendaPessoalOuComercial();
                cin >> opt;
                if(opt == 1) getContact(agendaPessoal);
                if(opt == 2) getContact(agendaComercial);
            break;
            case 4:
                agendaPessoalOuComercial();
                cin >> opt;
                if(opt == 1) ordenarAgenda(agendaPessoal);
                if(opt == 2) ordenarAgenda(agendaComercial);
            break;
            case 5:
                agendaPessoalOuComercial();
                cin >> opt;
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
