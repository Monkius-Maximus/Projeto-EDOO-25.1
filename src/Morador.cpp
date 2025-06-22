#include "../include/Morador.h"
#include "Morador.h"
#include <iostream>
using namespace std;

Morador::Morador()
    :Pessoa()
{
    apartamento = "N/A";
    classeApartamento = 'N/A';
    inadiplente = false;
};

Morador::Morador(int id, const string &nome, const string &email, const string &apartamento, char classeApartamento, bool inadiplente)
    :Pessoa(id, nome, email)
{
    this->apartamento = apartamento;
    this-> classeApartamento = classeApartamento;
    this->inadiplente = inadiplente;

};

Os* Morador::AbrirChamado(string categoria, string servico, string comentario, int prioridade){
    if(VerificarInadiplencia()){
        cout << "Morador " << getNome() << " está inadiplente e não poderá abrir chamados.";
    }
    
}

