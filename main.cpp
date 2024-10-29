// main.cpp
#include <iostream>
#include "Biblioteca.h"
#include "Livro.h"
#include "Leitor.h"

int main() {
    Biblioteca biblioteca;

    // Adding books to the library
    Livro* ficcao1 = new LivroFiccao("O Hobbit", "J.R.R. Tolkien", "Aventura");
    Livro* cientifico1 = new LivroCientifico("Uma Breve História do Tempo", "Stephen Hawking", "Física");

    biblioteca.adicionarLivro(ficcao1);
    biblioteca.adicionarLivro(cientifico1);

    // Registering readers
    Leitor* estudante1 = new Estudante("Alice", 20);
    Leitor* professor1 = new Professor("Dr. Silva", 45);

    biblioteca.registrarLeitor(estudante1);
    biblioteca.registrarLeitor(professor1);

    // Performing a loan
    biblioteca.realizarEmprestimo(estudante1, ficcao1);

    // Checking fines
    std::cout << "Verificando multas...\n";
    biblioteca.verificarMultas();

    return 0;
}

