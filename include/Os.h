#ifndef OS_H
#define OS_H

#include <string>
using std::string;

class Os
{
private:
    string categoria;
    string servico;
    double valor;
    int prioridade;
    string comentario;
    string dataAbertura;
    string dataFechamento;
    bool conclusao;

public:
    Os(); // Inicializar como construtor padrão vazio;
    Os(const string &categoria, const string &servico, const double &valor, int prioridade, const string &comentario, const string &dataAbertura, const string &dataFechamento, bool conclusao);

};

#endif
