// Livro.h
#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <iostream>

class Livro {
protected:
    std::string titulo;
    std::string autor;

public:
    Livro(const std::string& titulo, const std::string& autor) : titulo(titulo), autor(autor) {}
    virtual ~Livro() = default;
    virtual std::string detalhes() const = 0;  // Pure virtual function for polymorphism
};

class LivroFiccao : public Livro {
private:
    std::string genero;

public:
    LivroFiccao(const std::string& titulo, const std::string& autor, const std::string& genero)
        : Livro(titulo, autor), genero(genero) {}

    std::string detalhes() const override {
        return "Ficção: " + titulo + " por " + autor + ", Gênero: " + genero;
    }
};

class LivroCientifico : public Livro {
private:
    std::string area;

public:
    LivroCientifico(const std::string& titulo, const std::string& autor, const std::string& area)
        : Livro(titulo, autor), area(area) {}

    std::string detalhes() const override {
        return "Científico: " + titulo + " por " + autor + ", Área: " + area;
    }
};

#endif // LIVRO_H