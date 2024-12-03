#include "Jornal.h"

Jornal::Jornal()
{
    id = 0;
    titulo = "";
    autor = "";
    num_pags = 0;
    data_publicacao = "";
}

Jornal::Jornal(int _id, string _titulo, string _autor, int _num_pags, string _data_publicacao) : Geral(_id, _titulo, _autor, _num_pags)
{
    data_publicacao = _data_publicacao;
}

Jornal::~Jornal()
{
    //dtor
}

string Jornal::getTipo()
{
    return tipo;
}

void Jornal::Show()
{
    Geral::Show();
    cout << "Data Publicacao: " << data_publicacao << endl;
}

void Jornal::editarInformacoes()
{
    Geral::editarInformacoes();
    cout << "Data publicacao atual: " << data_publicacao << ".\nNova data publicacao: ";
    getline(cin, data_publicacao);
}
