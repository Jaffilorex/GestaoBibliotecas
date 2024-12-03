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
        string getTipo() override;
        void Show() override;
        void editarInformacoes() override;
        void setNumEdicao(int n);

    protected:

    private:
        const string tipo = "Revista";
        int num_edicao;
};

#endif // REVISTA_H
