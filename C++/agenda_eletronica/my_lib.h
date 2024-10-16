#ifndef MY_LIB
#define MY_LIB

#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct ContatoPessoal {
    T ID, CPF, cel;
    string nome;
};

template<typename T>
struct ContatoComercial {
    T ID, CNPJ, tel;
    string empresa;
};

template<typename T, int MAX>
struct Agenda {
    T* contatos = new T[MAX];
    int quantidade = 0;
};

template <typename T, int MAX>
void addPersonalContact(Agenda<ContatoPessoal<T>, MAX> &agenda);

template <typename T, int MAX>
void addComercialContact(Agenda<ContatoComercial<T>, MAX> &agenda);

template <typename T, int MAX>
void removePersonalContact(Agenda<ContatoPessoal<T>, MAX> &agenda);

template <typename T, int MAX>
void removeComercialContact(Agenda<ContatoComercial<T>, MAX> &agenda);

template <typename T, int MAX>
void getPersonalContact(Agenda<ContatoPessoal<T>, MAX> agenda);

template <typename T, int MAX>
void getComercialContact(Agenda<ContatoComercial<T>, MAX> agenda);

template <typename T, int MAX>
void ordenarAgendaPessoal(Agenda<ContatoPessoal<T>, MAX> &agenda);

template <typename T, int MAX>
void ordenarAgendaComercial(Agenda<ContatoComercial<T>, MAX> &agenda);

template <typename T, int MAX>
void getAllPersonalContacts(Agenda<ContatoPessoal<T>, MAX> agenda);

template <typename T, int MAX>
void getAllComercialContacts(Agenda<ContatoComercial<T>, MAX> agenda);

#endif