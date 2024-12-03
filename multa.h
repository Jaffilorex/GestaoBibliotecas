#ifndef MULTA_H
#define MULTA_H

#include <typeinfo>
#include <iostream>

#include "Pessoa.h"
#include "Estudante.h"
#include "Professor.h"

class Multa
{
    public:
        Multa(int, Pessoa*);
        virtual ~Multa();
        double calcularValor();
        void Show();

    protected:

    private:
        int dias_atraso;
        Pessoa* leitor;
};

#endif // MULTA_H
