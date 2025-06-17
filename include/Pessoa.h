#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa
{
private:
    int id;
    string nome;
    string email;

public:
    Pessoa(); // Construtor padrão
    Pessoa(int id, const string &nome, const string &email); // Construtor
    // Depois utilizar Getters e Setters
    void display() const;

};


#endif
