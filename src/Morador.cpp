#include "../include/Morador.h"
#include "../include/Persistencia.h"

#include <iostream>
#include <limits>

using namespace std;

Morador::Morador()

:Pessoa()
{
    apartamento = "N/A";
    classeApartamento = 'N';
    inadiplente = false;
};

Morador::Morador(
    int id,
    const string &nome,
    const string &email,
    const string &apartamento,
    char classeApartamento,
    bool inadiplente
)

:Pessoa(
    id,
    nome,
    email
)

{
    this->apartamento = apartamento;
    this-> classeApartamento = classeApartamento;
    this->inadiplente = inadiplente;
};

Os* Morador::AbrirChamado(vector<Os>& listaOs){
    if(VerificarInadiplencia()){
        cout << "Olá, " << getNome() << " você está inadiplente e não poderá abrir chamados.\n";
        return nullptr;
    }

    int numero = listaOs.size() + 1;
    string data, categoria, servico;
    int prioridade;

    cout << "\n-*-*- Abertura de OS -*-*-\n";
    cout << "Data de abertura (dd/mm/aaaa): ";
    getline(cin >> ws, data);
    cout << "Categoria do serviço: ";
    getline(cin, categoria);
    cout << "Descrição do serviço: ";
    getline(cin, servico);
    cout << "Prioridade (1 a 5): ";
    cin >> prioridade;

    Os novaOs(
        numero,
        data,
        categoria,
        servico,
        prioridade,
        "",    // Comentário
        0.0,   // Valor
        "",    // Data de fechamento
        false  // Conclusão
    );
    
    listaOs.push_back(novaOs);
    salvarEmJson(listaOs, "ordens.json");
    
    cout << "OS aberta com sucesso!\n" << endl;
    return &listaOs.back();
    
}

bool Morador::VerificarInadiplencia() const {
    return inadiplente;
}
