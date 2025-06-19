#include "../include/Os.h"
#include "../include/json.h"
#include "../include/Persistencia.h"

#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<Os> listaOrdens = carregarDoJson("ordens.json");

    // Cria uma nova OS
    Os exemplo(
        listaOrdens.size() + 1,  // Número automático
        "13/06/2025",
        "Elétrica",
        "A fiação solta dentro do apartamento, causando risco de choque.",
        5,
        "",  // Comentário do técnico
        0.0, // Valor
        "",  // Data fechamento
        false // Está concluída?
    );

    cout << "OS criada pelo morador:\n";
    exemplo.exibirDetalhes();
    cout << "\n";

    // Técnico edita
    cout << "Técnico analisando e resolvendo a OS...\n" << endl;
    exemplo.setValor(50.50);
    exemplo.setComentario("O morador quebrou a parede e expôs a fiação.");
    exemplo.setDataFechamento("14/06/2025");
    exemplo.setConclusao(true);

    cout << "OS após intervenção do técnico:\n";
    exemplo.exibirDetalhes();

    // Adiciona a lista e salva
    listaOrdens.push_back(exemplo);
    salvarEmJson(listaOrdens, "ordens.json");

    return 0;
}
