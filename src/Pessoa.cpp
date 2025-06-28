#include "Pessoa.h"
#include <iostream>
using namespace std;

Pessoa::Pessoa()
{
    idRegistro = 0;
    nome = "";
    email = "";
};

Pessoa::Pessoa(const int idRegistro, const string &nome, const string &email)
{
    this->idRegistro = idRegistro;
    this->nome = nome;
    this->email = email;

};

void Pessoa::displayInfo() const
{
    cout << "ID: " << idRegistro << endl;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
};
