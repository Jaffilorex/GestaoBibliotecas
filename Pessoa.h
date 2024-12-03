#ifndef PESSOA_H
#define PESSOA_H

using namespace std;

#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Pessoa
{
    public:
        Pessoa();
        Pessoa(int id, string nome);
        virtual ~Pessoa();
        void Show();
        virtual string tipo() = 0;
        int getLivrosEmprestados();
        virtual double getMultasPendentes() = 0; // Metodo polimorfico
        virtual void edit_informacoes() = 0; // Metodo polimorfico
        virtual int getPrazoDevolucao(string tipo_livro) = 0; // Metodo polimorfico
        virtual double getDescontoMulta() = 0; // Metodo polimorfico
        virtual int getLimiteReservas() = 0;
        virtual int getPrioridadeReserva(string tipo_livro) = 0;
        int getID();
        string getNome();
        void registrarEmprestimo(string tipo_livro, string titulo);
        void exibirHistorico();
        virtual bool canExtendLoan() = 0;
        virtual void sendNotification() = 0;

    protected:

        int id;
        string nome;
        double desconto_multa;

        // Histórico: tipo do livro -> lista de títulos
        map<string, vector<string>> historicoEmprestimos;

    private:
        int livros_emprestados;
        int max_livros_emprestados;
};


#endif // PESSOA_H
