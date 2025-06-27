#include "../include/Morador.h"
#include "../include/Persistencia.h"

#include <iostream>
#include <string>
#include <limits>

using namespace std;

Morador::Morador()

:Pessoa()
{
    apartamento = "N/A";
    classeApartamento = 'N';
    inadiplente = false;
};

Morador::Morador(
    int id,
    const string &nome,
    const string &email,
    const string &apartamento,
    char classeApartamento,
    bool inadiplente
)

:Pessoa(
    id,
    nome,
    email
)

{
    this->apartamento = apartamento;
    this-> classeApartamento = classeApartamento;
    this->inadiplente = inadiplente;
};

// Getters:
string Morador::getApartamento() const {return apartamento;}
char Morador::getClasseApartamento() const {return classeApartamento;}
bool Morador::getInadiplente() const {return inadiplente;}

// Setter:
void Morador::setApartamento(string &novoApartamento){
    if(!novoApartamento.empty()){
        apartamento = novoApartamento;
    }
    else {
        cout << "Erro: Apartamento não pode ser vázio!" << endl;
    }
};

void Morador::setClasseApartamento(char novaClasseAp){
    if(novaClasseAp == 'A' || novaClasseAp == 'B' || novaClasseAp == 'C' || novaClasseAp == 'D'){
        classeApartamento = novaClasseAp;
    }
    else {
        cout << "Erro: Classe de apartamento inválida!" << endl;
    }
};
void Morador::setInadiplente(bool status) {
    inadiplente = status;
}

// Métodos da classe:
Os* Morador::AbrirChamado(vector<Os>& listaOs){
    if(VerificarInadiplencia()){
        cout << "Olá, " << getNome() << " você está inadiplente e não poderá abrir chamados.\n";
        return nullptr;
    }

    int numero = listaOs.size() + 1;
    string data, categoria, servico;
    int prioridade;

    cout << "\n-*-*- Abertura de OS -*-*-\n";
    cout << "Data de abertura (dd/mm/aaaa): ";
    getline(cin >> ws, data);
    cout << "Categoria do serviço: ";
    getline(cin, categoria);
    cout << "Descrição do serviço: ";
    getline(cin, servico);
    cout << "Prioridade (1 a 5): ";
    // Garantir que a entrada para prioridade seja um número inteiro válido
    while (!(cin >> prioridade))
    {
        cout << "Entrada inválida. Por favor, digite um número para a prioridade (1 a 5): ";
        cin.clear();
    }
    
    Os novaOs(
        numero,
        data,
        categoria,
        servico,
        prioridade,
        "",    // Comentário
        0.0,   // Valor
        "",    // Data de fechamento
        false,  // Conclusão
        getId(), // ID do morador
        getNome(), // Nome morador
        "",
        0,
        false,
        0,
        "N/A",
        false
    );
    
    listaOs.push_back(novaOs);
    salvarEmJson(listaOs, "ordens.json");
    
    cout << "OS aberta com sucesso!\n" << endl;
    return &listaOs.back();
    
}

void Morador::VisualizarMeusChamados() const {
    cout << "\n-*-*- Chamados do Morador " << getNome() << " -*-*-\n";
    cout << "----------------------------------------\n";

    vector<Os> listaOs = carregarDoJson("ordens.json");

    bool temChamados = false;
    for (const Os& os : listaOs)
    {   
        // Verificar se a OS foi criada por qual morador usando o ID:
        if (os.getIdMoradorCriador() == getId()){
            temChamados = true;
            // Exibir os detalhes da classe Os:
            os.exibiriDetalhesMorador();
            cout << "----------------------------------------\n";
        }
        
    }

    if (!temChamados) {
        cout << "Você não tem nenhum chamado aberto ou registrado. \n";
    }
    cout << "\n";
    
}

void Morador::deletarChamado(int osId) {
    vector<Os> listaOs = carregarDoJson("ordens.json");

    bool removido = false;

    for(auto elemento = listaOs.begin(); elemento != listaOs.end(); elemento++){
        if (elemento->getNumeroOs() == osId && elemento->getIdMoradorCriador() == getId()) {
            if (!elemento->isConcluida()){
                listaOs.erase(elemento); //Remover os elementos de containers
                salvarEmJson(listaOs, "ordens.json");
                cout << "Chamado OS #" << osId << " deletado com sucesso.\n";
                removido = true;
            }else
            {
                cout << "O chamado OS #" << osId << " já foi concluído e não pode ser deletado. \n";
            }
            break;
        }
    }
}

void Morador::AvaliarServico(int osId){
    cout << "\n-*-*- Avaliar Serviço (OS #" << osId << ") -*-*-\n";
    
    vector<Os> listaOs = carregarDoJson("ordens.json");
    Os* osParaAvaliar = nullptr;

    for (size_t i = 0; i < listaOs.size(); i++){
        if(listaOs[i].getNumeroOs() == osId){
            osParaAvaliar = &listaOs[i];
            break;
        }
    }

    if(osParaAvaliar == nullptr){
        cout << "OS com número " << osId << " não foi encontrada.\n";
        return;
    }

    if(!osParaAvaliar->isConcluida()){
        cout << "A OS #"<< osId << " ainda não foi concluída pelo técnico." << endl;
        return;
    }

    if(osParaAvaliar->isAvaliada()){
        cout << "A OS #" << osId << " já foi avaliada por você. Sua avaliação: " << osParaAvaliar->getNotaAvaliacao() << " /5 - Comentário: " << osParaAvaliar->getComentarioMorador() << endl;
        return;
    }

    string comentario_morador;
    int nota;

    cout << "Os encontrada. Serviço: " << osParaAvaliar->getServico() << endl;
    cout << "Deixe um comenário sobre o serviço: ";
    // Limpar bo buffer antes do getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, comentario_morador);
    cout << "Dê uma nota (1 a 5): ";
    while (!(cin >> nota) || nota < 1 || nota > 5){
        cout << "Nota inválida! Digite um número de 1 a 5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    osParaAvaliar->setAvaliacao(comentario_morador, nota);
    
    salvarEmJson(listaOs, "ordens.json");

    cout << "OS #" << osId << " avaliada com sucesso!" << endl;
}

bool Morador::VerificarInadiplencia() const {
    return inadiplente;
}
