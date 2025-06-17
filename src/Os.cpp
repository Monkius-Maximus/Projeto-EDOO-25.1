#include "../include/Os.h"
#include <iostream>
#include <iomanip>

using namespace std;

Os::Os()
{
    numeroOs = 0;
    dataAbertura = "Data de Abertura";
    categoria = "Categoria do Serviço";
    servico = "Descrição do Serviço";
    prioridade = 0;

    comentario = "Comentário do Técnico";
    valor = 0;
    dataFechamento = "Data de Fechamento";
    conclusao = "Está Concluída?";
};

Os::Os
(
    int numeroOs,
    const string &dataAbertura,
    const string &categoria,
    const string &servico,
    int prioridade,

    const string &comentario,
    double valor,
    const string &dataFechamento,
    bool conclusao
)

{
    this->numeroOs = numeroOs;
    this->dataAbertura = dataAbertura;
    this->categoria = categoria;
    this->servico = servico;
    this->prioridade = prioridade;

    this->comentario = comentario;
    this->valor = valor;
    this->dataFechamento = dataFechamento;
    this->conclusao = conclusao;

};

// Getters
int Os::getNumeroOs() const { return numeroOs; }
string Os::getDataAbertura() const { return dataAbertura; }
string Os::getCategoria() const { return categoria; }
string Os::getServico() const { return servico; }
int Os::getPrioridade() const { return prioridade; }

string Os::getComentario() const { return comentario; }
double Os::getValor() const { return valor; }
string Os::getDataFechamento() const { return dataFechamento; }
bool Os::isConcluida() const { return conclusao; }

// Setters
void Os::setValor(double valor) {
    this->valor = valor;
}

void Os::setComentario(const string &comentario) {
    this->comentario = comentario;
}

void Os::setConclusao(bool status) {
    conclusao = status;
}

void Os::setDataFechamento(const string &data) {
    dataFechamento = data;
}

// Exibir Detalhes
void Os::exibirDetalhes() const {
    cout << fixed << setprecision(2);
    cout << "Número da OS: " << numeroOs << endl;
    cout << "Data de Abertura: " << dataAbertura << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Descrição do Serviço: " << servico << endl;
    cout << "Prioridade: " << prioridade << endl;

    cout << "Comentário do Técnico: " << comentario << endl;
    cout << "Valor do Serviço: R$ " << valor << endl;
    cout << "Data de Fechamento: " << dataFechamento << endl;
    cout << "Concluída: " << (conclusao ? "Sim" : "Não") << endl;
}
