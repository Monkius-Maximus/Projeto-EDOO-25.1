#ifndef TECNICO_H
#define TECNICO_H

#include <string>
#include <iostream>

#include "Pessoa.h"
using std::string;

class Tecnico : public Pessoa {

    private:
        string especialidade;
        bool disponibilidade;
        string os; // Ordem de serviço
        double nota;
        bool os_fechada; // Fechar chamado
        string comentario;
    
    public:
        Tecnico (
            int contato,
            int registroId,
            std::string nome,
            std:: string especialidade,
            bool disponibilidade,
            std::string os,
            double nota,
            bool os_fechada,
            string comentario
        )
            : Pessoa (
                contato,
                registroId,
                nome
            ),

            especialidade(especialidade),
            disponibilidade(disponibilidade),
            os(os),
            nota(nota),
            os_fechada(os_fechada),
            comentario(comentario) {}

    void exibirDadosTecnico();

};

#endif
