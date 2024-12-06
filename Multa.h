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
        double calcularValor() const;
        void Show(ostream& os) const;
        friend ostream& operator<<(std::ostream& os, const Pessoa& pessoa);

    protected:

    private:
        int dias_atraso;
        Pessoa* leitor;
};

#endif // MULTA_H
