#ifndef TECNICO_H
#define TECNICO_H

#include "Os.h"
#include "Pessoa.h"

#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Tecnico : public Pessoa
{
    private:
        string especialidade;
        int totalAvaliacoes = 0;
        double nota;

    public:
        Tecnico(); // Construtor padrão que inicializa disponibilidade false e nota com 0.
        Tecnico(
            int idRegistro,
            const string &nome, 
            const string &email, 
            const string &especialidade, 
            double nota
        );

    void displayInfo() const override;
    
    // Métodos da classe:
    void VisualizarChamadosDisponiveis() const;
    void AceitarChamado(int osId);
    void FecharChamado();
    void VisualizarMeusChamadosAtribuidos() const;
    void atualizarNotaMedia();

    // Getters:
    string getEspecialidade() const;
    double getNota() const;

    // Setters:
    void setEspecialidade(const string &novaEspecialidade);
    void setNota(double novaNota);

};

#endif
