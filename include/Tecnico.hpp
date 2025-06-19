#ifndef TECNICO_H
#define TECNICO_H

#include "Pessoa.hpp"
#include <string>
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
    void VisualizarChamadosDisponiveis() const;
    void AceitarChamado(int osID);
    void FecharChamado(int osID, string comentarioTecnico, double valor);
    void VisualizarMeusChamadosAtribuidos() const;
    void MudarStatusDisponibilidade (bool disponibilidade);
    double CalcularMediaAvaliacao(double nota) const;
};

#endif
