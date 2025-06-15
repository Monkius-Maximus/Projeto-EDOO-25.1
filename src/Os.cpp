#include "Os.h"
#include <iostream>
using namespace std;

Os::Os()
{
    categoria = "Vazio";
    servico = "Vazio";
    valor = 0;
    prioridade = 0;
    comentario = "Vazio";
    dataAbertura = "Vazio";
    dataFechamento = "Vazio";
    conclusao = "Vazio";
};

Os::Os(const string &categoria, const string &servico, const double &valor, int prioridade, const string &comentario, const string &dataAbertura, const string &dataFechamento, bool conclusao)
{
    this->categoria = categoria;
    this->servico = servico;
    this->valor = valor;
    this->prioridade = prioridade;
    this->comentario = comentario;
    this->dataAbertura = dataAbertura;
    this->dataFechamento = dataFechamento;
    this->conclusao = conclusao;

};
