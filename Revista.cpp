#include "Revista.h"

Revista::Revista()
{
    id = 0;
    titulo = "";
    autor = "";
    num_pags = 0;
    num_edicao = 0;
}

Revista::Revista(int _id, string _titulo, string _autor, int _num_pags, int _num_edicao) : Geral(_id, _titulo, _autor, _num_pags)
{
    //ctor
    num_edicao = _num_edicao;
}

Revista::~Revista()
{
    //dtor
}

string Revista::getTipo() const
{
    return tipo;
}

void Revista::Show(ostream& os) const
{
    Geral::Show(os);
    os << "Numero Edicao: " << num_edicao << "\n";
}

void Revista::setNumEdicao(int n)
{
    num_edicao = n;
}

void Revista::editarInformacoes()
{
    Geral::editarInformacoes();
    cout << "Num edicao atual: " << num_edicao << ".\nNovo num edicao: ";

    int n;
    string temp;
    getline(cin, temp);

    n = stoi(temp);
    setNumEdicao(n);
}

istream& operator>>(istream& is, Revista& livro) {
    is >> static_cast<Geral&>(livro); // Llama al operador de la clase base
    is >> livro.num_edicao;
    return is;
}

string Revista::formatoArchivo() const
{
    return "R " + Geral::formatoArchivo();
}
