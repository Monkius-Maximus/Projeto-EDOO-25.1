#ifndef OS_H
#define OS_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Os
{

    private:
        // Morador insere
        int numeroOs; // Deverá ser automaticamente incrementado
        string dataAbertura;
        string categoria; // Ex: "Elétrica", "Hidráulica", "Estrutural"
        string servico; // Descrição do serviço solicitado
        int prioridade; // Ex: 1 (Baixa), 2 (Média), 3 (Alta), 4 (Urgente), 5 (Emergencial)
        int idMoradorCriador; // ID do morador que irá criar o chamado;
        string nomeMoradorCriador; // Nome do morador que irá criar o chamado;

        string comentarioMorador; // Comentário do morador sobre a conclusão do serviço
        int notaAvaliacao;  // Nota dada pelo morador para o serviço
        bool avaliada; // Indica se a OS ja foi avaliada pelo morador

        // Técnico insere
        string comentarioTecnico; // Comentário do técnico sobre a situação da OS
        double valor; // Valor estimado do serviço
        string dataFechamento;
        bool conclusao; // Status de conclusão da OS (true/false)
        int idTecnicoResponsavel; // ID do técnico que aceitou a OS
        string nomeTecnicoResponsavel; // Nome do técnico que aceitou a OS
        bool atribuida; // Indicar se a OS foi atribuida a um tecnico


    public:
        Os(); // Inicializar como construtor padrão vazio

        Os(
            int NumeroOs,
            const string &dataAbertura,
            const string &categoria,
            const string &servico,
            int prioridade,
            const string &comentarioTecnicoPara, // Comentário técnico para morador
            double valor,
            const string &dataFechamento,
            bool conclusao,
            int idMoradorCriador,
            const string &nomeMoradorCriador,
            const string &comentarioMoradorPara, // Comentário morador para técnico
            int notaAvaliacao,
            bool avaliada,
            int idTecnicoResponsavel,
            const string &nomeTecnicoResponsavel,
            bool atribuida
        );

        // Getters
        int getNumeroOs() const;
        string getDataAbertura() const;
        string getCategoria() const;
        string getServico() const;
        int getPrioridade() const;
        string getComentarioTecnico() const;
        double getValor() const;
        string getDataFechamento() const;
        bool isConcluida() const;
        int getIdMoradorCriador() const;
        string getNomeMoradorCriador() const;
        string getComentarioMorador() const;
        int getNotaAvaliacao() const;
        bool isAvaliada() const;
        int getIdTecnicoResponsavel() const;
        string getNomeTecnicoResponsavel() const;
        bool isAtribuida() const;

        // Setters
        void setComentarioTecnico(const string &comentarioTecnicoPara);
        void setValor(double valor);
        void setDataFechamento(const string &data);
        void setConclusao(bool status);

        void setAvaliacao(const string &comentarioMoradorPara, int nota);
        void setAvaliada(bool avaliada);
        void setAtribuicao(int idTecnico, const string &nomeTecnico);
        void setAtribuida(bool status);

        // Método para exibir detalhes da OS
        void exibirDetalhesTecnico() const;
        void exibiriDetalhesMorador() const;

};

#endif
