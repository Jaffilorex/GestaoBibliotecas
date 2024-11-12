#include "Emprestimo.h"

Emprestimo::Emprestimo(Pessoa _p, Livro _l)
{
    leitor = _p;
    livro = _l;
    data_emprestimo = time(nullptr);
    data_devolucao = time(nullptr);
}

Emprestimo::~Emprestimo()
{
    //dtor
}
