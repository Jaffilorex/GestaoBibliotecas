#include "LeitorComum.h"

LeitorComum::LeitorComum(int _id, string _nome)
{
    id = _id;
    nome = _nome;
    desconto_multa = 0;
}

LeitorComum::~LeitorComum()
{
    //dtor
}
