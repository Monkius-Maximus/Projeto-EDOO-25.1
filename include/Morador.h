#ifndef MORADOR_H
#define MORADOR_H

#include "Pessoa.h"
#include <string>
using std::string;

class Morador : public Pessoa
{
private:
    string apartamento;
    char classeApartamento;
    bool inadiplente;

public:
    Morador (int id, const string &nome, const string &email, const string &apartamento, char classeApartamento, bool inadiplente);

};

#endif
