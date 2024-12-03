#include "Geral.h"

Geral::Geral(int _id, string _titulo, string _autor, int _num_pags)
{
    id = _id;
    titulo = _titulo;
    autor = _autor;
    num_pags = _num_pags;
}

Geral::~Geral()
{
    //dtor
}

int Geral::getID()
{
    return id;
}

string Geral::getTitulo()
{
    return titulo;
}

string Geral::getAutor()
{
    return autor;
}


int Geral::getNumPags()
{
    return num_pags;
}

void Geral::setNumPags(int n)
{
    num_pags = n;
}

void Geral::Show()
{
    cout << "ID del livro: " << getID() << endl;
    cout << "\tTitulo: " << getTitulo() << ".Autor: " << getAutor() << ".Num pags: " << getNumPags() << endl;
}

void Geral::editarInformacoes()
{
    cout << "Editando informacoes do livro..." << endl;
    cout << "Titulo atual: " << getTitulo() << ".\nNovo titulo:" << endl;
    getline(cin, titulo);

    cout << "Autor atual: " << getAutor() << ".\nNovo autor:" << endl;
    getline(cin, autor);

    int num;
    string temp;

    cout << "Num pags atual: " << getNumPags() << ".\nNovo num pags:" << endl;
    getline(cin, temp);

    num = stoi(temp);
    setNumPags(num);
}
