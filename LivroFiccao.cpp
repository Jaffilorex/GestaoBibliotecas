#include "LivroFiccao.h"

LivroFiccao::LivroFiccao()
{
    id = 0;
    titulo = "";
    autor = "";
    num_pags = 0;
    tema = "";
}

LivroFiccao::LivroFiccao(int _id, string _titulo, string _autor, int _num_pags, string _tema) : Geral(_id, _titulo, _autor, _num_pags)
{
    tema = _tema;
}

LivroFiccao::~LivroFiccao()
{
    //dtor
}

string LivroFiccao::getTipo()
{
    return tipo;
}

void LivroFiccao::Show()
{
    Geral::Show();
    cout << "Tipo: " << LivroFiccao::getTipo() << endl;
}

void LivroFiccao::editarInformacoes()
{
    Geral::editarInformacoes();
    cout << "Tema atual: " << tema << ".\nNovo tema: ";
    getline(cin, tema);
}
