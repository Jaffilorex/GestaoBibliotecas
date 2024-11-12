#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

using namespace std;

#include "Pessoa.h"
#include "Livro.h"
#include <ctime>


class Emprestimo
{
    public:
        Emprestimo(Pessoa, Livro);
        virtual ~Emprestimo();

    protected:

    private:
        Pessoa *leitor;
        Livro * livro;
        time_t data_emprestimo;
        time_t data_devolucao;
};

#endif // EMPRESTIMO_H
