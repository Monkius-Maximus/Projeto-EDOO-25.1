#include "Pessoa.h"
#include <iostream>
using namespace std;

Pessoa::Pessoa()
{
    id = 0;
    nome = "";
    email = "";
};

Pessoa::Pessoa(const int id, const string &nome, const string &email)
{
    this->id = id;
    this->nome = nome;
    this->email = email;

};

void Pessoa::display()
{
    cout << "ID: " << id << endl;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
};