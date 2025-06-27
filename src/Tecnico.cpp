#include "../include/Tecnico.h"
#include "../include/Persistencia.h"

#include <iostream>
#include <limits>
#include "Tecnico.h"

using namespace std;

Tecnico::Tecnico()

:Pessoa()
{
    especialidade = "N/A";
    disponibilidade = false;
    nota = 0.0;
};

Tecnico::Tecnico(
    int numeroOs,
    const string &nome,
    const string &email, 
    const string &especialidade, 
    bool disponibilidade, 
    double nota
)

:Pessoa(
    numeroOs, 
    nome, 
    email
)

{
    this->especialidade = especialidade;
    this->disponibilidade = disponibilidade; 
    this->nota = nota; 
};

// Getters:
string Tecnico::getEspecialidade() const {return especialidade;}
bool Tecnico::getDisponibilidade() const {return disponibilidade;}
double Tecnico::getNota() const {return nota;}

// Setter:
void Tecnico::setEspecialidade(const string &novaEspecialidade){
    if(!novaEspecialidade.empty()){
        especialidade = novaEspecialidade;
    } else {
        cout << "Erro: Especialidade não pode ser vázia" << endl;
    }
};
void Tecnico::setDisponibilidade(bool status){
    disponibilidade = status;
};
void Tecnico::setNota(double novaNota){
    if(novaNota >= 0.0 && novaNota <= 5.0){
        nota = novaNota;
    }else{
        cout << "Erro: Nota inválida. A nota deve estar entre 0.0 e 5.0" << endl;
    }
}

// Métodos da classe:
void Tecnico::VisualizarChamadosDisponiveis() const{
    cout << "\n-*-*- Chamados Disponíveis para o Técnico " << getNome() << " -*-*-\n";

    vector<Os> listaOs = carregarDoJson("ordens.json");

    bool temChamadoDisponiveis = false;
    for(const Os& os : listaOs){
        if(!os.isConcluida()){
            temChamadoDisponiveis = true;
            os.exibirDetalhesTecnico();
            cout << "----------------------------------------\n";
        }
    }

    if(!temChamadoDisponiveis){
        cout << "Não há chamados disponíveis no momento\n.";
    }
    cout << "\n";
}

void Tecnico::AceitarChamado(int osId){
    cout << "\n-*-*- Aceitar Chamado (OS #" << osId << ") -*-*-\n";

    if(!getDisponibilidade()){
        cout << "Você não está disponível para aceitar chamados no momento.\n";
        return;
    }

    vector<Os> listaOs = carregarDoJson("ordens.json");
    Os* osParaAceitar = nullptr;

    for(size_t i = 0; i < listaOs.size(); i++){
        if(listaOs[i].getNumeroOs() == osId){
            osParaAceitar = &listaOs[i];
            break;
        }
    }

    if(osParaAceitar->isConcluida()){
        cout << "A OS #" << osId << " já foi concluída e não pode ser aceita.\n";
        return;
    }

    if(osParaAceitar->isAtribuida()){
        cout << "A OS #" << osId << " já foi atribuída ao técnico " << osParaAceitar->getNomeTecnicoResponsavel() << "(ID: " << osParaAceitar->getIdTecnicoResponsavel() << ").\n";
        return;
    }

    if(osParaAceitar->getCategoria() != getEspecialidade()){
        cout << "Esta OS não corresponde à sua especialidade (" << getEspecialidade() << ").\n";
        cout << "Categoria da OS: " << osParaAceitar->getCategoria() << endl;
        return;
    }

    osParaAceitar->setAtribuicao(getId(), getNome());
    salvarEmJson(listaOs, "ordens.json");

    cout << "OS #" << osId << " aceita com sucesso por " << getNome() << "!\n";
    cout << "Agora você é o técnico responsável por esta OS.\n";
}

void Tecnico::FecharChamado(vector<Os>& listaOs) {
    int numeroOs;
    cout << "\n-*-*- Fechamento de Chamado -*-*-\n";
    cout << "Digite o número da OS que deseja fechar: ";
    cin >> numeroOs;
    
    bool encontrada = false;

    for (auto& os : listaOs) {
        if (os.getNumeroOs() == numeroOs) {
            encontrada = true;
            cout << "\nOS encontrada. Dados atuais:\n";
            os.exibirDetalhesTecnico();
            cout << "\n";

            string comentarioTecnicoEntrada, dataFechamento;
            double valor;

            cout << "Comentário técnico: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, comentarioTecnicoEntrada);

            cout << "Valor do serviço: R$ ";
            cin >> valor;

            cout << "Data de fechamento (dd/mm/aaaa): ";
            cin.ignore();
            getline(cin, dataFechamento);

            os.setComentarioTecnico(comentarioTecnicoEntrada);
            os.setValor(valor);
            os.setDataFechamento(dataFechamento);
            os.setConclusao(true);

            cout << "\nOS fechada com sucesso!\n";
            salvarEmJson(listaOs, "ordens.json");
            break;
        }
    }

    if (!encontrada) {
        cout << "Nenhuma OS com esse número foi encontrada.\n";
    }
}

void Tecnico::VisualizarMeusChamadosAtribuidos() const{
    cout << "\n-*-*- Seus Chamados Atribuídos, " << getNome() << " -*-*-\n";

    vector<Os> listaOs = carregarDoJson("ordens.json");

    bool temChamadosAtribuidos = false;
    for(const Os& os : listaOs){
        if(os.isAtribuida() && os.getIdTecnicoResponsavel() == getId()){
            temChamadosAtribuidos = true;
            os.exibirDetalhesTecnico();
            cout << "----------------------------------------\n";
        }
    }

    if(!temChamadosAtribuidos){
        cout << "Você não tem nenhum chamado atribuído no momento.\n";
    }
    cout << "\n";
}
