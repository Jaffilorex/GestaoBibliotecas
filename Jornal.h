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
        string getTipo() const override;
        void Show(ostream& os) const override;
        void editarInformacoes() override;
        friend istream& operator>>(istream& is, Jornal& livro);
        string formatoArchivo() const override;

    protected:

    private:
        const string tipo = "Jornal";
        string data_publicacao;
};

#endif // JORNAL_H
