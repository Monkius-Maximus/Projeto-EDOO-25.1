#ifndef MORADOR_H
#define MORADOR_H

#include "Os.h"
#include "Pessoa.h"
#include "Tecnico.h"

#include <vector> // Usar vector para lista de Os's
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Morador : public Pessoa // Classe Morador herdando publicamente de Pessoa
{
private: // Seção privada
    // Atributos da Classe Morador:
    string apartamento; 
    char classeApartamento;
    bool inadiplente;

public: // Interface Pública da Classe Morador:
    Morador(); // Construtor padrão: Usado para criar objetos Morador sem inicializar seus atributos especificos.
    Morador( //Construtor com parâmetos.
        int idRegistro, // Parâmetro: ID do Morador (herdado de Pessoa).
        const string &nome, // Parâmetro: Nome do Morador (herdado de Pessoa).
        const string &email, // Parâmetro: Email do Morador (herdado de Pessoa).
        const string &apartamento, // Parâmetro: Apartamento do Morador.
        char classeApartamento, // Parâmetro: Classe do Apartamento do Morador.
        bool inadiplente); // Parâmetro: Inadiplencia do Morador. 

    void displayInfo() const override; // Método: Exibe informações do Morador (como Pessoa, e adicionais de Morador).

    // --- Métodos da classe ---
    Os *AbrirChamado(std::vector<Os> &listaOs); // Permite ao Morador abrir uma nova OS.
                                                // Além de receber uma referência para um vetor de OS e retornar um ponteiro para a OS.
    void VisualizarMeusChamados(const std::vector<Os> &listaOs) const; // Permite ao Morador ver apenas as OS's que ele criou, recebe uma Referência para o vetor de OS.
    void deletarChamado(int osId, std::vector<Os> &listaOs); // Permite ao Morador deletar uma Os específica pelo ID, e recebe uma referência para o vetor de OS.
    void AvaliarServico(int osId, std::vector<Os> &listaOs, Tecnico &tecnico); // Permite ao Morador avaliar uma Os concluida, recebendo o ID da OS, o vetor de Os para atualização.
    bool VerificarInadiplencia() const; // Verificar se o morador está inadimplente, caso retorne `True`, então não poderá abrir uma OS.

    // --- Getters ---
    string getApartamento() const; // Retornar o número do Apartamento.
    char getClasseApartamento() const; //Retorna a Classe do Apartamento.
    bool getInadiplente() const; // Retorna o Status de inadimplência

    // --- Setters ---
    void setApartamento(string &novoApartamento); // Define o novo Aparatamento do Morador.
    void setClasseApartamento(char novaClasseAp); // Define a nova Classe do Apartamento.
    void setInadiplente(bool status); // Define o Status da inadimplência.
};

#endif
