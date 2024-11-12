#include "LivroEducativo.h"

LivroEducativo::LivroEducativo()
{
    //ctor
}

LivroEducativo::~LivroEducativo()
{
    //dtor
}

LivroEducativo::tipo()
{
    return "Educativo";
}

LivroEducativo::Show()
{
    Geral::Show();
    cout << "Grau Escolaridade: " << grau_escolaridade << endl;
}
