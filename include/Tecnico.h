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
    void AceitarChamado(int osID);
    void FecharChamado(std::vector<Os>& listaOs);
    void VisualizarMeusChamadosAtribuidos() const;
    void MudarStatusDisponibilidade (bool disponibilidade);
    double CalcularMediaAvaliacao(double nota) const;

    // Getters:
    string getEspecialidade() const {return especialidade;}
    bool getDisponibilidade() const {return disponibilidade;}
    double getNota() const {return nota;}

    // Setters:
    void setEspecialidade(const string &novaEspecialidade){
        if(!novaEspecialidade.empty()){
            especialidade = novaEspecialidade;
        } else {
            cout << "Erro: Especialidade não pode ser vázia" << endl;
        }
    }

    void setDisponibilidade(bool status){
        disponibilidade = status;
    }

    void setNota(double novaNota){
        if(novaNota >= 0.0 && novaNota <= 5.0){
            nota = novaNota;
        }else{
            cout << "Erro: Nota inválida. A nota deve estar entre 0.0 e 5.0" << endl;
        }
    }

};

#endif
