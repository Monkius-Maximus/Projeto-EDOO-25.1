#include "../include/Os.h"
#include "../include/Morador.h"
#include "../include/Tecnico.h"
#include "../include/Persistencia.h"

#include <limits>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    system("cls");
    vector<Os> listaOrdens = carregarDoJson("ordens.json");

    Morador morador1(21, "João", "joao@email.com", "302", 'B', false);
    Tecnico tecnico1(81, "Pedro", "pedro@email.com", "Eletrica", 4.8);
    
    int opcaoPrincipal;

    do {
        system("cls");
        cout << "\n-#-#-#-#- SISTEMA DE MANUTENÇÃO PREDIAL DO EDIFÍCIO MANGABEIRAS -#-#-#-#-\n";
        cout << "1. Sou morador\n";
        cout << "2. Sou técnico\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcaoPrincipal;

        switch (opcaoPrincipal) {
            case 1: {
                int op;
                do {
                    system("cls");
                    cout << "\n-#-#-#-#- MODO MORADOR -#-#-#-#-\n";
                    cout << "Seja bem-vindo, " << morador1.getNome() << "!\n";
                    cout << "Por favor, selecione o que você deseja fazer a partir das seguintes opções:\n";  
                    cout << "1. Abrir uma OS\n";
                    cout << "2. Visualizar meus chamados\n";
                    cout << "3. Avaliar um serviço\n";
                    cout << "0. Voltar ao menu principal\n";
                    cout << "Digite uma opção: ";
                    cin >> op;
                    
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpar o buffer de entrada 

                    if (op == 1) {
                        morador1.AbrirChamado(listaOrdens);
                        cout << "Pressione Enter para continuar...";
                        cin.get();
                    }
                    
                    else if (op == 2){
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
                        cout << "Pressione ENTER para continuar...";
                        cin.get();

                    }
                    
                    else if (op == 3){
                        int osIdParaAvaliar;
                        cout << "Digite o número da OS que deseja avaliar: ";
                        cin >> osIdParaAvaliar;

                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        morador1.AvaliarServico(osIdParaAvaliar);
                    } 
                }

                while (op != 0);
                break;

            }

            case 2: {
                int op;
                do {
                    system("cls");
                    cout << "\n-#-#-#-#- MODO TÉCNICO -#-#-#-#-\n";
                    cout << "Seja bem-vindo, " << tecnico1.getNome() << "!\n";
                    cout << "Por favor, selecione o que você deseja fazer:\n";
                    cout << "1. Visualizar chamados disponíveis\n";
                    cout << "2. Fechar uma OS\n";
                    cout << "3. Aceitar um chamado\n";
                    cout << "4. Visualizar meus chamados atribuídos\n";
                    cout << "0. Voltar ao menu principal\n";
                    cout << "Digite uma opção: ";
                    cin >> op;
                    
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    switch(op) {
                        case 1:
                            tecnico1.VisualizarChamadosDisponiveis();
                            cout << "Pressione Enter para continuar...";
                            cin.get();
                            break;
                            
                        case 2:
                            tecnico1.FecharChamado();
                            break;
                            
                        case 3: {
                            int osIdParaAceitar;
                            system("cls");
                            cout << "Digite o número da OS que deseja aceitar: ";
                            cin >> osIdParaAceitar;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            tecnico1.AceitarChamado(osIdParaAceitar);
                            cout << "Pressione Enter para continuar...";
                            cin.get();
                            break;
                        }
                            
                        case 4:
                            tecnico1.VisualizarMeusChamadosAtribuidos();
                            cout << "Pressione Enter para continuar...";
                            cin.get();
                            break;
                            
                        case 0:
                            break;
                            
                        default:
                            cout << "Opção Inválida!\n";
                            cout << "Pressione Enter para continuar...";
                            cin.get();
                    }
                } while (op != 0);
                break;
            }

            case 0:
                cout << "Saindo do Sistema...\n";
                break;

            default:
                cout << "Opção Inválida!\n";
        }

    }
    
    while (opcaoPrincipal != 0);

    return 0;
}
