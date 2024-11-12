#ifndef MULTA_H
#define MULTA_H

#include "Pessoa.h"


class Multa
{
    public:
        Multa();
        virtual ~Multa();

    protected:

    private:
        int dias_atraso;
        Leitor *leitor;
};

#endif // MULTA_H
