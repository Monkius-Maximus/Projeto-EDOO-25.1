#include "../include/Os.h"
#include "../include/Pessoa.h"
#include "../include/Morador.h"
#include "../include/Tecnico.h"
#include "../include/Persistencia.h"

#include <limits>
#include <vector>
#include <iostream>

using namespace std;

// --- Função Principal ---
int main()
{
    system("cls"); // Limpa a tela do console no início da execução.

     // Carrega as Ordens de Serviço existentes do arquivo JSON.
    vector<Os> listaOrdens = carregarDoJson("ordens.json");

    // Cria um vetor de ponteiros para a classe base Pessoa. Isso permite armazenar objetos Morador e Tecnico de forma polimórfica.
    vector<Pessoa *> pessoas;

    pessoas.push_back(new Morador(21, "João", "joao@email.com", "302", 'B', false)); // Adiciona um novo Morador ao vetor.
    pessoas.push_back(new Tecnico(81, "Pedro", "pedro@email.com", "Eletrica", 0.0)); // Adiciona um novo Tecnico ao vetor.

    // Loop para testes de polimorfismo. Itera sobre o vetor de ponteiros 'pessoas'.
    for (Pessoa *p : pessoas)
    {
        p->displayInfo(); // Chamada polimórfica: Chama a versão de displayInfo() da classe derivada (Morador & Tecnico)
        cout << "------------------------" << endl;
    }

    // Realiza um downcast seguro para acessar métodos específicos de Morador e Tecnico.
    Morador *morador1 = dynamic_cast<Morador *>(pessoas[0]);
    Tecnico *tecnico1 = dynamic_cast<Tecnico *>(pessoas[1]);

    int opcaoPrincipal; // Variável para armazenar a opção escolhida no menu principal.

    // Loop principal do programa, continua até o usuário escolher sair (opção 0).
    do
    {
        system("cls");
        cout << "\n-#-#-#-#- SISTEMA DE MANUTENÇÃO PREDIAL DO EDIFÍCIO MANGABEIRAS -#-#-#-#-\n";
        cout << "1. Sou morador\n"; // Opção para entrar como morador.
        cout << "2. Sou técnico\n"; // Opção para entrar como técnico.
        cout << "0. Sair\n";        // Opção para sair do programa.
        cout << "Escolha uma opção: "; 
        cin >> opcaoPrincipal; // Lê a opção do usuário.

        // Estrutura switch para lidar com as opções do menu principal.
        switch (opcaoPrincipal)
        {
        case 1: // Caso a opção seja 1 (Sou morador).
        {
            int op; // Variável para as opções do menu do morador.
            do // Loop para o menu do morador, continua até o usuário escolher voltar (opção 0).
            {
                system("cls");
                cout << "\n-#-#-#-#- MODO MORADOR -#-#-#-#-\n";
                cout << "Seja Bem-Vindo, " << morador1->getNome() << "!\n";
                cout << "Por Favor, Selecione o que Você Deseja Fazer a Partir das Seguintes Opções:\n";
                cout << "1. Verificar se Estou Inadimplente\n"; // Opção para verificar inadimplência.
                cout << "2. Abrir uma OS\n"; // Opção para abrir uma nova OS.
                cout << "3. Visualizar Meus Chamados\n"; // Opção para visualizar OSs do morador.
                cout << "4. Avaliar um Serviço\n"; // Opção para avaliar um serviço.
                cout << "0. Voltar ao Menu Principal\n"; // Opção para voltar.
                cout << "Digite uma opção: ";
                cin >> op;

                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpar o buffer de entrada

                if (op == 1) // Verificar inadimplência.
                {
                    system("cls");
                    if (morador1->VerificarInadiplencia()) // Chama o método para verificar inadimplência.
                    {
                        cout << "Você está inadimplente e não pode abrir chamados.\n";
                    }
                    else
                    {
                        cout << "Você está em dia e pode abrir chamados normalmente.\n";
                    }
                    cout << "Pressione ENTER para continuar...";
                    cin.get(); // Pausa a execução.
                }

                else if (op == 2) // Abrir uma OS.
                {
                    morador1->AbrirChamado(listaOrdens); // Chama o método AbrirChamado.
                    cout << "Pressione Enter para continuar...";
                    cin.get(); // Pausa a execução.
                }

                else if (op == 3) // Visualizar Meus Chamados (e opção de apagar).
                {
                    morador1->VisualizarMeusChamados(listaOrdens); // Chama o método VisualizarMeusChamados.

                    char desejaApagar; // Variável para a resposta do usuário.
                    cout << "Deseja apagar algum chamado? (S/N): ";
                    cin >> desejaApagar; // Lê a resposta.

                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpar o buffer de entrada

                    if (desejaApagar == 's' || desejaApagar == 'S') // Se o usuário deseja apagar.
                    {
                        int osId; // Variável para o ID da OS a ser apagada.
                        cout << "Digite o número da OS que deseja excluir: ";
                        cin >> osId; // Lê o ID da OS.

                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpar o buffer de entrada

                        cout << "Pressione ENTER para confirmar a exclusão...";
                        cin.get();

                        morador1->deletarChamado(osId, listaOrdens); // Chama o método deletarChamado.
                    }
                    cout << "Pressione ENTER para continuar...";
                    cin.get(); // Pausa a execução.
                }

                else if (op == 4) // Avaliar um Serviço.
                {
                    int osIdParaAvaliar; // Variável para o ID da OS a ser avaliada.
                    system("cls");
                    cout << "Digite o número da OS que deseja avaliar: ";
                    cin >> osIdParaAvaliar; // Lê o ID da OS.

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    morador1->AvaliarServico(osIdParaAvaliar, listaOrdens, *tecnico1); // Chama o método AvaliarServico, passando a lista de OSs e o objeto técnico.
                }
            }

            while (op != 0); // O loop do menu do morador continua até a opção 0.
            break;
        }

        case 2: // Caso a opção seja 2 (Sou técnico).
        {
            int op; // Variável para as opções do menu do técnico.
            do  // Loop para o menu do técnico, continua até o usuário escolher voltar (opção 0).
            {
                system("cls");
                cout << "\n-#-#-#-#- MODO TÉCNICO -#-#-#-#-\n";
                cout << "Seja bem-vindo, " << tecnico1->getNome() << "!\n";
                cout << "Por favor, selecione o que você deseja fazer:\n";
                cout << "1. Visualizar Chamados Disponíveis\n"; // Opção para ver OSs não concluídas/atribuídas.
                cout << "2. Aceitar um Chamado\n";              // Opção para aceitar uma OS.
                cout << "3. Fechar um Chamado\n";               // Opção para fechar uma OS.
                cout << "4. Visualizar Meus Chamados Atribuídos\n"; // Opção para ver OSs aceitas pelo próprio técnico.
                cout << "0. Voltar ao Menu Principal\n";            // Opção para voltar.
                cout << "Digite uma Opção: ";
                cin >> op;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // Estrutura switch para lidar com as opções do menu do técnico.
                switch (op)
                {
                case 1: // Visualizar Chamados Disponíveis.
                    tecnico1->VisualizarChamadosDisponiveis(); // Chama o método.
                    cout << "Pressione Enter para continuar...";
                    cin.get();
                    break;

                case 2: // Aceitar um Chamado.
                {
                    int osIdParaAceitar;
                    system("cls");
                    cout << "Digite o número da OS que deseja aceitar: ";
                    cin >> osIdParaAceitar;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    tecnico1->AceitarChamado(osIdParaAceitar); // Chama o método AceitarChamado.
                    cout << "Pressione Enter para continuar...";
                    cin.get();
                    break;
                }

                case 3: // Fechar um Chamado.
                    tecnico1->FecharChamado(); // Chama o método FecharChamado().
                    break;

                case 4: // Visualizar Meus Chamados Atribuídos.
                    tecnico1->VisualizarMeusChamadosAtribuidos(); // Chama o método.
                    cout << "Pressione Enter para continuar...";
                    cin.get();
                    break;

                case 0: // Opção: Voltar ao Menu Principal.
                    break;

                default: // Caso a opção principal seja inválida.
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
