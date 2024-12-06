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

void LivroCientifico::Show(ostream& os) const
{
    Geral::Show(os);
    os << "Area cientifica: " << area << "\n";
}

string LivroCientifico::getTipo() const
{
    return tipo;
}

void LivroCientifico::editarInformacoes()
{
    Geral::editarInformacoes();
    cout << "Area atual: " << area << ".\nNova area: ";
    getline(cin, area);
}

istream& operator>>(istream& is, LivroCientifico& livro) {
    is >> static_cast<Geral&>(livro); // Llama al operador de la clase base
    is >> livro.area;
    return is;
}

string LivroCientifico::formatoArchivo() const
{
    return "C " + Geral::formatoArchivo();
}
