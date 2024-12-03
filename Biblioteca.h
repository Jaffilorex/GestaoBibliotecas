#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
using namespace std;
#include <list>
#include <map>
#include <vector>
#include <typeinfo>
#include <fstream>
#include "Pessoa.h"
#include "Geral.h"
#include "Emprestimo.h"
#include "LivroCientifico.h"
#include "LivroFiccao.h"
#include "Revista.h"
#include "Jornal.h"

class Biblioteca
{
   // list, vector, map Coleccao_LIVROS;
   // list, vector, map Coleccao_REQ;
    public:
        Biblioteca();
        virtual ~Biblioteca();
        bool SaveToFile(string nf);
        bool LoadFile(string nf);
        void RelatorioLivrosCategoria(string cat);
        void Prorrogacao_Emprestimos();
        void Sistema_Notificacoes_Atraso();
        void Listagem_Livros();
        bool Add_Leitores(vector<Pessoa*>* _leitores);
        bool Add_Leitor(Pessoa *P);
        bool Add_Emprestimo(Emprestimo *E);
        bool Add_Livro(Geral *G);
        void RelatorioMultasPendentes();
        void EditarInformacoesLeitores(int ID_leitor);
        void ExtendLoanForReader(int ID_leitor);

    private:
        vector<Geral*> livros;
        vector<Pessoa*> leitores;
        vector<Emprestimo*> emprestimos;

};

#endif // BIBLIOTECA_H
