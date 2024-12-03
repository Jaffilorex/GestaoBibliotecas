#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include "Pessoa.h"


class Estudante : public Pessoa
{
    public:
        Estudante();
        Estudante(int id, string nome);
        virtual ~Estudante();
        int getPrazoDevolucao(string tipo_livro);
        double getDescontoMulta();
        int getLimiteReservas(); // Metodo polimorfico
        int getPrioridadeReserva(string tipo_livro); // Metodo polimorfico
        string tipo() override;
        bool canExtendLoan() override;
        double getMultasPendentes() override;
        void edit_informacoes() override;

    protected:

    private:
        int max_libros = 10;
        double calcularMultasEstudante();
};

#endif // ESTUDANTE_H
