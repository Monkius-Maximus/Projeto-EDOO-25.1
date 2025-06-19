#include "../include/Os.hpp"
#include <iostream>

using namespace std;

int main() {
    // 1° - Morador cria uma OS
    Os exemplo(
        1,
        "13/06/2025",
        "Elétrica",
        "A fiação solta dentro do apartamento, causando risco de choque.",
        5,

        "",  // Comentário do técnico
        0, // Ainda não há valor 
        "",  // Ainda não há data de fechamento
        false // Não está concluída
    );

    cout << "OS criada pelo morador:\n";
    exemplo.exibirDetalhes();
    cout << "\n";

    // 2° - Técnico acessa a OS
    cout << "Técnico analisando a OS...\n" << endl;

    // Adiciona valor
    exemplo.setValor (50.50);

    // Adiciona comentário
    exemplo.setComentario("O morador quebrou a parede e expôs a fiação.");

    // Fecha a OS com data
    exemplo.setDataFechamento("14/06/2025");

    // Marca como concluída
    exemplo.setConclusao(true);

    // 3° - Exibe os dados atualizados
    cout << "OS após intervenção do técnico:\n";
    exemplo.exibirDetalhes();

    return 0;
}
