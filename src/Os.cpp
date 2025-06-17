#include "Os.h"
#include <iostream>
using namespace std;

Os::Os()
{   
    osID = 0;
    categoria = "Vazio";
    servico = "Vazio";
    valor = 0.0;
    prioridade = 0;
    comentario = "N/A";
    dataAbertura = "Vazio";
    dataFechamento = "Vazio";
    conclusao = false;
};

Os::Os(int osID, const string &categoria, const string &servico, const double &valor, int prioridade, const string &comentario, const string &dataAbertura, const string &dataFechamento, bool conclusao)
{   
    this->osID = osID;
    this->categoria = categoria;
    this->servico = servico;
    this->valor = valor;
    this->prioridade = prioridade;
    this->comentario = comentario;
    this->dataAbertura = dataAbertura;
    this->dataFechamento = dataFechamento;
    this->conclusao = conclusao;

};
