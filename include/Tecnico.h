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
    bool disponibilidade;
    double nota;

public:
    Tecnico(); // Construtor padrão que inicializa disponibilidade false e nota com 0.
    Tecnico(int id, const string &nome, const string &email, const string &especialidade, bool disponibilidade, double nota);

    // Métodos da classe:
    void VisualizarChamadosDisponiveis() const;
    void AceitarChamado(int osId);
    void FecharChamado(std::vector<Os>& listaOs);
    void VisualizarMeusChamadosAtribuidos() const;
    void MudarStatusDisponibilidade (bool disponibilidade);
    double CalcularMediaAvaliacao(double nota) const;

    // Getters:
    string getEspecialidade() const;
    bool getDisponibilidade() const;
    double getNota() const;

    // Setters:
    void setEspecialidade(const string &novaEspecialidade);
    void setDisponibilidade(bool status);
    void setNota(double novaNota);

};

#endif
