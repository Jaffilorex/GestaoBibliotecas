#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include <Geral.h>


class LivroFiccao : public Geral
{
    public:
        LivroFiccao(int, string, string, int);
        virtual ~LivroFiccao();
        string tipo();

    protected:

    private:
};

#endif // LIVROFICCAO_H
