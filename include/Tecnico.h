#ifndef TECNICO_H
#define TECNICO_H

#include "Pessoa.h"
#include <string>
using std::string;

class Tecnico : public Pessoa
{
private:
    string especialidade;
    bool disponibilidade;
    double nota;

public:
    Tecnico(int id, const string &nome, const string &email, const string &especialidade); // Construtor padrão que inicializa disponibilidade false e nota com 0.
    Tecnico(int id, const string &nome, const string &email, const string &especialidade, bool disponibilidade, double nota);


};

#endif
