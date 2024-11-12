#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_H

#include "Geral.h"


class LivroEducativo
{
    public:
        LivroEducativo();
        virtual ~LivroEducativo();
        string tipo();
        void Show();

    protected:

    private:
        int grau_escolaridade;
};

#endif // LIVROEDUCATIVO_H
