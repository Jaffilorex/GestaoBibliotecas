#include "LivroFiccao.h"

LivroFiccao::LivroFiccao(int _id, string _titulo, string _autor, int _num_pags)
{
    id = _id;
    titulo = _titulo;
    autor = _autor;
    num_pags = _num_pags;
}

LivroFiccao::~LivroFiccao()
{
    //dtor
}

LivroFiccao::tipo()
{
    return "Ficcao";
}
