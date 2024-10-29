// Emprestimo.h (modified)
#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Leitor.h"
#include "Livro.h"
#include <ctime>

class Emprestimo {
private:
    Leitor* leitor;
    Livro* livro;
    std::time_t dataEmprestimo;
    std::time_t dataDevolucao;

public:
    Emprestimo(Leitor* leitor, Livro* livro)
        : leitor(leitor), livro(livro) {
        dataEmprestimo = std::time(nullptr);
        dataDevolucao = calcularDataDevolucao();
    }

    std::time_t calcularDataDevolucao() const {
        int diasEmprestimo = 14;
        if (dynamic_cast<Estudante*>(leitor) && dynamic_cast<LivroCientifico*>(livro)) {
            diasEmprestimo = 30;
        } else if (dynamic_cast<Professor*>(leitor)) {
            diasEmprestimo = 45;
        }
        return dataEmprestimo + diasEmprestimo * 24 * 60 * 60;
    }

    int calcularDiasAtraso() const {
        std::time_t hoje = std::time(nullptr);
        int diasAtraso = static_cast<int>(difftime(hoje, dataDevolucao) / (60 * 60 * 24));
        return diasAtraso > 0 ? diasAtraso : 0;
    }

    Leitor* getLeitor() const { return leitor; }
    Livro* getLivro() const { return livro; }
};

#endif // EMPRESTIMO_H