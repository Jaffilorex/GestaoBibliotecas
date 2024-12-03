#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

using namespace std;

#include "Pessoa.h"
#include "Geral.h"
#include <ctime>


class Emprestimo
{
    public:
        Emprestimo(Pessoa* _leitor, Geral* _livro, time_t data_emprestimo);
        virtual ~Emprestimo();
        void mostrarDetalhes();
        void registrarDevolucao(int diasEmPosse);
        double calcularMulta(double valor_base_dia);
        bool extendLoan();
        Pessoa* getLeitor();
        bool isOverdue();

    protected:

    private:
        Geral* livro;
        Pessoa* leitor;
        int prazo_devolucao;
        bool devolvido;
        int dias_atraso;
        time_t data_emprestimo;
};

#endif // EMPRESTIMO_H
