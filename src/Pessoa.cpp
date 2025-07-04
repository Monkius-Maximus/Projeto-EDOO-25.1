#include "Pessoa.h"
#include <iostream>
using namespace std;

// --- Construtor Padrão ---
Pessoa::Pessoa()
{ // Inicializa os atributos com valor padrão:
    idRegistro = 0;
    nome = "";
    email = "";
};

// --- Construtor com Parâmetros ---
Pessoa::Pessoa(const int idRegistro, const string &nome, const string &email)
{
    // Usar 'this->' para distinguir os parâmetros dos membros da classe quando eles têm o mesmo nome.
    this->idRegistro = idRegistro;
    this->nome = nome;
    this->email = email;
};

// --- Método displayInfo() ---
void Pessoa::displayInfo() const
{
    cout << "ID: " << idRegistro << endl;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
};
