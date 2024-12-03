#ifndef JORNAL_H
#define JORNAL_H

#include "Geral.h"
#include <string>
#include <iostream>

using namespace std;


class Jornal : public Geral
{
    public:
        Jornal();
        Jornal(int, string, string, int, string);
        virtual ~Jornal();
        string getTipo() override;
        void Show() override;
        void editarInformacoes() override;

    protected:

    private:
        const string tipo = "Jornal";
        string data_publicacao;
};

#endif // JORNAL_H
