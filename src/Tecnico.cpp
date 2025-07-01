#include "../include/Tecnico.h"
#include "../include/Persistencia.h"

#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include <cctype>
#include "Tecnico.h"

using namespace std;

Tecnico::Tecnico()

    : Pessoa()
{
    especialidade = "N/A";
    nota = 0.0;
};

Tecnico::Tecnico(
    int numeroOs,
    const string &nome,
    const string &email,
    const string &especialidade,
    double nota)

    : Pessoa(
          numeroOs,
          nome,
          email)

{
    this->especialidade = especialidade;
    this->nota = nota;
};

// Getters:
string Tecnico::getEspecialidade() const { return especialidade; }
double Tecnico::getNota() const { return nota; }

// Setter:
void Tecnico::setEspecialidade(const string &novaEspecialidade)
{
    if (!novaEspecialidade.empty())
    {
        especialidade = novaEspecialidade;
    }

    else
    {
        system("cls");
        cout << "Erro: Especialidade não pode ser vázia" << endl;
    }
};

void Tecnico::setNota(double novaNota)
{
    if (novaNota >= 0.0 && novaNota <= 5.0)
    {
        nota = novaNota;
    }

    else
    {
        system("cls");
        cout << "Erro: Nota inválida. A nota deve estar entre 0.0 e 5.0" << endl;
    }
}

// Métodos da classe:
void Tecnico::VisualizarChamadosDisponiveis() const
{
    system("cls");
    cout << "\n-*-*- Chamados Disponíveis para o Técnico " << getNome() << " -*-*-\n";

    vector<Os> listaOs = carregarDoJson("ordens.json");

    bool temChamadoDisponiveis = false;
    for (const Os &os : listaOs)
    {
        if (!os.isConcluida())
        {
            temChamadoDisponiveis = true;
            os.exibirDetalhesTecnico();
            cout << "----------------------------------------\n";
        }
    }

    if (!temChamadoDisponiveis)
    {
        system("cls");
        cout << "Não há chamados disponíveis no momento\n.";
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

void Tecnico::AceitarChamado(int osId)
{
    system("cls");
    cout << "\n-*-*- Aceitar Chamado (OS #" << osId << ") -*-*-\n";

    // Carregar a lista de OSs
    vector<Os> listaOs = carregarDoJson("ordens.json");
    bool osEncontrada = false;

    // Procurar a OS específica
    for (auto &os : listaOs)
    {
        if (os.getNumeroOs() == osId)
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

            // Verificar especialidade

            if (transformaString(os.getCategoria()) != transformaString(getEspecialidade()))
            {
                cout << "Esta OS não corresponde à sua especialidade ("
                     << getEspecialidade() << ").\n";
                cout << "Categoria da OS: " << os.getCategoria() << endl;
                return;
            }

            // Atribuir a OS ao técnico
            os.setAtribuicao(getId(), getNome());
            salvarEmJson(listaOs, "ordens.json");

            cout << "OS #" << osId << " aceita com sucesso por " << getNome() << "!\n";
            cout << "Agora você é o técnico responsável por esta OS.\n";

            break;
        }
    }

    if (!osEncontrada)
    {
        cout << "OS #" << osId << " não encontrada.\n";
    }
}

void Tecnico::FecharChamado()
{
    system("cls");
    int numeroOs;
    cout << "\n-*-*- Fechamento de Chamado -*-*-\n";

    vector<Os> listaOs = carregarDoJson("ordens.json");

    // Mostrar os chamados atribuídos primeiro
    VisualizarMeusChamadosAtribuidos();

    cout << "Digite o número da OS que deseja fechar (ou 0 para cancelar): ";
    cin >> numeroOs;

    if (numeroOs == 0)
    {
        return; // Cancelar operação
    }

    bool encontrada = false;

    for (auto &os : listaOs)
    {
        if (os.getNumeroOs() == numeroOs)
        {
            encontrada = true;

            // Verificar se o técnico atual é o responsável pela OS
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
            os.exibirDetalhesTecnico();
            cout << "\n";

            string comentarioTecnicoEntrada, dataFechamento;
            double valor;

            cout << "Comentário técnico: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, comentarioTecnicoEntrada);

            cout << "Valor do serviço: R$ ";
            while (!(cin >> valor) || valor < 0)
            {
                cout << "Valor inválido! Digite um número positivo: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Data de fechamento (dd/mm/aaaa): ";
            cin.ignore();
            getline(cin, dataFechamento);

            // Atualizar campos
            os.setComentarioTecnico(comentarioTecnicoEntrada);
            os.setValor(valor);
            os.setDataFechamento(dataFechamento);
            os.setConclusao(true);

            salvarEmJson(listaOs, "ordens.json");

            system("cls");
            cout << "\nOS #" << numeroOs << " fechada com sucesso!\n";
            cout << "Pressione Enter para continuar...";
            cin.get();
            return; // Sai após fechar uma OS
        }
    }

    if (!encontrada)
    {
        cout << "\nNenhuma OS com esse número foi encontrada.\n";
        cout << "Pressione Enter para continuar...";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
    }
}

void Tecnico::VisualizarMeusChamadosAtribuidos() const
{
    system("cls");
    cout << "\n-*-*- Chamados atribuídos para o técnico " << getNome() << ": -*-*-\n";

    vector<Os> listaOs = carregarDoJson("ordens.json");

    bool temChamadosAtribuidos = false;
    for (const Os &os : listaOs)
    {
        if (os.isAtribuida() && os.getIdTecnicoResponsavel() == getId())
        {
            temChamadosAtribuidos = true;
            os.exibirDetalhesTecnico();
            cout << "----------------------------------------\n";
        }
    }

    if (!temChamadosAtribuidos)
    {
        system("cls");
        cout << "Você não tem nenhum chamado atribuído no momento.\n";
    }
    cout << "\n";
}

void Tecnico::atualizarNotaMedia()
{
    vector<Os> listaOs = carregarDoJson("ordens.json");

    int somaNotas = 0;
    int totalAvaliacoes = 0;

    for (const Os &os : listaOs)
    {
        if (os.isAvaliada() && os.getIdTecnicoResponsavel() == getId())
        {
            somaNotas += os.getNotaAvaliacao();
            totalAvaliacoes++;
        }
    }

    if (totalAvaliacoes > 0)
    {
        nota = static_cast<double>(somaNotas) / totalAvaliacoes;
    }
    else
    {
        nota = 0.0;
    }
}

void Tecnico::displayInfo() const
{
    cout << "TÉCNICO\n";
    Pessoa::displayInfo();
    cout << "Especialidade: " << especialidade << endl;
    cout << "Nota média: " << nota << endl;
}
