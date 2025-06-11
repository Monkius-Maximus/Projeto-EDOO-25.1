#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa {

    private:
        int registroId;
        string nome;
        int contato;

    public:
        Pessoa (
            int contato,
            int registroId,
            std::string nome
        );
        
    void exibirDadosPessoa();

};

#endif
