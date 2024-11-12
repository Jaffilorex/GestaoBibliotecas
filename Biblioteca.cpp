#include "Biblioteca.h"

Biblioteca::Biblioteca()
{
    //ctor
}

Biblioteca::~Biblioteca()
{
    //dtor
    for (auto livro : livros) delete livro;
    for (auto leitor : leitores) delete leitor;
    for (auto emprestimo : emprestimos) delete emprestimo;
}

bool Biblioteca::SaveToFile(string nf)
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
    return true;
}

bool Biblioteca::LoadFile(string nf)
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
    return true;
}
void Biblioteca::RelatorioCategoria(string cat)
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
}
void Biblioteca::Prorrogacao_Emprestimos()
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
}
void Biblioteca::Sistema_Notificacoes_Atraso()
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
}
void Biblioteca::Listagem_Livros()
{
    for(auto liv : livros) liv.Show();
}
bool Biblioteca::Add_Leitores(vector _leitores)
{
    for(auto l : _leitores) leitores.push_back(l);
    return true;
}
bool Biblioteca::Add_Leitor(Pessoa *P)
{
    leitores.push_back(P);
    return true;
}
