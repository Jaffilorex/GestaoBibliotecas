#include "Professor.h"

Professor::Professor()
{
    id = 0;
    nome = "";
}

Professor::Professor(int _id, string _nome) : Pessoa(_id, _nome)
{
    //ctor
}

Professor::~Professor()
{
    //dtor
}

double Professor::calcularMultasProfessor()
{
    return 0.0;
}

double Professor::getMultasPendentes()
{
    return calcularMultasProfessor();
}

int Professor::getPrazoDevolucao(string tipo_livro)
{
    if(tipo_livro == "Cientifico") return 30;
    return 14;
}

double Professor::getDescontoMulta()
{
    return 0.2;
}

int Professor::getLimiteReservas()
{
    return 7;
}

int Professor::getPrioridadeReserva(string tipo_livro)
{
    return 2; // Sem desconto
}

string Professor::tipo()
{
    return "Professor";
}

bool Professor::canExtendLoan()
{
    return true;
}

void Professor::sendNotification()
{
    cout << "Dear professor" << nome << ":\n";
    cout << "You have overdue loans. Remember you are eligible for a fine discount of " << desconto_multa * 100 << "%.\n";
    cout << "You may also request an extension for your loans" << endl;
}

void Professor::edit_informacoes()
{
    cout << "Editing information for Professor\n";
    cout << "Current max books allowed: " << max_libros << "\n";
    cout << "Enter new max books allowed: ";
    cin >> max_libros;
    cout << "Updated max books allowed to: " << max_libros << "\n";
}
