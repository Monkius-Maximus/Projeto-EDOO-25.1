#ifndef TECNICO_H
#define TECNICO_H

#include "Pessoa.h"
using std::string

class Tecnico : public Pessoa  
{
private:
    string especialidade;
    bool disponibilidade;
    string os; // Ordem de serviço
    int nota;
    bool fechar; // Fechar chamado
    string comentario;
    
public:


};


#endif