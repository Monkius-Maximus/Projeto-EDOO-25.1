#include "../include/Tecnico.h"
#include "../include/Morador.h"
#include "../include/Persistencia.h"

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// --- Construtor Padrão ---
Morador::Morador()

    : Pessoa() // Chama o construtor padrão da classe base Pessoa.
{   // Inicializa os atributos com um valor padrão:
    apartamento = "N/A"; 
    classeApartamento = 'N';
    inadiplente = false;
};

// --- Construtor com Parâmetros ---
Morador::Morador(
    int idRegistro, 
    const string &nome,
    const string &email,
    const string &apartamento,
    char classeApartamento,
    bool inadiplente)

    : Pessoa( // Chama o construtor da classe base Pessoa com os parâmetros herdados:
        idRegistro,
        nome,
        email)

{ // Atribuições dos parâmetros aos membros da classe (usando 'this->' para clareza).
    this->apartamento = apartamento; 
    this->classeApartamento = classeApartamento; 
    this->inadiplente = inadiplente; 
};

// --- Getters ---
string Morador::getApartamento() const { return apartamento; } 
char Morador::getClasseApartamento() const { return classeApartamento; }
bool Morador::getInadiplente() const { return inadiplente; }

// --- Setter ---
void Morador::setApartamento(string &novoApartamento)
{
    if (!novoApartamento.empty()) //Verificar se a string não está vázia.
    {
        apartamento = novoApartamento;
    }
    else
    {
        system("cls"); // Limpa a tela.
        cout << "Erro: Apartamento não pode ser vázio!" << endl; // Mensagem de erro caso contrário.
    }
};

void Morador::setClasseApartamento(char novaClasseAp)
{
    // Verifica se a nova classe é 'A', 'B', 'C' ou 'D':
    if (novaClasseAp == 'A' || novaClasseAp == 'B' || novaClasseAp == 'C' || novaClasseAp == 'D')
    {
        classeApartamento = novaClasseAp;
    }
    else
    {
        system("cls"); // Limpa a tela.
        cout << "Erro: Classe de apartamento inválida!" << endl; // Mensagem de erro caso contrário.
    }
};
void Morador::setInadiplente(bool status)
{
    inadiplente = status; // Define o Status de inadimplência. 
}

// --- Função auxiliar global para pausar a execução ---
void aguardarEnter() 
{
    cout << "Pressione ENTER para continuar...";
    cin.get();
}

// --- Métodos da classe ---

// Método para abrir uma nova Ordem de Serviço (OS).
Os *Morador::AbrirChamado(vector<Os> &listaOs)
{
    if (VerificarInadiplencia()) // Verifica se o morador está inadimplente.
    {
        cout << "Olá, " << getNome() << " você está inadiplente e não poderá abrir chamados.\n";
        return nullptr; // Retorna nulo se inadimplente.
    }
    // Encontra o maior número de OS existente para incrementar.
    int maiorNumero = 0;
    for (const Os &os : listaOs)
    {
        if (os.getNumeroOs() > maiorNumero)
        {
            maiorNumero = os.getNumeroOs();
        }
    }
    int numero = maiorNumero + 1; // Incrementador: Novo número da OS.
    string data, categoria, servico;
    int prioridade;

    system("cls");// Limpa a tela. 
    cout << "\n-*-*- Abertura de OS -*-*-\n";
    cout << "Data de abertura (dd/mm/aaaa): ";
    getline(cin >> ws, data);
    cout << "Categoria do serviço: ";
    getline(cin, categoria);
    cout << "Descrição do serviço: ";
    getline(cin, servico);
    cout << "Prioridade (1 a 5): ";
    // Garantir que a entrada para prioridade seja um número inteiro válido
    while (!(cin >> prioridade) || prioridade < 1 || prioridade > 5)
    {
        cout << "Prioridade inválida! Por favor, digite um número de 1 a 5: ";
        cin.clear();                                         // Limpa o estado de erro do cin (caso o usuário tenha digitado texto)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada inválida do buffer
    }

    // Cria um novo objeto OS com 17 parâmetros.
    Os novaOs(
        numero,
        data,
        categoria,
        servico,
        prioridade,
        "",        // Comentário do Técnico (vazio na abertura).
        0.0,       // Valor do Serviço (0.0 na abertura).
        "",        // Data de fechamento
        false,     // Conclusão
        getId(),   // ID do morador
        getNome(), // Nome morador
        "",        // Comentário do Morador
        0,         // Nota de Avaliação 
        false,     // Avaliada 
        0,         // idTecnicoResponsavel
        "N/A",     // nomeTecnicoResponsavel
        false);    // Atribuida

    system("cls");
    cout << "\nOS criada com sucesso!\n"; // Confirmação de criação

    listaOs.push_back(novaOs); // Adiciona a nova OS ao vetor de OS's.
    salvarEmJson(listaOs, "ordens.json"); // Salva a lista atualizada no arquivo JSON.

    cout << "OS aberta com sucesso!\n"
        << endl;
    return &listaOs.back(); // Retorna um ponteiro para a OS recém-adicionada.
}

// Método para deletar uma OS específica.
void Morador::VisualizarMeusChamados(const std::vector<Os> &listaOs) const
{
    cout << "\n-*-*- Chamados do Morador " << getNome() << " -*-*-\n";
    cout << "----------------------------------------\n";

    bool temChamados = false;

    // Itera sobre cada OS na lista.
    for (const Os &os : listaOs)
    {
        // Verifica se a OS foi criada por este morador, comparando os IDs:
        if (os.getIdMoradorCriador() == getId())
        {
            temChamados = true;
            // Exibir os detalhes da classe Os para o Morador:
            os.exibiriDetalhesMorador();
            cout << "----------------------------------------\n";
        }
    }

    if (!temChamados) // Se nenhum chamado foi encontrado para este morador.
    {
        system("cls");
        cout << "Você não tem nenhum chamado aberto ou registrado. \n";
    }
    cout << "\n";
}

// Método para deletar uma OS específica.
void Morador::deletarChamado(int osId, std::vector<Os> &listaOs)
{

    bool removido = false;

    // Itera sobre o vetor usando um iterador:
    for (auto elemento = listaOs.begin(); elemento != listaOs.end();)
    {   
        // Verifica se o número da OS corresponde e se o morador logado é o criador da OS.
        if (elemento->getNumeroOs() == osId && elemento->getIdMoradorCriador() == getId())
        {
            if (!elemento->isConcluida()) // Só pode deletar se a OS não estiver concluída.
            {
                elemento = listaOs.erase(elemento); // Remove o elemento do vetor.
                cout << "Chamado OS #" << osId << " deletado com sucesso.\n";
                removido = true;
            }
            else
            {
                cout << "O chamado OS #" << osId << " já foi concluído e não pode ser deletado. \n";
                ++elemento; // Incremente apenas se não apagar
            }

            break;
        }
        else
        {
            ++elemento; // Incremente o iterador se não for o elemento a ser apagado
        }
    }
}

// Método para avaliar um serviço.
void Morador::AvaliarServico(int osId, std::vector<Os> &listaOs, Tecnico &tecnico)
{
    cout << "\n-*-*- Avaliar Serviço (OS #" << osId << ") -*-*-\n";

    Os *osParaAvaliar = nullptr;

    // Encontrar a OS no vetor:
    for (size_t i = 0; i < listaOs.size(); i++)
    {
        if (listaOs[i].getNumeroOs() == osId)
        {
            osParaAvaliar = &listaOs[i]; // Atribui o endereço da OS encontrada.
            break;
        }
    }

    // Verifica se a OS foi encontrada.
    if (osParaAvaliar == nullptr)
    {
        cout << "OS com número " << osId << " não foi encontrada.\n";
        aguardarEnter();
        return;
    }

    // Verifica se a OS deve estar concluída para ser avaliada.
    if (!osParaAvaliar->isConcluida())
    {
        cout << "A OS #" << osId << " ainda não foi concluída pelo técnico." << endl;
        aguardarEnter();
        return;
    }

    // Verifica se a OS não deve ter sido avaliada ainda.
    if (osParaAvaliar->isAvaliada())
    {
        cout << "A OS #" << osId << " já foi avaliada por você. Sua avaliação: "
            << osParaAvaliar->getNotaAvaliacao() << "/5 - Comentário: "
            << osParaAvaliar->getComentarioMorador() << endl;
        aguardarEnter();
        return;
    }

    // Capturar comentário do Morador.
    string comentario_morador;
    cout << "OS encontrada. Serviço: " << osParaAvaliar->getServico() << endl;
    cout << "Deixe um comentário sobre o serviço: ";
    getline(cin, comentario_morador);

    // Capturar nota do Morador.
    int nota;
    cout << "Dê uma nota (1 a 5): ";
    while (!(cin >> nota) || nota < 1 || nota > 5)
    {
        cout << "Nota inválida! Digite um número de 1 a 5: ";
        cin.clear();                                         // Limpa o estado de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
    }

    // Atualizar a OS.
    osParaAvaliar->setAvaliacao(comentario_morador, nota);
    salvarEmJson(listaOs, "ordens.json");

    if (osParaAvaliar->getIdTecnicoResponsavel() == tecnico.getId())
    {
        tecnico.atualizarNotaMedia();
        system("cls");
        cout << "\nOS #" << osId << " avaliada com sucesso!" << endl;
        cout << "Nota média atual do técnico "
            << tecnico.getNome()
            << ": " << tecnico.getNota() << " / 5" << endl;
    }
    else
    {
        cout << "\nOS #" << osId << " avaliada com sucesso!" << endl;
        cout << "Técnico responsável: " << osParaAvaliar->getNomeTecnicoResponsavel() << endl;
    }

    cout << "Pressione ENTER para continuar...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa o buffer
    cin.get();
}

// Método para verificar o status de inadimplência do morador.
bool Morador::VerificarInadiplencia() const
{
    return inadiplente;
}

// Método para exibir informações detalhadas do morador (sobrescrevendo displayInfo de Pessoa).
void Morador::displayInfo() const
{
    cout << "MORADOR\n";
    Pessoa::displayInfo();
    cout << "Apartamento: " << apartamento << endl;
    cout << "Classe: " << classeApartamento << endl;
    cout << "Inadimplente: " << (inadiplente ? "Sim" : "Não") << endl;
}
