#include "../include/Tecnico.h"
#include "../include/Persistencia.h"

#include <iostream>
#include <limits>

using namespace std;

Tecnico::Tecnico()

:Pessoa()
{
    especialidade = "N/A";
    disponibilidade = false;
    nota = 0.0;
};

Tecnico::Tecnico(
    int numeroOs,
    const string &nome,
    const string &email, 
    const string &especialidade, 
    bool disponibilidade, 
    double nota
)

:Pessoa(
    numeroOs, 
    nome, 
    email
)

{
    this->especialidade = especialidade;
    this->disponibilidade = disponibilidade; 
    this->nota = nota; 
};

void Tecnico::FecharChamado(vector<Os>& listaOs) {
    int numeroOs;
    cout << "\n-*-*- Fechamento de Chamado -*-*-\n";
    cout << "Digite o número da OS que deseja fechar: ";
    cin >> numeroOs;
    
    bool encontrada = false;

    for (auto& os : listaOs) {
        if (os.getNumeroOs() == numeroOs) {
            encontrada = true;
            cout << "\nOS encontrada. Dados atuais:\n";
            os.exibirDetalhes();
            cout << "\n";

            string comentario, dataFechamento;
            double valor;

            cout << "Comentário técnico: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, comentario);

            cout << "Valor do serviço: R$ ";
            cin >> valor;

            cout << "Data de fechamento (dd/mm/aaaa): ";
            cin.ignore();
            getline(cin, dataFechamento);

            os.setComentario(comentario);
            os.setValor(valor);
            os.setDataFechamento(dataFechamento);
            os.setConclusao(true);

            cout << "\nOS fechada com sucesso!\n";
            salvarEmJson(listaOs, "ordens.json");
            break;
        }
    }

    if (!encontrada) {
        cout << "Nenhuma OS com esse número foi encontrada.\n";
    }
}
