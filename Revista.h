#ifndef REVISTA_H
#define REVISTA_H

#include "Geral.h"
#include <string>
#include <iostream>

using namespace std;


class Revista : public Geral
{
    public:
        Revista();
        Revista(int _id, string _titulo, string _autor, int _num_pags, int _num_edicao);
        virtual ~Revista();
        string getTipo() const override;
        void Show(ostream& os) const override;
        void editarInformacoes() override;
        void setNumEdicao(int n);
        friend istream& operator>>(istream& is, Revista& livro);
        string formatoArchivo() const override;

    protected:

    private:
        const string tipo = "Revista";
        int num_edicao;
};

#endif // REVISTA_H
