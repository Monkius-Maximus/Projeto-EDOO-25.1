#include "Os.h"
#include <iostream>

// Construtor da classe Morador
Os::Os(
    int contato,
    int registroId,
    std::string nome,
    std::string servico,
    double valor,
    int prioridade,
    int data_abertura,
    int data_fechamento,
    bool conclusao
)
    : Pessoa (
        contato,
        registroId,
        nome
    ),
    
    servico(servico),
    valor(valor),
    prioridade(prioridade),
    data_abertura(data_abertura),
    data_fechamento(data_fechamento),
    conclusao(conclusao) {}

// Método para exibir os dados do morador
void Os::exibirDadosOs() {
    exibirDadosPessoa(); // Chama o método da classe base Pessoa
    std::cout << "Serviço: " << servico << std::endl;
    std::cout << "Valor: " << valor << std::endl;
    std::cout << "Prioridade: " << prioridade << std::endl;
    std::cout << "Data de Abertura: " << data_abertura << std::endl;
    std::cout << "Data de Fechamento: " << data_fechamento << std::endl;
    std::cout << "Conclusão: " << (conclusao ? "Sim" : "Não") << std::endl;
}
