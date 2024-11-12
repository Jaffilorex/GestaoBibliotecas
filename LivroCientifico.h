#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include "Geral.h"


class LivroCientifico : public Geral
{
    public:
        LivroCientifico(int, string, string, int, string);
        virtual ~LivroCientifico();
        void Show();
        string tipo();
    protected:

    private:
        string area;
};

#endif // LIVROCIENTIFICO_H
