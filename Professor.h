#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <Pessoa.h>


class Professor : public Pessoa
{
    public:
        Professor();
        virtual ~Professor();

    protected:

    private:
        static const int MAX_LIVROS_EMPRESTADOS = 15;
        static const double DESCONTO_MULTA = 3.5;
};

#endif // PROFESSOR_H
