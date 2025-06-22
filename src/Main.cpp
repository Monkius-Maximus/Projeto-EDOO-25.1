#include "../include/Os.h"
#include "../include/Persistencia.h"
#include "../include/Morador.h"
#include "../include/Tecnico.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    system("cls");
    vector<Os> listaOrdens = carregarDoJson("ordens.json");

    Morador morador1(1, "Bruno", "bruno@email.com", "302", 'B', false);
    Tecnico tecnico1(1, "Lucas", "Lucas@email.com", "Elétrica", true, 4.5);

    int opcaoPrincipal;

    do {
        system("cls");
        cout << "\n-#-#-#-#- SISTEMA DE MANUTENÇÃO PREDIAL DO EDIFÍCIO MANGABEIRAS -#-#-#-#-\n";
        cout << "1. Entrar como Morador\n";
        cout << "2. Entrar como Técnico\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcaoPrincipal;

        switch (opcaoPrincipal) {
            case 1: {
                int op;
                do {
                    system("cls");
                    cout << "\n--- MODO MORADOR ---\n";
                    cout << "1. Abrir uma OS\n";
                    cout << "0. Voltar ao menu principal\n";
                    cout << "Escolha: ";
                    cin >> op;

                    if (op == 1) {
                        morador1.AbrirChamado(listaOrdens);
                    }

                } while (op != 0);
                break;
            }

            case 2: {
                int op;
                do {
                    system("cls");
                    cout << "\n--- MODO TÉCNICO ---\n";
                    cout << "1. Fechar uma OS\n";
                    cout << "0. Voltar ao menu principal\n";
                    cout << "Escolha: ";
                    cin >> op;

                    if (op == 1) {
                        tecnico1.FecharChamado(listaOrdens);
                    }

                } while (op != 0);
                break;
            }

            case 0:
                cout << "Saindo do sistema...\n";
                break;

            default:
                cout << "Opção inválida!\n";
        }

    } while (opcaoPrincipal != 0);

    return 0;
}
