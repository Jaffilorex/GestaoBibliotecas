#include "Pessoa.h"

Pessoa::Pessoa()
{
    id = 0;
    nome = "";
}

Pessoa::Pessoa(int _id, string _nome)
{
    //ctor
    id = _id;
    nome = _nome;
}

Pessoa::~Pessoa()
{
    //dtor
}

string Pessoa::tipo() const {
    return "Pessoa";
}

void Pessoa::Show(ostream& os) const
{
    os << "Id: " << id << ". Nome: " << nome << endl;
}

int Pessoa::getLivrosEmprestados()
{
    return livros_emprestados;
}

int Pessoa::getID() const
{
    return id;
}

string Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setID(int n)
{
    id = n;
}

void Pessoa::setNome(string n)
{
    nome = n;
}

// Adiciona um empr�stimo ao hist�rico
void Pessoa::registrarEmprestimo(string tipo_livro, string titulo) {
    historicoEmprestimos[tipo_livro].push_back(titulo);
}

void Pessoa::registrarMulta(double v)
{
    multas_pendentes.push_back(v);
}

// Exibe o hist�rico de empr�stimos
void Pessoa::exibirHistorico() {
    cout << "\nHist�rico de Empr�stimos de " << getNome() << " (" << tipo() << "):\n";
    for (auto& par : historicoEmprestimos) {
        auto tipo_livro = par.first;  // Clave
        auto& titulos = par.second;   // Valor

        cout << "- Tipo de Livro: " << tipo_livro << "\n";
        for (auto& titulo : titulos) {
            cout << "  * " << titulo << "\n";
        }
    }
}

ostream& operator<<(std::ostream& os, const Pessoa& pessoa) {
    pessoa.Show(os);  // Llama al m�todo Show de la clase base
    return os;
}

istream& operator>>(istream& is, Pessoa& pessoa) {
    is >> pessoa.id >> pessoa.nome >> pessoa.desconto_multa;
    return is;
}

string Pessoa::formatoArchivo() const {
    return to_string(getID()) + "\t" + getNome();
}
