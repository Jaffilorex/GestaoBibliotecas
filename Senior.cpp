#include "Senior.h"

Senior::Senior()
{
    id = 0;
    nome = "";
}

Senior::Senior(int _id, string _nome) : Pessoa(_id, _nome)
{
    //ctor
}

Senior::~Senior()
{
    //dtor
}
/*
double Senior::calcularMultasSenior()
{
    // Poner codigo
}

double Senior::getMultasPendentes()
{
    Senior::calcularMultasSenior();
}
*/
int Senior::getPrazoDevolucao(string tipo_livro)
{
    return 10;
}

double Senior::getDescontoMulta()
{
    return 0.15;
}

int Senior::getLimiteReservas()
{
    return 4;
}

int Senior::getPrioridadeReserva(string tipo_livro)
{
    return 3;
}

string Senior::tipo()
{
    return "Senior";
}
