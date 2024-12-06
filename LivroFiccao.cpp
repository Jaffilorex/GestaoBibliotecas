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

string LivroFiccao::getTipo() const
{
    return tipo;
}

void LivroFiccao::Show(ostream& os) const
{
    Geral::Show(os);
    os << "Tipo: " << LivroFiccao::getTipo() << "\n";
}

void LivroFiccao::editarInformacoes()
{
    Geral::editarInformacoes();
    cout << "Tema atual: " << tema << ".\nNovo tema: ";
    getline(cin, tema);
}

istream& operator>>(istream& is, LivroFiccao& livro) {
    is >> static_cast<Geral&>(livro); // Llama al operador de la clase base
    is >> livro.tema;             // Lee atributos específicos de LivroFiccao
    return is;
}

string LivroFiccao::formatoArchivo() const
{
    return "F " + Geral::formatoArchivo();
}
