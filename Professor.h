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
        const int max_libros = 15;
        const bool recebe_desconto = true;
};

#endif // PROFESSOR_H
