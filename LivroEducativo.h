#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_H

#include "Geral.h"
#include <string>
#include <iostream>

using namespace std;

class LivroEducativo : public Geral
{
    public:
        LivroEducativo();
        LivroEducativo(int id, string titulo, string autor, int num_pags, int grau_escolaridade);
        virtual ~LivroEducativo();
        string getTipo() override;
        void Show() override;
        void editarInformacoes() override;
        void setGrauEscolaridade(int n);

    protected:

    private:
        const string tipo = "Educativo";
        int grau_escolaridade;
};

#endif // LIVROEDUCATIVO_H
