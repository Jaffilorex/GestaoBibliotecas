#include "Jornal.h"

Jornal::Jornal(int _id, string _titulo, string _autor, int _num_pags, string _data_publicacao)
{
    id = _id;
    titulo = _titulo;
    autor = _autor;
    num_pags = _num_pags;
    data_publicacao = _data_publicacao;
}

Jornal::~Jornal()
{
    //dtor
}

Jornal::tipo()
{
    return "Jornal";
}

Jornal::Show()
{
    Geral::Show();
    cout << "Data Publicacao: " << data_publicacao << endl;
}
