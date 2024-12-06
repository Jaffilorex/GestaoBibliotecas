#include "LivroEducativo.h"

LivroEducativo::LivroEducativo()
{
    id = 0;
    titulo = "";
    autor = "";
    num_pags = 0;
    grau_escolaridade = 0;
}

LivroEducativo::LivroEducativo(int _id, string _titulo, string _autor, int _num_pags, int _grau_escolaridade) : Geral(_id, _titulo, _autor, _num_pags)
{
    //ctor
    grau_escolaridade = _grau_escolaridade;
}

LivroEducativo::~LivroEducativo()
{
    //dtor
}

string LivroEducativo::getTipo() const
{
    return tipo;
}

void LivroEducativo::Show(ostream& os) const
{
    Geral::Show(os);
    os << "Grau Escolaridade: " << grau_escolaridade << "\n";
}

void LivroEducativo::setGrauEscolaridade(int n)
{
    grau_escolaridade = n;
}

void LivroEducativo::editarInformacoes()
{
    Geral::editarInformacoes();
    cout << "Grau escolaridade atual: " << grau_escolaridade << ".\nNovo grau escolaridade: ";

    int n;
    string temp;
    getline(cin, temp);

    n = stoi(temp);
    setGrauEscolaridade(n);
}

istream& operator>>(istream& is, LivroEducativo& livro) {
    is >> static_cast<Geral&>(livro); // Llama al operador de la clase base
    is >> livro.grau_escolaridade;
    return is;
}

string LivroEducativo::formatoArchivo() const
{
    return "E " + Geral::formatoArchivo();
}
