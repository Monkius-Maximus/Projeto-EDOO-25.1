#ifndef MORADOR_H
#define MORADOR_H

#include <string>
#include <iostream>

#include "Pessoa.h"
using std::string;

class Morador : public Pessoa {

    private:
        string apartamento;
        char classe_apto; // Classe do morador (A, B, C, D, E)
        bool inad; // Inadiplente
        bool tem_os_aberta; // Abrir chamado
        
    public:
        Morador (
            int contato,
            int registroId,
            std::string nome,
            std::string apartamento,
            char classe_apto,
            bool inad,
            bool tem_os_aberta
        );

    void exibirDadosMorador();

};

#endif
