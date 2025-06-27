#ifndef MORADOR_H
#define MORADOR_H

#include "Os.h"
#include "Pessoa.h"

#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Morador : public Pessoa
{
    private:
        string apartamento;
        char classeApartamento;
        bool inadiplente;
        
    public:
        Morador(); // Construtor padrão
        Morador (
            int id,
            const string &nome,
            const string &email,
            const string &apartamento,
            char classeApartamento,
            bool inadiplente
        );
        
    // Métodos da classe:
    Os* AbrirChamado(std::vector<Os>& listaOs);
    void VisualizarMeusChamados() const;
    void deletarChamado(int osId);
    void AvaliarServico(int osId);
    bool VerificarInadiplencia() const;

    // Getters:
    string getApartamento() const;
    char getClasseApartamento() const;
    bool getInadiplente() const;

    // Setters:
    void setApartamento(string &novoApartamento);
    void setClasseApartamento(char novaClasseAp);
    void setInadiplente(bool status);
};

#endif
