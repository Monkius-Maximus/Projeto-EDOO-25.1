#include "Pessoa.h"
#include <iostream>

// Construtor da classe Pessoa
Pessoa::Pessoa (
    int contato,
    int registroId,
    std::string nome
)
    : contato(contato),
    registroId(registroId),
    nome(nome) {}

void Pessoa::exibirDadosPessoa() {
    std::cout << "--- Dados da Pessoa ---" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "ID: " << registroId << std::endl;
    std::cout << "Contato: " << contato << std::endl;
}
