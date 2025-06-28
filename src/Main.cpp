#include "../include/Os.h"
#include "../include/Pessoa.h"
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
    
    vector<Pessoa*> pessoas;
    pessoas.push_back(new Morador(21, "João", "joao@email.com", "302", 'B', false));
    pessoas.push_back(new Tecnico(81, "Pedro", "pedro@email.com", "Eletrica", 0.0));
    
    // Para testes de polimorfismo:
    for (Pessoa* p : pessoas) {
        p->displayInfo();  // Chamada polimórfica
        cout << "------------------------" << endl;
    }
    
    Morador* morador1 = dynamic_cast<Morador*>(pessoas[0]);
    Tecnico* tecnico1 = dynamic_cast<Tecnico*>(pessoas[1]);
    
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
                    cout << "Seja Bem-Vindo, " << morador1->getNome() << "!\n";
                    cout << "Por Favor, Selecione o que Você Deseja Fazer a Partir das Seguintes Opções:\n";  
                    cout << "1. Verificar se Estou Inadimplente\n";
                    cout << "2. Abrir uma OS\n";
                    cout << "3. Visualizar Meus Chamados\n";
                    cout << "4. Avaliar um Serviço\n";
                    cout << "0. Voltar ao Menu Principal\n";
                    cout << "Digite uma opção: ";
                    cin >> op;
                    
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpar o buffer de entrada 

                    if (op == 1){
                        system("cls");
                        if (morador1->VerificarInadiplencia()) {
                            cout << "Você está inadimplente e não pode abrir chamados.\n";
                        } else {
                            cout << "Você está em dia e pode abrir chamados normalmente.\n";
                        }
                        cout << "Pressione ENTER para continuar...";
                        cin.get();
                    }

                    else if (op == 2) {
                        morador1->AbrirChamado(listaOrdens);
                        cout << "Pressione Enter para continuar...";
                        cin.get();
                    }
                    
                    else if (op == 3){
                        morador1->VisualizarMeusChamados();

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

                            morador1->deletarChamado(osId);
                        }
                        cout << "Pressione ENTER para continuar...";
                        cin.get();

                    }
                    
                    else if (op == 4){
                        int osIdParaAvaliar;
                        system("cls");
                        cout << "Digite o número da OS que deseja avaliar: ";
                        cin >> osIdParaAvaliar;

                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        morador1->AvaliarServico(osIdParaAvaliar, *tecnico1);
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
                    cout << "Seja bem-vindo, " << tecnico1->getNome() << "!\n";
                    cout << "Por favor, selecione o que você deseja fazer:\n";
                    cout << "1. Visualizar Chamados Disponíveis\n";
                    cout << "2. Aceitar um Chamado\n";
                    cout << "3. Fechar um Chamado\n";
                    cout << "4. Visualizar Meus Chamados Atribuídos\n";
                    cout << "0. Voltar ao Menu Principal\n";
                    cout << "Digite uma Opção: ";
                    cin >> op;
                    
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    switch(op) {
                        case 1:
                            tecnico1->VisualizarChamadosDisponiveis();
                            cout << "Pressione Enter para continuar...";
                            cin.get();
                            break;
                            
                        case 2: {
                            int osIdParaAceitar;
                            system("cls");
                            cout << "Digite o número da OS que deseja aceitar: ";
                            cin >> osIdParaAceitar;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            tecnico1->AceitarChamado(osIdParaAceitar);
                            cout << "Pressione Enter para continuar...";
                            cin.get();
                            break;
                        }

                        case 3:
                            tecnico1->FecharChamado();
                            break;
                            
                        case 4:
                            tecnico1->VisualizarMeusChamadosAtribuidos();
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

                }
                
                while (op != 0);
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
