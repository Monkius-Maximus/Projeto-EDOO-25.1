#include "Morador.h"
#include <iostream>

// Construtor da classe Morador
Morador::Morador(
    int contato,
    int registroId,
    std::string nome,
    std::string apartamento,
    char classe_apto,
    bool inad,
    bool tem_os_aberta
)
    : Pessoa (
        contato,
        registroId,
        nome
    ),
    
    apartamento(apartamento),
    classe_apto(classe_apto),
    inad(inad),
    tem_os_aberta(tem_os_aberta) {}

// Método para exibir os dados do morador
void Morador::exibirDadosMorador() {
    exibirDadosPessoa(); // Chama o método da classe base Pessoa
    std::cout << "Apartamento: " << apartamento << std::endl;
    std::cout << "Classe do Apartamento: " << classe_apto << std::endl;
    std::cout << "Inadimplente: " << (inad ? "Sim" : "Não") << std::endl;
    std::cout << "Abrir OS: " << (tem_os_aberta ? "Sim" : "Não") << std::endl;
}
