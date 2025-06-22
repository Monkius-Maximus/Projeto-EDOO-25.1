#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa
{
private:
    int id;
    string nome;
    string email;

public:
    Pessoa(); // Construtor padrão
    Pessoa(int id, const string &nome, const string &email); // Construtor

    virtual void displayInfo() const; // Puramente virtual para garantir o Polimorfismo 

    // Getters:
    int getId() const {return id; }
    string getNome() const {return nome;}
    string getEmail() const {return email;}

    // Setters:
    void setId(int novoId) {
        if (novoId > 0)
        {
            id = novoId;
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
            cout << "Erro: Email do usuário inválido";
        }
        
    }

    // Criar um destrutor para classe (pensar com calma)
};


#endif
