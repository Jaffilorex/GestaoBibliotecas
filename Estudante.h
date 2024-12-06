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
        string tipo() const override;
        bool canExtendLoan() override;
        void sendNotification() override;
        double getMultasPendentes() override;
        void edit_informacoes() override;
        void Show(ostream& os) const override;
        friend istream& operator>>(istream& is, Estudante& estudante);
        string formatoArchivo() const override;

    protected:

    private:
        int max_libros = 10;
        double calcularMultasEstudante();
};

#endif // ESTUDANTE_H
