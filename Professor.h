#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <Pessoa.h>


class Professor : public Pessoa
{
    public:
        Professor();
        Professor(int id, string nome, string _asig);
        virtual ~Professor();
        int getPrazoDevolucao(string tipo_livro) override;
        double getDescontoMulta();
        int getLimiteReservas(); // Metodo polimorfico
        int getPrioridadeReserva(string tipo_livro); // Metodo polimorfico
        string tipo() const override;
        bool canExtendLoan() override;
        void sendNotification() override;
        double getMultasPendentes() override;
        void edit_informacoes() override;
        void Show(ostream& os) const override;
        friend istream& operator>>(istream& is, Professor& professor);
        string formatoArchivo() const override;

    protected:

    private:
        int max_libros = 15;
        double calcularMultasProfessor();
        string asignatura;
};

#endif // PROFESSOR_H
