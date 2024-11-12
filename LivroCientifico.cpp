#include "LivroCientifico.h"

LivroCientifico::LivroCientifico(int _id, string _titulo, string _autor, int _num_pags, string _area)
{
    id = _id;
    titulo = _titulo;
    autor = _autor;
    num_pags = _num_pags;
    area = _area;
}

LivroCientifico::~LivroCientifico()
{
    //dtor
}

LivroCientifico::Show()
{
    Geral::Show();
    cout << "Area cientifica: " << area << endl;
}

LivroCientifico::tipo()
{
    return "Cientifico";
}
