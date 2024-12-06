#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

using namespace std;

#include "Pessoa.h"
#include "Geral.h"
#include <ctime>
#include <iomanip>  // put_time
#include <chrono>


class Emprestimo
{
    public:
        Emprestimo(Pessoa* _leitor, Geral* _livro, time_t prazo);
        virtual ~Emprestimo();
        void mostrarDetalhes();
        void registrarDevolucao(int diasEmPosse);
        double calcularMulta(double valor_base_dia);
        bool extendLoan();
        Pessoa* getLeitor();
        Geral* getLivro();
        bool isOverdue();
        int getID();
        int getDiasAtraso();
        time_t getPrazoDevolucao() const;

    protected:

    private:
        static int ultimoID; // Variable estática para rastrear el último ID asignado
        int id;              // ID único del empréstimo
        Geral* livro;
        Pessoa* leitor;
        time_t prazo_devolucao;
        bool devolvido;
        int dias_atraso;
        time_t data_emprestimo;
};

#endif // EMPRESTIMO_H
