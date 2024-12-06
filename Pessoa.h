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
        virtual void Show(ostream& os) const;
        virtual string tipo() const;
        int getLivrosEmprestados();
        virtual double getMultasPendentes() = 0; // Metodo polimorfico
        virtual void edit_informacoes() = 0; // Metodo polimorfico
        virtual int getPrazoDevolucao(string tipo_livro) = 0; // Metodo polimorfico
        virtual double getDescontoMulta() = 0; // Metodo polimorfico
        virtual int getLimiteReservas() = 0;
        virtual int getPrioridadeReserva(string tipo_livro) = 0;
        int getID() const;
        string getNome() const;
        void setID(int n);
        void setNome(string n);
        void registrarEmprestimo(string tipo_livro, string titulo);
        void registrarMulta(double v);
        void exibirHistorico();
        virtual bool canExtendLoan() = 0;
        virtual void sendNotification() = 0;
        // Declaración del operador << como amigo para permitir el acceso a los atributos privados
        friend ostream& operator<<(std::ostream& os, const Pessoa& pessoa);
        friend istream& operator>>(istream& is, Pessoa& pessoa);
        virtual string formatoArchivo() const;

    protected:

        int id;
        string nome;
        double desconto_multa;

        // Histórico: tipo do livro -> lista de títulos
        map<string, vector<string>> historicoEmprestimos;
        vector<double> multas_pendentes;

    private:
        int livros_emprestados;
        int max_livros_emprestados;
};


#endif // PESSOA_H
