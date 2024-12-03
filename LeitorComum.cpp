#include "LeitorComum.h"

LeitorComum::LeitorComum()
{
    id = 0;
    nome = "";
}

LeitorComum::LeitorComum(int _id, string _nome) : Pessoa(_id, _nome)
{

}

LeitorComum::~LeitorComum()
{
    //dtor
}

int LeitorComum::getPrazoDevolucao(string tipo_livro)
{
    return 7;
}

double LeitorComum::getDescontoMulta()
{
    return 0.0; // Sem desconto
}

int LeitorComum::getLimiteReservas()
{
    return 3;
}

int LeitorComum::getPrioridadeReserva(string tipo_livro)
{
    return 3;
}

string LeitorComum::tipo()
{
    return "Leitor Comum";
}

bool LeitorComum::canExtendLoan()
{
    return false; // Leitores Comumes nao podem extender Emprestimo
}

void LeitorComum::sendNotification()
{
    cout << "Dear " << nome << ":" << endl;
    cout << "You have overdue loans. Please settle the fine as soon as possible to avoid further penalties" << endl;
}

double LeitorComum::getMultasPendentes()
{
    return calcularMultasLeitorComum();
}

double LeitorComum::calcularMultasLeitorComum()
{
    return 0.0;
}

void LeitorComum::edit_informacoes()
{
    cout << "Editing information for Leitor Comum:" << endl;
    cout << "Current max books allowed: " << max_libros << "\n";
    cout << "Enter new max books allowed: ";
    cin >> max_libros;
    cout << "Updated max books allowed to: " << max_libros << "\n";
}
