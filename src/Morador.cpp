#include "../include/Morador.h"
#include <iostream>
using namespace std;

Morador::Morador()
    :Pessoa()
{
    apartamento = "N/A";
    classeApartamento = 'N/A';
    inadiplente = false;
};


Morador::Morador(int id, const string &nome, const string &email, const string &apartamento, char classeApartamento, bool inadiplente)
    :Pessoa(id, nome, email)
{
    this->apartamento = apartamento;
    this-> classeApartamento = classeApartamento;
    this->inadiplente = inadiplente;

};
