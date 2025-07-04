#ifndef OS_H
#define OS_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Classe Os
class Os
{

private: // Seção Privada:
    // Morador insere:
    int numeroOs; // Deverá ser automaticamente incrementado
    string dataAbertura;
    string categoria;          // Ex: "Elétrica", "Hidráulica", "Estrutural"
    string servico;            // Descrição do serviço solicitado
    int prioridade;            // Ex: 1 (Baixa), 2 (Média), 3 (Alta), 4 (Urgente), 5 (Emergencial)
    int idMoradorCriador;      // ID do morador que irá criar o chamado;
    string nomeMoradorCriador; // Nome do morador que irá criar o chamado;

    string comentarioMorador; // Comentário do morador sobre a conclusão do serviço
    int notaAvaliacao;        // Nota dada pelo morador para o serviço
    bool avaliada;            // Indica se a OS ja foi avaliada pelo morador

    // Técnico insere:
    string comentarioTecnico; // Comentário do técnico sobre a situação da OS
    double valor;             // Valor estimado do serviço
    string dataFechamento;    // Data de Fechamento da Orem de Serviço
    bool conclusao;                // Status de conclusão da OS (true/false)
    int idTecnicoResponsavel;      // ID do técnico que aceitou a OS
    string nomeTecnicoResponsavel; // Nome do técnico que aceitou a OS
    bool atribuida;                // Indicar se a OS foi atribuida a um tecnico

public: // Interface Pública:
    Os(); // Construtor Padrão: Cria objetos Os sem incializar com seus atributos padrão.

    Os(
        int NumeroOs, // Parâmetro: Número da Os.
        const string &dataAbertura, // Parâmetro: Data de Abertura da OS.
        const string &categoria, // Parâmetro: Categoria da Os.
        const string &servico, // Parâmetro: Descrição do Serviço da Os.
        int prioridade, // Parâmetro: Nível de Prioridade.
        const string &comentarioTecnicoPara, // Parâmetro: Comentário do técnico (para morador).
        double valor, // Parâmetro: Valor do Serviço.
        const string &dataFechamento, // Parâmetro: Data de Fechamento da Os.
        bool conclusao, // Parâmetro: Status de Conclusão;
        int idMoradorCriador, // Parâmetro: ID do morador que criou a OS.
        const string &nomeMoradorCriador, // Parâmetro: Nome do Morador que criou a Os.
        const string &comentarioMoradorPara, // Parâmetro: Comentário do morador (para o técnico).
        int notaAvaliacao, // Parâmetro: Nota de avaliação. 
        bool avaliada, // Parâmetro: Status de avaliação.
        int idTecnicoResponsavel, // Parâmetro: ID do técnico responsavel pela OS.
        const string &nomeTecnicoResponsavel, // Parâmetro: Nome do técnico responsável pela OS.
        bool atribuida); // Parâmetro: Status de Atribuição para técnico.

    // --- Getters ---
    int getNumeroOs() const; // Retorna o Número da Os.
    string getDataAbertura() const; // Retorna a Data de abertura.
    string getCategoria() const; // Retorna Categoria da Os.
    string getServico() const; // Retorna a Descrição do serviço.
    int getPrioridade() const; // Retorna a Prioridade do serviço.
    string getComentarioTecnico() const; // Retorna o comentário do Técnico.
    double getValor() const; // Retorna o valor.
    string getDataFechamento() const; // Retorna da Data de Fechamento.
    bool isConcluida() const; // Retorna se a OS está concluida.
    int getIdMoradorCriador() const; // Retorna o ID do morador que criou a Os.
    string getNomeMoradorCriador() const; // Retorna o Nome do morador que criou a Os.
    string getComentarioMorador() const; // Retorna o comentário do morador.
    int getNotaAvaliacao() const; // Retorna a nota de avaliação.
    bool isAvaliada() const; // Retorna se a OS foi avaliada.
    int getIdTecnicoResponsavel() const; // Retorna ID do técnico responsável pela OS.
    string getNomeTecnicoResponsavel() const; // Retorna Nome do técnico responsável pela OS.
    bool isAtribuida() const; // Retorna se a OS está atribuida a um técnico.

    // --- Setters ---
    void setComentarioTecnico(const string &comentarioTecnicoPara); // Define o comentário do técnico.
    void setValor(double valor); // Define o valor do serviço.
    void setDataFechamento(const string &data); // Define a data de fechamento.
    void setConclusao(bool status); // Define o status da conclusão.

    void setAvaliacao(const string &comentarioMoradorPara, int nota); // Define o comentário e a nota de avaliação do Morador.
    void setAvaliada(bool avaliada); // Define o status da Avaliação.
    void setAtribuicao(int idTecnico, const string &nomeTecnico); // Define o técnico responsável e marca como atribuída.
    void setAtribuida(bool status); // Define o status da Atribuição.

    // --- Método para exibir detalhes da OS ---
    void exibirDetalhesTecnico() const; // Exibe os detalhes da OS focando em informações relevantes apenas para o técnico.
    void exibiriDetalhesMorador() const; // Exibe os detalhes da OS focando em informações relevantes apenas para o morador.
};

#endif
