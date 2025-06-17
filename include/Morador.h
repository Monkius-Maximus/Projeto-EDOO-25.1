#ifndef MORADOR_H
#define MORADOR_H

#include "Pessoa.h"
#include <string>
using std::string;

class Morador : public Pessoa
{
private:
    string apartamento;
    char classeApartamento;
    bool inadiplente;

public:
    Morador(); // Construtor padrão
    Morador (int id, const string &nome, const string &email, const string &apartamento, char classeApartamento, bool inadiplente);
    // Os* AbrirChamado(string categoria, string servico, string comentario, int prioridade);
    void VisualizarMeusChamados() const;
    void CancelarChamado(int osId);
    void AvaliarServico(int osId, int comentario);
    void CancelarChamado(int osId);
    void AvaliarServico(int osId, int comentario);
    bool VerificarInadiplencia() const;
};

#endif
