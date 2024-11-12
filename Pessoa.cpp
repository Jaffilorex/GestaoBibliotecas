#include "Pessoa.h"

Pessoa::Pessoa(int _id, string _nome)
{
    //ctor
    e_leitor = true; // Por defeto, é true
    id = _id;
    nome = _nome;
}

Pessoa::~Pessoa()
{
    //dtor
}

Pessoa::fazerLeitor()
{
    e_leitor = true;
}

Pessoa::removerLeitor()
{
    e_leitor = false;
}

Pessoa::getLivrosEmprestados()
{
    return livros_emprestados;
}
