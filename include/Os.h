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

        // Técnico insere
        string comentario; // Comentário do técnico sobre a situação da OS
        double valor; // Valor estimado do serviço
        string dataFechamento;
        bool conclusao; // Status de conclusão da OS (true/false)

    public:
        Os(); // Inicializar como construtor padrão vazio
        Os(
            int NumeroOs,
            const string &dataAbertura,
            const string &categoria,
            const string &servico,
            int prioridade,

            const string &comentario,
            double valor,
            const string &dataFechamento,
            bool conclusao
        );

        // Getters
        int getNumeroOs() const;
        string getDataAbertura() const;
        string getCategoria() const;
        string getServico() const;
        int getPrioridade() const;

        string getComentario() const;
        double getValor() const;
        string getDataFechamento() const;
        bool isConcluida() const;

        // Setters
        void setComentario(const string &comentario);
        void setValor(double valor);
        void setDataFechamento(const string &data);
        void setConclusao(bool status);

        // Método para exibir detalhes da OS
        void exibirDetalhes() const;

};

#endif
