#include "Geral.h"

Geral::Geral(int _id, string _titulo, string _autor, int _num_pags)
{
    id = _id;
    titulo = _titulo;
    autor = _autor;
    num_pags = _num_pags;
}

Geral::~Geral()
{
    //dtor
}

Geral::get_titulo()
{
    return titulo;
}

Geral::get_num_pags()
{
    return autor;
}


Geral::get_num_pags()
{
    return num_pags;
}

Geral::Show()
{
    cout << "ID del livro: " << id << endl;
    cout << "\tTitulo: " << get_titulo() << ".Autor: " << autor << ".Num pags: " << get_num_pags() << endl;
}
