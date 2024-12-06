#include "Geral.h"

Geral::Geral()
{
    id = 0;
    titulo = "";
    autor = "";
    num_pags = 0;
    emprestado = false;
}

Geral::Geral(int _id, string _titulo, string _autor, int _num_pags)
{
    id = _id;
    titulo = _titulo;
    autor = _autor;
    num_pags = _num_pags;
    emprestado = false;
}

Geral::~Geral()
{
    //dtor
}

string Geral::getTipo() const {
    return "Geral";
}

int Geral::getID() const
{
    return id;
}

string Geral::getTitulo() const
{
    return titulo;
}

string Geral::getAutor() const
{
    return autor;
}


int Geral::getNumPags() const
{
    return num_pags;
}

void Geral::setID(int n)
{
    id = n;
}

void Geral::setTitulo(string t)
{
    titulo = t;
}

void Geral::setAutor(string a)
{
    autor = a;
}

void Geral::setNumPags(int n)
{
    num_pags = n;
}

bool Geral::isEmprestado()
{
    return emprestado;
}

void Geral::setEmprestado(bool e)
{
    emprestado = e;
}

void Geral::emprestar()
{
    emprestado = true;
}

void Geral::Show(ostream& os) const
{
    os << "ID del livro: " << getID() << "\tTitulo: " << getTitulo() << ".Autor: " << getAutor() << ".Num pags: " << getNumPags() << endl;
}

void Geral::editarInformacoes()
{
    cout << "Editando informacoes do livro..." << endl;
    cout << "Titulo atual: " << getTitulo() << ".\nNovo titulo:" << endl;
    getline(cin >> ws, titulo);

    cout << "Autor atual: " << getAutor() << ".\nNovo autor:" << endl;
    getline(cin >> ws, autor);

    int num;
    string temp;

    cout << "Num pags atual: " << getNumPags() << ".\nNovo num pags:" << endl;
    getline(cin, temp);

    num = stoi(temp);
    setNumPags(num);
}

// Sobrecarga del operador <<
ostream& operator<<(std::ostream& os, const Geral& geral) {
    geral.Show(os);  // Llama a un método virtual
    return os;
}

// Sobrecarga del operador >>
istream& operator>>(istream& is, Geral& geral) {
    is >> geral.id >> geral.titulo >> geral.autor >> geral.num_pags;
    return is;
}

const vector<Pessoa*>& Geral::getReservas() const
{
    return reservas;
}

void Geral::addReserva(Pessoa* p)
{
    reservas.push_back(p);
}

string Geral::formatoArchivo() const {
    return to_string(getID()) + "\t" + getTitulo() + "\t" + getAutor() + "\t" + to_string(getNumPags());
}
