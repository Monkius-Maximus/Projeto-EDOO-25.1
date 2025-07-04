#include "../include/Tecnico.h"
#include "../include/Persistencia.h"

#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include <cctype>
#include "Tecnico.h"

using namespace std;

// --- Construtor Padrão ---
// Inicializa um objeto Tecnico com valores padrão.
Tecnico::Tecnico()

    : Pessoa() // Chama o construtor padrão da classe base Pessoa.
{
    especialidade = "N/A";
    nota = 0.0;
};

// --- Construtor com Parâmetros ---
// Inicializa um objeto Tecnico com valores específicos fornecidos como argumentos.
Tecnico::Tecnico(
    int numeroOs,
    const string &nome,
    const string &email,
    const string &especialidade,
    double nota)

    : Pessoa( // Chama o construtor da classe base Pessoa.
        numeroOs,
        nome,
        email)

{   // Atribui utilizando 'this->':
    this->especialidade = especialidade;
    this->nota = nota;
};

// --- Getters ---
string Tecnico::getEspecialidade() const { return especialidade; }
double Tecnico::getNota() const { return nota; }

// --- Setters ---
void Tecnico::setEspecialidade(const string &novaEspecialidade)
{
    if (!novaEspecialidade.empty()) // Verificar se a string não é vázia
    {
        especialidade = novaEspecialidade;
    }

    else
    {
        system("cls");
        cout << "Erro: Especialidade não pode ser vázia" << endl; // Mensagem de erro caso contrário.
    }
};

void Tecnico::setNota(double novaNota)
{   
    // Verificar se a nota deve estra entre 0.0 e 5.0:
    if (novaNota >= 0.0 && novaNota <= 5.0)
    {
        nota = novaNota;
    }

    else
    {
        system("cls");
        cout << "Erro: Nota inválida. A nota deve estar entre 0.0 e 5.0" << endl; // Mensagem de erro caso contrário.
    }
}

// --- Métodos da classe Tecnico ---

// Método para visualizar chamados que estão disponíveis para serem aceitos.
void Tecnico::VisualizarChamadosDisponiveis() const
{
    system("cls");
    cout << "\n-*-*- Chamados Disponíveis para o Técnico " << getNome() << " -*-*-\n";

    vector<Os> listaOs = carregarDoJson("ordens.json"); // Carrega todas as OSs do arquivo JSON.

    bool temChamadoDisponiveis = false;
    for (const Os &os : listaOs) // Itera sobre cada OS na lista.
    {
        if (!os.isConcluida()) // Verifica se a OS não foi concluida.
        {
            temChamadoDisponiveis = true;
            os.exibirDetalhesTecnico();
            cout << "----------------------------------------\n";
        }
    }

    if (!temChamadoDisponiveis) // Se nenhum chamado disponível foi encontrado.
    {
        system("cls");
        cout << "Não há chamados disponíveis no momento\n."; // Mensagem.
    }
    cout << "\n";
}

// Comparar Categoria da OS e Especialidade do Técnico independente de maiúsculas/minúsculas
string transformaString(const string &str)
{
    string minuscula = str;
    transform(minuscula.begin(), minuscula.end(), minuscula.begin(), [](unsigned char c)
            { return tolower(c); });
    return minuscula;
}

// Método para aceitar uma Ordem de Serviço específica.
void Tecnico::AceitarChamado(int osId)
{
    system("cls");
    cout << "\n-*-*- Aceitar Chamado (OS #" << osId << ") -*-*-\n";

    vector<Os> listaOs = carregarDoJson("ordens.json"); // Carrega a lista de OSs do arquivo JSON.
    bool osEncontrada = false;

     // Procurar a OS específica pelo ID.
    for (auto &os : listaOs) // Usa referência '&' para que as modificações no objeto 'os' afetem a 'listaOs'.
    {
        if (os.getNumeroOs() == osId) // Se a OS com o ID correspondeu.
        {
            osEncontrada = true;

            // Verificar se a OS já está concluída
            if (os.isConcluida())
            {
                cout << "A OS #" << osId << " já foi concluída e não pode ser aceita.\n";
                return;
            }

            // Verificar se já está atribuída a outro técnico
            if (os.isAtribuida())
            {
                cout << "A OS #" << osId << " já foi atribuída ao técnico "
                    << os.getNomeTecnicoResponsavel() << " (ID: "
                    << os.getIdTecnicoResponsavel() << ").\n";
                return;
            }

            // Verificar se a categoria da OS corresponde à especialidade do técnico.
            if (transformaString(os.getCategoria()) != transformaString(getEspecialidade()))
            {
                cout << "Esta OS não corresponde à sua especialidade ("
                    << getEspecialidade() << ").\n";
                cout << "Categoria da OS: " << os.getCategoria() << endl;
                return;
            }

            // Se todas as validações passaram, atribui a OS ao técnico.
            os.setAtribuicao(getId(), getNome()); // Define o técnico responsável pela OS.
            salvarEmJson(listaOs, "ordens.json"); // Salva a lista atualizada de OSs no JSON.

            cout << "OS #" << osId << " aceita com sucesso por " << getNome() << "!\n";
            cout << "Agora você é o técnico responsável por esta OS.\n";

            break;
        }
    }

    if (!osEncontrada) // Se a OS não foi encontrada após o loop.
    {
        cout << "OS #" << osId << " não encontrada.\n";
    }
}

// Método para fechar uma Ordem de Serviço.
void Tecnico::FecharChamado()
{
    system("cls");
    int numeroOs;
    cout << "\n-*-*- Fechamento de Chamado -*-*-\n";

    vector<Os> listaOs = carregarDoJson("ordens.json"); // Carrega todas as OSs.

    // Mostra os chamados atribuídos ao técnico primeiro, para ele escolher qual fechar.
    VisualizarMeusChamadosAtribuidos();

    cout << "Digite o número da OS que deseja fechar (ou 0 para cancelar): ";
    cin >> numeroOs;

    if (numeroOs == 0) // Opção para cancelar o fechamento.
    {
        return; // Sai da função.
    }

    bool encontrada = false;

    // Itera sobre a lista de OSs.
    for (auto &os : listaOs) // Usa referência '&' para poder modificar o objeto 'os'.
    {
        if (os.getNumeroOs() == numeroOs) // Se a OS com o número correspondeu.
        {
            encontrada = true;

            // Verificar se o técnico atual é o responsável pela OS.
            if (os.getIdTecnicoResponsavel() != getId())
            {
                cout << "\nVocê não é o técnico responsável por esta OS.\n";
                cout << "Pressione Enter para continuar...";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.get();
                return;
            }

            system("cls");
            cout << "\nOS encontrada. Dados atuais:\n";
            os.exibirDetalhesTecnico(); // Exibe os detalhes da OS no formato para técnico.
            cout << "\n";

            string comentarioTecnicoEntrada, dataFechamento; // Variáveis para os dados de fechamento.
            double valor;

            cout << "Comentário técnico: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, comentarioTecnicoEntrada); // Lê o comentário do técnico.

            cout << "Valor do serviço: R$ ";

            // Validação do valor (deve ser um número positivo).
            while (!(cin >> valor) || valor < 0)
            {
                cout << "Valor inválido! Digite um número positivo: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Data de fechamento (dd/mm/aaaa): ";
            cin.ignore();
            getline(cin, dataFechamento); // Lê a data de fechamento.

            // Atualiza os campos da OS.
            os.setComentarioTecnico(comentarioTecnicoEntrada);
            os.setValor(valor);
            os.setDataFechamento(dataFechamento);
            os.setConclusao(true); // Marca a OS como concluída.

            salvarEmJson(listaOs, "ordens.json"); // Salva a lista atualizada de OSs no JSON.


            system("cls");
            cout << "\nOS #" << numeroOs << " fechada com sucesso!\n"; // Confirmação.
            cout << "Pressione Enter para continuar...";
            cin.get();
            return; // Sai da função após o fechamento.
        }
    }

    if (!encontrada) // Se a OS não foi encontrada após o loop.
    {
        cout << "\nNenhuma OS com esse número foi encontrada.\n";
        cout << "Pressione Enter para continuar...";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
    }
}

// Método para visualizar os chamados que foram atribuídos a este técnico.
void Tecnico::VisualizarMeusChamadosAtribuidos() const
{
    system("cls");
    cout << "\n-*-*- Chamados atribuídos para o técnico " << getNome() << ": -*-*-\n";

    vector<Os> listaOs = carregarDoJson("ordens.json"); // Carrega todas as OSs.

    bool temChamadosAtribuidos = false;
    for (const Os &os : listaOs) // Itera sobre as OSs.
    {
        // Verifica se a OS está atribuída E se o ID do técnico responsável corresponde ao ID deste técnico.
        if (os.isAtribuida() && os.getIdTecnicoResponsavel() == getId())
        {
            temChamadosAtribuidos = true;
            os.exibirDetalhesTecnico(); // Exibe os detalhes no formato para técnico.
            cout << "----------------------------------------\n";
        }
    }

    if (!temChamadosAtribuidos) // Se nenhum chamado atribuído foi encontrado.
    {
        system("cls");
        cout << "Você não tem nenhum chamado atribuído no momento.\n";
    }
    cout << "\n";
}

// Método para atualizar a nota média do técnico com base nas avaliações das OSs que ele atendeu.
void Tecnico::atualizarNotaMedia()
{
    vector<Os> listaOs = carregarDoJson("ordens.json"); // Carrega todas as OSs.

    int somaNotas = 0; // Variável para somar as notas das avaliações.
    int totalAvaliacoes = 0; // Contador de avaliações válidas.

    for (const Os &os : listaOs) // Itera sobre as OSs.
    {
        // Verifica se a OS foi avaliada e se este técnico foi o responsável.
        if (os.isAvaliada() && os.getIdTecnicoResponsavel() == getId())
        {
            somaNotas += os.getNotaAvaliacao(); // Adiciona a nota à soma.
            totalAvaliacoes++; // Incrementa o contador.
        }
    }

    if (totalAvaliacoes > 0) // Se há avaliações, calcula a média.
    {
        // Calcula a média, usando static_cast<double> para garantir divisão de ponto flutuante.
        nota = static_cast<double>(somaNotas) / totalAvaliacoes;
    }
    else // Se não há avaliações, a nota média é 0.0.
    {
        nota = 0.0;
    }
}

// Método para exibir informações detalhadas do técnico (sobrescrevendo displayInfo de Pessoa).
void Tecnico::displayInfo() const
{
    cout << "TÉCNICO\n";
    Pessoa::displayInfo(); // Chama a versão da classe base para exibir informações gerais de Pessoa.
    cout << "Especialidade: " << especialidade << endl; // Exibe a especialidade.
    cout << "Nota média: " << nota << endl; // Exibe a nota média.
}
