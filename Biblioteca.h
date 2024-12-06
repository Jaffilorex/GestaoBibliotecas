#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
using namespace std;
#include <list>
#include <map>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <ctime>    // time_t, time, localtime, strftime
#include <iomanip>  // put_time
#include <chrono>

#include "Pessoa.h"
#include "Geral.h"
#include "Emprestimo.h"

#include "LivroCientifico.h"
#include "LivroEducativo.h"
#include "LivroFiccao.h"
#include "Revista.h"
#include "Jornal.h"

#include "Professor.h"
#include "LeitorComum.h"
#include "Senior.h"
#include "Estudante.h"

#include "Multa.h"

class Biblioteca
{
   // list, vector, map Coleccao_LIVROS;
   // list, vector, map Coleccao_REQ;
    public:
        Biblioteca();
        virtual ~Biblioteca();
        bool SaveToFile(string nf);
        bool LoadFile(string nf);
        void RelatorioLivrosCategoria();
        void Sistema_Notificacoes_Atraso();
        void Listagem_Livros();
        void Listagem_Leitores();
        void Listagem_Emprestimos();
        bool Add_Leitores(vector<Pessoa*>* _leitores);
        bool Add_Leitor(Pessoa *P);
        void registrarLeitor();
        bool Add_Emprestimo(Emprestimo *E);
        bool Add_Livro(Geral *G);
        void registrarLivro();
        void RelatorioMultasPendentes();
        void EditarInformacoesLeitores(int ID_leitor);
        void EditarInformacoesLivros(int ID_livro);
        void ExtendLoanForReader(int ID_leitor);
        const vector<Geral*>& getLivros() const;  // Acceso de solo lectura
        const vector<Pessoa*>& getLeitores() const; // Acceso de solo lectura
        void realizarEmprestimo();
        Pessoa* buscarLeitor(int id);
        Geral* buscarLivro(int id);
        void reservarLivro(int id_livro, Pessoa* leitor);
        void devolverLivro(int id_livro, Pessoa* leitor);
        Emprestimo* getEmprestimoPorLivro(int id_livro);
        void listarEmprestimosPorTipo() const;


    private:
        vector<Geral*> livros;
        vector<Pessoa*> leitores;
        vector<Emprestimo*> emprestimos;

        void removerEmprestimo(Emprestimo* e);

};

#endif // BIBLIOTECA_H
