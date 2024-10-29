// Leitor.h
#ifndef LEITOR_H
#define LEITOR_H

#include <string>
#include <vector>
#include "Livro.h"

class Leitor {
protected:
    std::string nome;
    int idade;
    std::vector<const Livro*> historico;

public:
    Leitor(const std::string& nome, int idade) : nome(nome), idade(idade) {}
    virtual ~Leitor() = default;
    virtual int emprestimoLimite() const = 0;

    void adicionarHistorico(const Livro* livro) {
        historico.push_back(livro);
    }

    virtual std::string detalhes() const {
        return "Nome: " + nome + ", Idade: " + std::to_string(idade);
    }
};

class Estudante : public Leitor {
public:
    Estudante(const std::string& nome, int idade) : Leitor(nome, idade) {}
    int emprestimoLimite() const override { return 5; }
    std::string detalhes() const override { return Leitor::detalhes() + " (Estudante, Limite: " + std::to_string(emprestimoLimite()) + " livros)"; }
};

class Professor : public Leitor {
public:
    Professor(const std::string& nome, int idade) : Leitor(nome, idade) {}
    int emprestimoLimite() const override { return 10; }
    std::string detalhes() const override { return Leitor::detalhes() + " (Professor, Limite: " + std::to_string(emprestimoLimite()) + " livros)"; }
};

#endif // LEITOR_H