#include "Revista.h"

Revista::Revista(int _id, string _titulo, string _autor, int _num_pags, int _num_edicao)
{
    //ctor
    id = _id;
    titulo = _titulo;
    autor = _autor;
    num_pags = _num_pags;
    num_edicao = _num_edicao
}

Revista::~Revista()
{
    //dtor
}

Revista::tipo()
{
    return "Revista";
}

Revista::Show()
{
    Geral::Show();
    cout << "Numero Edicao: " << num_edicao << endl;
}
