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
void addContact(Agenda<ContatoPessoal<T>, MAX> &agenda);

template <typename T, int MAX>
void addContact(Agenda<ContatoComercial<T>, MAX> &agenda);

template <typename T, int MAX>
void removeContact(Agenda<ContatoPessoal<T>, MAX> &agenda);

template <typename T, int MAX>
void removeContact(Agenda<ContatoComercial<T>, MAX> &agenda);

template <typename T, int MAX>
void getContact(Agenda<ContatoPessoal<T>, MAX> agenda);

template <typename T, int MAX>
void getContact(Agenda<ContatoComercial<T>, MAX> agenda);

template <typename T, int MAX>
void ordenarAgenda(Agenda<ContatoPessoal<T>, MAX> &agenda);

template <typename T, int MAX>
void ordenarAgenda(Agenda<ContatoComercial<T>, MAX> &agenda);

template <typename T, int MAX>
void getAllContacts(Agenda<ContatoPessoal<T>, MAX> agenda);

template <typename T, int MAX>
void getAllContacts(Agenda<ContatoComercial<T>, MAX> agenda);

#endif