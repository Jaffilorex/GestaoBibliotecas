#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
using namespace std;
#include <list>
#include <map>
#include "Pessoa.h"
#include "Geral.h"

class Biblioteca
{
   // list, vector, map Coleccao_LIVROS;
   // list, vector, map Coleccao_REQ;
    public:
        Biblioteca();
        virtual ~Biblioteca();
        bool SaveToFile(string nf);
        bool LoadFile(string nf);
        void RelatorioCategoria(string cat);
        void Prorrogacao_Emprestimos();
        void Sistema_Notificacoes_Atraso();
        void Listagem_Livros();
        bool Add_Leitores(vector _leitores);
        bool Add_Leitor(Pessoa *P);

    private:
        vector<Geral*> livros;
        vector<Leitor*> leitores;
        vector<Emprestimo*> emprestimos;

};

#endif // BIBLIOTECA_H
