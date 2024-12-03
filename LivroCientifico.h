#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include "Geral.h"
#include <string>
#include <iostream>

using namespace std;

class LivroCientifico : public Geral
{
    public:
        LivroCientifico();
        LivroCientifico(int, string, string, int, string);
        virtual ~LivroCientifico();
        string getTipo() override;
        void Show() override;
        void editarInformacoes() override;
    protected:

    private:
        const string tipo = "Cientifico";
        string area;
};

#endif // LIVROCIENTIFICO_H
