#include "../include/Tecnico.hpp"
#include <iostream>
using namespace std;

Tecnico::Tecnico()
    :Pessoa()
{
    especialidade = "N/A";
    disponibilidade = false;
    nota = 0.0;
};

Tecnico::Tecnico(int id, const string &nome, const string &email, const string &especialidade, bool disponibilidade, double nota)
    :Pessoa(id, nome, email)
{
    this->especialidade = especialidade;
    this->disponibilidade = disponibilidade; 
    this->nota = nota; 
};
