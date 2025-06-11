#include "Pessoa.h"
#include <string>
#include <iostream>
using std::string;

// Criar construtor

void Pessoa::exibirDadosPessoa() {
    std::cout << "--- Dados da Pessoa ---" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "ID: " << registroId << std::endl;
    std::cout << "Contato: " << contato << std::endl;
}
