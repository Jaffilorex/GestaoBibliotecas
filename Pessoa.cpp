#include "Pessoa.h"

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

void Pessoa::Show()
{
    cout << "Id: " << id << ". Nome: " << nome << endl;
}

int Pessoa::getLivrosEmprestados()
{
    return livros_emprestados;
}

int Pessoa::getID()
{
    return id;
}

string Pessoa::getNome()
{
    return nome;
}

// Adiciona um empréstimo ao histórico
void Pessoa::registrarEmprestimo(string tipo_livro, string titulo) {
    historicoEmprestimos[tipo_livro].push_back(titulo);
}

// Exibe o histórico de empréstimos
void Pessoa::exibirHistorico() {
    cout << "\nHistórico de Empréstimos de " << getNome() << " (" << tipo() << "):\n";
    for (auto& par : historicoEmprestimos) {
        auto tipo_livro = par.first;  // Clave
        auto& titulos = par.second;   // Valor

        cout << "- Tipo de Livro: " << tipo_livro << "\n";
        for (auto& titulo : titulos) {
            cout << "  * " << titulo << "\n";
        }
    }
}

