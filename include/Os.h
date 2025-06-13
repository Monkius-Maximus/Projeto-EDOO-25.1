#ifndef OS_H
#define OS_H

#include <string>
#include <iostream>

#include "Pessoa.h"
using std::string;

class Os : public Pessoa {

    private:
        string servico;
        double valor;
        int prioridade;
        int data_abertura;
        int data_fechamento;
        bool conclusao;
    
    public:
        Os (
            int contato,
            int registroId,
            std::string nome,
            std:: string servico,
            double valor,
            int prioridade,
            int data_abertura,
            int data_fechamento,
            bool conclusao
        )
            : Pessoa (
                contato,
                registroId,
                nome
            ),

            servico(servico),
            valor(valor),
            prioridade(prioridade),
            data_abertura(data_abertura),
            data_fechamento(data_fechamento),
            conclusao(conclusao) {}

    void exibirDadosOs();

};

#endif
