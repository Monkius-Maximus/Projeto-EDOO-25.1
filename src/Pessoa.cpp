#include "Pessoa.h"
#include string
using std::string

// Criar construtor

void Pessoa::exibirDadosPessoa() {
    cout << "--- Dados da Pessoa ---" << endl;
    cout << "Nome: " << nome << endl;
    cout << "ID: " << registroId << endl;
    cout << "Contato: " << contato << endl;
}