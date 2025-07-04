#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Declaração da Classe Base 'Pessoa';
class Pessoa
{
private:
    int idRegistro; // Atributo: Identificador único para cada pessoa (morador ou técnico).
    string nome; // Atributo: Nome da Pessoa.
    string email; // Atributo: Endereço de e-mail da pessoa.

public:
    Pessoa(); // Construtor padrão: Criar um objeto 'Pessoa' sem incializar com os atributos padrões.
    Pessoa( // Construtor com parâmetros:
        int idRegistro, // Parâmeto: ID de registro.
        const string &nome, // Parâmeto: `&` para criar uma cópia na mémoria do nome da pessoa
        const string &email); // Parâmeto: `&` para criar uma cópia na mémoria do email da pessoa

    virtual void displayInfo() const = 0; // Método vitural Puro. Garantindo o Polimorfismo: um ponteiro ou referência de 'Pessoa' pode ser chamado.
                                          // A classe 'Pessoa' se torna uma classe abstrata e não pode ser instanciada diretamente.
                                          // Classes derivadas (como Morador, Tecnico) SÃO OBRIGADAS a implementar este método.
    
    // --- Getters ---
    int getId() const { return idRegistro; } // Retorna o ID, utilizando método inline.
    string getNome() const { return nome; } // Retorna o Nome, utilizando método inline.
    string getEmail() const { return email; } // Retorna o Email, utilizando método inline.

    // --- Setters ---
    void setId(int novoId) // Define um novo ID para a pessoa:
    {
        if (novoId > 0) // Verifica se o número é positivo.
        {
            idRegistro = novoId; // Atribui o novo ID.
        }
        else
        {
            cout << "Erro: ID deve ser positivo!" << endl; // Mesangem de erro se o ID for negativo.
        }
    }

    void setNome(string &novoNome) //Define um novo nome para a pessoa.
    {
        if (!novoNome.empty()) // Verifica se não é uma string vázia.
        {
            nome = novoNome; //Atibui o novo nome.
        }
        else
        {
            cout << "Erro: Nome do usuário não deve ser vázio!" << endl; // Mensagem de erro caso contrário.
        }
    }

    void setEmail(string &novoEmail) // Define um novo email para a pessoa.
    {
        if (novoEmail.find('@')) // Verifica se o '@' existe na string.
        {
            email = novoEmail; // Atribui novo email.
        }
        else
        {
            cout << "Erro: E-mail do usuário inválido"; // Caso contrário envia uma mensagem de erro.
        }
    }

    virtual ~Pessoa() = default; // Destrutor virtual para garantir a destruição correta de objetos derivados,
};

#endif
