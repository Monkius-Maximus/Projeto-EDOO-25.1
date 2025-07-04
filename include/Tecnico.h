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

// Declaração da Classe Técnico que Herda de Pessoa.
class Tecnico : public Pessoa
{
private: // Seção Privada:
    string especialidade; // Atributo: Especialidade do técnico.
    int totalAvaliacoes = 0; // Atributo: Contador do número total de avaliações que o técnico recebeu.
    double nota; // Atributo: Nota que o técnico recebe do morador.

public:
    Tecnico(); // Construtor padrão: Criar um objeto 'Tecnico' sem incializar com os atributos padrões.
    Tecnico( // Construtor com parâmetros.
        int idRegistro, // Parâmeto: ID registro (herda de Pessoa).
        const string &nome, // Parâmeto: Nome (herda de Pessoa).
        const string &email, // Parâmeto: email (herda de Pessoa).
        const string &especialidade, // Parâmeto: Especialidade.
        double nota); // Parâmeto: Nota.

    void displayInfo() const override; // Exibirá as informações específicas de um técnico.

    // --- Métodos da classe ---
    void VisualizarChamadosDisponiveis() const; // Permite ao técnico ver Oderns de Serviço que não estão concluidas e atribuidas a ele ou outro técnico.
    void AceitarChamado(int osId); // Permite ao técnico aceitar uma OS, tornando-se o responsável por essa OS atráves do ID da OS.
    void FecharChamado(); // Permite ao técnico marcar apenas uma OS de sua responsabilidade como concluída 
    void VisualizarMeusChamadosAtribuidos() const; // Permite ao técnico visualizar apenas as OS's que são suas responsabilidade.
    void atualizarNotaMedia(); // Calcula e atualiza a nota média do técncio com base nas avaliações dos moradores que ele aceitou a Ordem de Serviço.

    // --- Getters ---
    string getEspecialidade() const; // Retorna a Especialidade do técnico.
    double getNota() const; // Retorna a média das notas.

    // --- Setters ---
    void setEspecialidade(const string &novaEspecialidade); // Define uma nova especialidade do técnico.
    void setNota(double novaNota); // Define a nota média do técnico.
};

#endif
