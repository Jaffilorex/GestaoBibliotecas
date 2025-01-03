#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include "Pessoa.h"
#include <string>
#include <iostream>

using namespace std;

class LeitorComum : public Pessoa
{
    public:
        LeitorComum();
        LeitorComum(int id, string nome);
        virtual ~LeitorComum();
        int getPrazoDevolucao(string tipo_livro);
        double getDescontoMulta(); // Metodo polimorfico
        int getLimiteReservas(); // Metodo polimorfico
        int getPrioridadeReserva(string tipo_livro); // Metodo polimorfico
        string tipo() const override;
        bool canExtendLoan() override;
        void sendNotification() override;
        double getMultasPendentes() override;
        void edit_informacoes() override;
        void Show(ostream& os) const override;
        friend istream& operator>>(istream& is, LeitorComum& leitor_comum);
        string formatoArchivo() const override;

    protected:

    private:
        int max_libros = 3;
        double calcularMultasLeitorComum();
};

#endif // LEITORCOMUM_H
