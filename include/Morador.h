#ifndef MORADOR_H
#define MORADOR_H

#include "Pessoa.h"
using std::string

class Morador : public Pessoa  
{
private:
    string apartamento;
    char classes;
    bool inad; // Inadiplente
    bool abrir; // Abrir chamado
    
public:
    

};


#endif