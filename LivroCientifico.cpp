#include "LivroCientifico.h"

LivroCientifico::LivroCientifico()
{
    id = 0;
    titulo = "";
    autor = "";
    num_pags = 0;
    area = "";
}

LivroCientifico::LivroCientifico(int _id, string _titulo, string _autor, int _num_pags, string _area) : Geral(_id, _titulo, _autor, _num_pags)
{
    area = _area;
}

LivroCientifico::~LivroCientifico()
{
    //dtor
}

void LivroCientifico::Show()
{
    Geral::Show();
    cout << "Area cientifica: " << area << endl;
}

string LivroCientifico::getTipo()
{
    return tipo;
}

void LivroCientifico::editarInformacoes()
{
    Geral::editarInformacoes();
    cout << "Area atual: " << area << ".\nNova area: ";
    getline(cin, area);
}
