#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include <Pessoa.h>


class LeitorComum : public Pessoa
{
    public:
        LeitorComum(int, string);
        virtual ~LeitorComum();

    protected:

    private:
        static const int MAX_LIVROS_EMPRESTADOS = 3;
        static const double DESCONTO_MULTA = 0;

};

#endif // LEITORCOMUM_H
