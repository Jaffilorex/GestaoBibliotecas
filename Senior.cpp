#include "Senior.h"

Senior::Senior() : Pessoa()
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

double Senior::calcularMultasSenior()
{
    // Poner codigo
    return 0.0;
}

double Senior::getMultasPendentes()
{
    Senior::calcularMultasSenior();
}

void Senior::edit_informacoes()
{
    cout << "Editing information for Senior\n";
    cout << "Current max books allowed: " << max_libros << "\n";
    cout << "Enter new max books allowed: ";
    cin >> max_libros;
    cout << "Updated max books allowed to: " << max_libros << "\n";
}

bool Senior::canExtendLoan()
{
    return true;
}

void Senior::sendNotification()
{
    cout << "Dear Senior" << nome << ":\n";
    cout << "You have overdue loans. Remember you are eligible for a fine discount of " << desconto_multa * 100 << "%.\n";
    cout << "You may also request an extension for your loans" << endl;
}

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

string Senior::tipo() const
{
    return "Senior";
}

void Senior::Show(ostream& os) const
{
    Pessoa::Show(os);
    os << tipo() << "\n";
}

istream& operator>>(istream& is, Senior& senior) {
    is >> static_cast<Pessoa&>(senior); // Llama al operador de entrada de Pessoa
    is >> senior.max_libros;        // Lee el atributo específico de LeitorComum
    return is;
}

string Senior::formatoArchivo() const
{
    return "S " + Pessoa::formatoArchivo();
}
