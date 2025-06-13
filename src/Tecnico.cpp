#include "Tecnico.h"
#include <iostream>

// Construtor da classe Morador
Tecnico::Tecnico(
    int contato,
    int registroId,
    std::string nome,
    string especialidade,
    bool disponibilidade,
    std::string os,
    double nota,
    bool os_fechada,
    std::string comentario

)
    : Pessoa (
        contato,
        registroId,
        nome
    ),
    
    especialidade(especialidade),
    disponibilidade(disponibilidade),
    os(os),
    nota(nota),
    os_fechada(os_fechada),
    comentario(comentario) {}

// Método para exibir os dados do morador
void Tecnico::exibirDadosTecnico() {
    exibirDadosPessoa(); // Chama o método da classe base Pessoa
    std::cout << "Especialidade: " << especialidade << std::endl;
    std::cout << "Disponível: " << (disponibilidade ? "Sim" : "Não") << std::endl;
    std::cout << "Ordem de Serviço: " << os << std::endl;
    std::cout << "Nota: " << nota << std::endl;
    std::cout << "OS Fechada: " << (os_fechada ? "Sim" : "Não") << std::endl;
    std::cout << "Comentário: " << comentario << std::endl;
}
