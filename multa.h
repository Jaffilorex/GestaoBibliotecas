// Multa.h
#ifndef MULTA_H
#define MULTA_H

#include <iostream>
#include "Leitor.h"

class Multa {
private:
    int diasAtraso;
    Leitor* leitor;

public:
    Multa(int diasAtraso, Leitor* leitor) : diasAtraso(diasAtraso), leitor(leitor) {}

    double calcularValor() const {
        double taxaBase = 2.0;  // Base rate per day

        if (auto estudante = dynamic_cast<Estudante*>(leitor)) {
            return diasAtraso * taxaBase * 0.5;  // 50% discount for students
        } else if (auto professor = dynamic_cast<Professor*>(leitor)) {
            return diasAtraso * taxaBase * 0.7;  // 30% discount for professors
        } else {
            return diasAtraso * taxaBase;  // No discount for other readers
        }
    }

    void mostrarMulta() const {
        std::cout << "Multa para " << leitor->detalhes()
                  << ": " << calcularValor() << " unidades.\n";
    }
};

#endif // MULTA_H