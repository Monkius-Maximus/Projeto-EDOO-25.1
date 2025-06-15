#include "../include/Tecnico.h"
#include <iostream>
using namespace std;

Tecnico::Tecnico(const int id, const string &nome, const string &email, const string &especialidade)
    : Pessoa(id, nome, email)
{
    this->especialidade = especialidade;
    this->disponibilidade = false;
    this->nota = 0.0;
};

Tecnico::Tecnico(int id, const string &nome, const string &email, const string &especialidade, bool disponibilidade, double nota)
    :Pessoa(id, nome, email)
{
    this->especialidade = especialidade;
    this->disponibilidade = disponibilidade; 
    this->nota = nota; 
};
