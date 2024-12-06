#ifndef SENIOR_H
#define SENIOR_H

#include "Pessoa.h"

class Senior : public Pessoa
{
    public:
        Senior();
        Senior(int id, string nome);
        virtual ~Senior();
        int getPrazoDevolucao(string tipo_livro) override;
        double getDescontoMulta();
        int getLimiteReservas(); // Metodo polimorfico
        int getPrioridadeReserva(string tipo_livro); // Metodo polimorfico
        string tipo() const override;
        void Show(ostream& os) const override;
        double getMultasPendentes() override;
        bool canExtendLoan() override;
        void sendNotification() override;
        void edit_informacoes() override;
        friend istream& operator>>(istream& is, Senior& senior);
        string formatoArchivo() const override;

    protected:

    private:
        int max_libros = 20;
        const bool recebe_desconto = true;
        double calcularMultasSenior();
};

#endif // SENIOR_H
