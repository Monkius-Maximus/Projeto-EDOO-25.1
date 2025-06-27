#include "../include/Os.h"
#include "../include/Persistencia.h"
#include "../include/Morador.h"
#include "../include/Tecnico.h"

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    system("cls");
    vector<Os> listaOrdens = carregarDoJson("ordens.json");

    Morador morador1(1, "Bruno", "bruno@email.com", "302", 'B', false);
    Tecnico tecnico1(1, "Lucas", "Lucas@email.com", "Eletrica", true, 4.5);

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
                    cout << "Seja bem vindo, " << morador1.getNome() << "!\n";   
                    cout << "1. Abrir uma OS\n";
                    cout << "2. Visualizar Meus Chamados\n";
                    cout << "3. Avaliar um Serviço\n";
                    cout << "0. Voltar ao menu principal\n";
                    cout << "Escolha: ";
                    cin >> op;

                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpar o buffer de entrada 

                    if (op == 1) {
                        morador1.AbrirChamado(listaOrdens);
                        cout << "Pressione Enter para continuar...";
                        cin.get();
                    }else if (op == 2){
                        morador1.VisualizarMeusChamados();

                        char desejaApagar;
                        cout << "Deseja apagar algum chamado? (S/N): ";
                        cin >> desejaApagar;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpar o buffer de entrada 

                        if (desejaApagar == 's' || desejaApagar == 'S'){
                            int osId;
                            cout << "Digite o número da OS que deseja excluir: ";
                            cin >> osId;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpar o buffer de entrada 
                            cout << "Pressione ENTER para confirmar a exclusão...";
                            cin.get();

                            morador1.deletarChamado(osId);
                        }
                        cout << "Pressione Enter para continuar...";
                        cin.get();
                    } else if (op == 3){
                        int osIdParaAvaliar;
                        cout << "Digite o número da OS que deseja avaliar: ";
                        cin >> osIdParaAvaliar;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        morador1.AvaliarServico(osIdParaAvaliar);
                        cout << "Pressione Enter para continuar...";
                        cin.get();
                    } 
                } while (op != 0);
                break;
            }

            case 2: {
                int op;
                do {
                    system("cls");
                    cout << "\n--- MODO TÉCNICO ---\n";
                    cout << "Seja bem vindo, " << tecnico1.getNome() << "!\n"; 
                    cout << "1. Visualizar Chamados Disponíveis\n";
                    cout << "2. Fechar uma OS\n";
                    cout << "3. Aceitar um chamado\n";
                    cout << "4. Visualizar Meus Chamados Atribuídos\n";
                    cout << "0. Voltar ao menu principal\n";
                    cout << "Escolha: ";
                    cin >> op;
                    
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(op == 1){
                        tecnico1.VisualizarChamadosDisponiveis();
                        cout << "Pressione Enter para continuar...";
                        cin.get();
                    }else if (op == 2) {
                        tecnico1.FecharChamado(listaOrdens);
                        cout << "Pressione Enter para continuar...";
                        cin.get();
                    }else if(op == 3){
                        int osIdParaAceitar;
                        cout << "Digite o número da OS que deseja aceitar: ";
                        cin >> osIdParaAceitar;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        tecnico1.AceitarChamado(osIdParaAceitar);
                        cout << "Pressione Enter para continuar...";
                        cin.get();
                    }else if (op == 4){
                        tecnico1.VisualizarMeusChamadosAtribuidos();
                        cout << "Pressione Enter para continuar...";
                        cin.get();
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
