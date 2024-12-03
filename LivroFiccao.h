#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include <Geral.h>
#include <string>
#include <iostream>

using namespace std;


class LivroFiccao : public Geral
{
    public:
        LivroFiccao();
        LivroFiccao(int, string, string, int, string);
        virtual ~LivroFiccao();
        string getTipo() override;
        void Show() override;
        void editarInformacoes() override;

    protected:

    private:
        const string tipo = "Ficcao";
        string tema;
};

#endif // LIVROFICCAO_H
