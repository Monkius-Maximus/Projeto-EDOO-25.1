#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Pessoa
{
    private:
        int idRegistro;
        string nome;
        string email;
        
    public:
        Pessoa(); // Construtor padrão
        Pessoa(
            int idRegistro,
            const string &nome,
            const string &email
        );
        
    virtual void displayInfo() const = 0; // Puramente virtual para garantir o Polimorfismo 

    // Getters:
    int getId() const {return idRegistro; }
    string getNome() const {return nome;}
    string getEmail() const {return email;}

    // Setters:
    void setId(int novoId) {
        if (novoId > 0)
        {
            idRegistro = novoId;
        }else {
            cout << "Erro: ID deve ser positivo!" << endl;
        }
    }

    void setNome(string &novoNome) {
            if (!novoNome.empty())
            {
                nome = novoNome;
            }else
            {
                cout <<"Erro: Nome do usuário não deve ser vázio!" << endl;
            }
        }

    void setEmail(string &novoEmail) {
        if (novoEmail.find('@'))
        {
            email = novoEmail;
        }else
        {
            cout << "Erro: E-mail do usuário inválido";
        }
    }

    virtual ~Pessoa() = default; // Destrutor virtual para garantir a destruição correta de objetos derivados
};

#endif
