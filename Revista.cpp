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

string Revista::getTipo()
{
    return tipo;
}

void Revista::Show()
{
    Geral::Show();
    cout << "Numero Edicao: " << num_edicao << endl;
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
