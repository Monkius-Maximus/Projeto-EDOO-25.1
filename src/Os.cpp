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
    comentarioTecnico = "Comentário do Técnico";
    valor = 0.00;
    dataFechamento = "Data de Fechamento";
    conclusao = false;
    idMoradorCriador = 0;
    nomeMoradorCriador = "Desconhecido";

    // Verificar se está funcional
    comentarioMorador = "Comentário do Morador";
    notaAvaliacao = 0;
    avaliada = false;
    //

    idTecnicoResponsavel = 0;
    nomeTecnicoResponsavel = "N/A";
    atribuida = false;
};

Os::Os
(
    int numeroOs,
    const string &dataAbertura,
    const string &categoria,
    const string &servico,
    int prioridade,
    const string &comentarioTecnicoPara,
    double valor,
    const string &dataFechamento,
    bool conclusao,
    int idMoradorCriador,
    const string &nomeMoradorCriador,

    // Verificar se está funcional
    const string &comentarioMoradorPara,
    int notaAvaliacao,
    bool avaliada,
    //

    int idTecnicoResponsavel_,
    const string &nomeTecnicoResponsavel_,
    bool atribuida_
)

{
    this->numeroOs = numeroOs;
    this->dataAbertura = dataAbertura;
    this->categoria = categoria;
    this->servico = servico;
    this->prioridade = prioridade;
    this->comentarioTecnico = comentarioTecnicoPara;
    this->valor = valor;
    this->dataFechamento = dataFechamento;
    this->conclusao = conclusao;
    this->idMoradorCriador = idMoradorCriador;
    this->nomeMoradorCriador = nomeMoradorCriador;

    // Verificar se está funcional
    this->comentarioMorador = comentarioMoradorPara;
    this->notaAvaliacao = notaAvaliacao;
    this->avaliada = avaliada;
    //

    this->idTecnicoResponsavel = idTecnicoResponsavel_;
    this->nomeTecnicoResponsavel = nomeTecnicoResponsavel_;
    this->atribuida = atribuida_;

};

// Getters
int Os::getNumeroOs() const { return numeroOs; }
string Os::getDataAbertura() const { return dataAbertura; }
string Os::getCategoria() const { return categoria; }
string Os::getServico() const { return servico; }
int Os::getPrioridade() const { return prioridade; }
string Os::getComentarioTecnico() const { return comentarioTecnico; }
double Os::getValor() const { return valor; }
string Os::getDataFechamento() const { return dataFechamento; }
bool Os::isConcluida() const { return conclusao; }
int Os::getIdMoradorCriador() const { return idMoradorCriador; }
string Os::getNomeMoradorCriador() const { return nomeMoradorCriador; }

// Verificar se está funcional
string Os::getComentarioMorador() const { return comentarioMorador; }
int Os::getNotaAvaliacao() const { return notaAvaliacao; }
bool Os::isAvaliada() const { return avaliada; }
//

int Os::getIdTecnicoResponsavel() const { return idTecnicoResponsavel; }
string Os::getNomeTecnicoResponsavel() const { return nomeTecnicoResponsavel; }
bool Os::isAtribuida() const { return atribuida; }

// Setters
void Os::setValor(double valor) {
    this->valor = valor;
}

void Os::setComentarioTecnico(const string &comentarioTecnicoPara) {
    this->comentarioTecnico = comentarioTecnicoPara;
}

void Os::setConclusao(bool status) {
    conclusao = status;
}

void Os::setDataFechamento(const string &data) {
    dataFechamento = data;
}

void Os::setAvaliacao(const string &comentarioMoradorPara, int nota){
    this->comentarioMorador = comentarioMoradorPara;
    this->notaAvaliacao = nota;
    this->avaliada = true;
}

void Os::setAvaliada(bool avaliada){
    this->avaliada = avaliada;
}

void Os::setAtribuicao(int idTecnico, const string& nomeTecnico){
    this->idTecnicoResponsavel = idTecnico;
    this->nomeTecnicoResponsavel = nomeTecnico;
    this->atribuida = true;
}

void Os::setAtribuida(bool status){
    this->atribuida = status;
}

// Exibir Detalhes
void Os::exibirDetalhesTecnico() const {
    cout << fixed << setprecision(2);
    if(atribuida){
        cout << "Técnico Responsável (ID): " << idTecnicoResponsavel << endl;
        cout << "Técnico Responsável (Nome): " << nomeTecnicoResponsavel << endl;
    }
    
    else {
        cout << "Status de Atribuição: Não atribuída." << endl;
    }

    cout << "Número da OS: " << numeroOs << endl;
    cout << "Data de Abertura: " << dataAbertura << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Descrição do Serviço: " << servico << endl;
    cout << "Prioridade: " << prioridade << endl;
    cout << "Comentário do Técnico: " << comentarioTecnico << endl;
    cout << "Valor do Serviço: R$ " << valor << endl;
    cout << "Data de Fechamento: " << dataFechamento << endl;
    cout << "Concluída: " << (conclusao ? "Sim" : "Não") << endl;
    if(avaliada){
        cout << "Avaliação do Morador: " << notaAvaliacao << "/5 - Comentário: " << comentarioMorador << endl;
    }
    
    else {
        cout << "Serviço ainda não avaliado pelo morador." << endl;
    }

}

void Os::exibiriDetalhesMorador() const {
    cout << fixed << setprecision(2);
    cout << "ID do Morador: " << idMoradorCriador << endl;
    cout << "Nome do Morador: " << nomeMoradorCriador << endl;
    cout << "Numero da OS: " << numeroOs << endl;
    cout << "Data de Abertura: " << dataAbertura << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Descrição do Serviço: " << servico << endl;
    cout << "Prioridade: " << prioridade << endl;
    if(avaliada){
        cout << "Sua Avaliação: " << notaAvaliacao << "/5" << endl; 
        if(!comentarioMorador.empty()){
            cout << "Comentário: " << comentarioMorador << endl;
        }
        
        else {
            cout << "Comentário: (Não informado)" << endl;
            
        }
        cout << "Status da Avaliação: Concluído!" << endl;
    }
    
    else if (isConcluida()){
        cout << "Sua Avaliação: N/A" << endl;
        cout << "Comentário: N/A" << endl;
        cout << "Status da Avaliação: Serviço concluído, aguardando sua avaliação." << endl;
    }
    
    else {
        cout << "Sua Avaliação: N/A" << endl; 
        cout << "Comentário: N/A" << endl; 
        cout << "Status da Avaliação: Serviço não concluído." << endl;
    }

}
