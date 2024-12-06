#include "Estudante.h"

Estudante::Estudante() : Pessoa()
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

string Estudante::tipo() const
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

void Estudante::sendNotification()
{
    cout << "Dear Estudante" << nome << ":\n";
    cout << "You have overdue loans. Remember you are eligible for a fine discount of " << desconto_multa * 100 << "%.\n";
    cout << "You may also request an extension for your loans" << endl;
}


void Estudante::Show(ostream& os) const
{
    Pessoa::Show(os);
    os << tipo() << "\n";
}

istream& operator>>(istream& is, Estudante& estudante) {
    is >> static_cast<Pessoa&>(estudante); // Llama al operador de entrada de Pessoa
    is >> estudante.max_libros;        // Lee el atributo específico de Estudante
    return is;
}

string Estudante::formatoArchivo() const
{
    return "E " + Pessoa::formatoArchivo();
}
