#include "Professor.h"

Professor::Professor() : Pessoa()
{
    id = 0;
    nome = "";
}

Professor::Professor(int _id, string _nome, string _asig) : Pessoa(_id, _nome)
{
    //ctor
    asignatura = _asig;
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

string Professor::tipo() const
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

void Professor::Show(ostream& os) const
{
    Pessoa::Show(os);
    os << tipo() << "\n";
}

istream& operator>>(istream& is, Professor& professor) {
    is >> static_cast<Pessoa&>(professor); // Llama al operador de entrada de Pessoa
    is >> professor.max_libros;        // Lee el atributo específico de Professor
    return is;
}

string Professor::formatoArchivo() const
{
    return "P " + Pessoa::formatoArchivo();
}
