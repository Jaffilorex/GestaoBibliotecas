#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <Pessoa.h>


class Professor : public Pessoa
{
    public:
        Professor();
        Professor(int id, string nome);
        virtual ~Professor();
        int getPrazoDevolucao(string tipo_livro) override;
        double getDescontoMulta();
        int getLimiteReservas(); // Metodo polimorfico
        int getPrioridadeReserva(string tipo_livro); // Metodo polimorfico
        string tipo() override;
        bool canExtendLoan() override;
        void sendNotification() override;
        double getMultasPendentes() override;
        void edit_informacoes() override;

    protected:

    private:
        int max_libros = 15;
        double calcularMultasProfessor();
};

#endif // PROFESSOR_H
