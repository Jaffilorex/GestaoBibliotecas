// Biblioteca.h (modified)
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include "Livro.h"
#include "Leitor.h"
#include "Emprestimo.h"
#include "Multa.h"

class Biblioteca {
private:
    std::vector<Livro*> livros;
    std::vector<Leitor*> leitores;
    std::vector<Emprestimo*> emprestimos;

public:
    ~Biblioteca() {
        for (auto livro : livros) delete livro;
        for (auto leitor : leitores) delete leitor;
        for (auto emprestimo : emprestimos) delete emprestimo;
    }

    void adicionarLivro(Livro* livro) {
        livros.push_back(livro);
    }

    void registrarLeitor(Leitor* leitor) {
        leitores.push_back(leitor);
    }

    void realizarEmprestimo(Leitor* leitor, Livro* livro) {
        Emprestimo* novoEmprestimo = new Emprestimo(leitor, livro);
        emprestimos.push_back(novoEmprestimo);
        leitor->adicionarHistorico(livro);
    }

    void verificarMultas() const {
        for (auto emprestimo : emprestimos) {
            int diasAtraso = emprestimo->calcularDiasAtraso();
            if (diasAtraso > 0) {
                Multa multa(diasAtraso, emprestimo->getLeitor());
                multa.mostrarMulta();
            }
        }
    }
};

#endif // BIBLIOTECA_H