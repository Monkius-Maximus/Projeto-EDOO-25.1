#ifndef MORADOR_H
#define MORADOR_H

#include "Pessoa.h"
#include "Os.h"
#include <string>
using std::string;

class Morador : public Pessoa
{
private:
    string apartamento;
    char classeApartamento;
    bool inadiplente;

public:
    Morador(); // Construtor padrão
    Morador (int id, const string &nome, const string &email, const string &apartamento, char classeApartamento, bool inadiplente);

    // Métodos da classe:
    Os* AbrirChamado(string categoria, string servico, string comentario, int prioridade);
    void VisualizarMeusChamados() const;
    void CancelarChamado(int osId);
    void AvaliarServico(int osId, int comentario);
    bool VerificarInadiplencia() const;

    // Getters:
    string getApartamento() const {return apartamento;}
    char getClasseApartamento() const {return classeApartamento;}
    bool getInadiplente() const {return inadiplente;}

    // Setters:
    void setApartamento(string &novoApartamento){
        if(!novoApartamento.empty()){
            apartamento = novoApartamento;
        }else {
            cout << "Erro: Apartamento não pode ser vázio!" << endl;
        }
    }

    void setClasseApartamento(char novaClasseAp){
        if(novaClasseAp == 'A' || novaClasseAp == 'B' || novaClasseAp == 'C' || novaClasseAp == 'D'){
            classeApartamento = novaClasseAp;
        }else {
            cout << "Erro: Classe de apartamento inválida!" << endl;
        }
    }

    void setInadiplente(bool status) {
        inadiplente = status;
    }
};

#endif
