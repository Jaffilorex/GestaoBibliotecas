#include "Multa.h"

Multa::Multa(int _dias_atraso, Pessoa* _l)
{
    dias_atraso = _dias_atraso;
    leitor = _l;
}

Multa::~Multa()
{
    //dtor
}

double Multa::calcularValor() const
{
    double taxa_base = 2.0;  // Base rate per day

    if (typeid(*leitor) == typeid(Estudante)) {
        auto estudante = dynamic_cast<Estudante*>(leitor);
        return dias_atraso * taxa_base * 0.5; // 50% discount for students
    } else if (typeid(*leitor) == typeid(Professor)) {
        auto professor = dynamic_cast<Professor*>(leitor);
        return dias_atraso * taxa_base * 0.7;  // 30% discount for professors
    } else {
        return dias_atraso * taxa_base;  // No discount for other readers
    }
}

void Multa::Show(ostream& os) const
{
    os << "Multa para ";
    leitor->Show(os);
    os << ": " << calcularValor() << " euros.\n";
}
