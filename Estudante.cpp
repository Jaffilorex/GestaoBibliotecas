#include "Estudante.h"

Estudante::Estudante()
{
    id = 0;
    nome = "";
}

Estudante::Estudante(int _id, string _nome) : Pessoa(_id, _nome)
{
    //ctor
}

Estudante::~Estudante()
{
    //dtor
}

int Estudante::getPrazoDevolucao(string tipo_livro)
{
    if(tipo_livro == "Educativo") return 15;
    return 10;
}

double Estudante::getDescontoMulta()
{
    return 0.1;
}

int Estudante::getLimiteReservas()
{
    return 5;
}

int Estudante::getPrioridadeReserva(string tipo_livro)
{
    if(tipo_livro == "Educativo") return 1; // Alta prioridade para livros educativos
    return 2;
}

string Estudante::tipo()
{
    return "Estudante";
}

bool Estudante::canExtendLoan()
{
    return true;
}

double Estudante::getMultasPendentes()
{
    return calcularMultasEstudante();
}

double Estudante::calcularMultasEstudante()
{
    return 0.0;
}

void Estudante::edit_informacoes()
{
    cout << "Editing information for Estudante\n";
    cout << "Current max books allowed: " << max_libros << "\n";
    cout << "Enter new max books allowed: ";
    cin >> max_libros;
    cout << "Updated max books allowed to: " << max_libros << "\n";
}
