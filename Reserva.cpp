#include "Reserva.h"

Reserva::Reserva(string _livro)
{
    //ctor
    livro = _livro;
}

Reserva::~Reserva()
{
    //dtor
}

bool Reserva::adicionarReserva(shared_ptr<Pessoa> leitor, string tipo_livro)
{
    // Verificar se o leitor já atingiu o limite de reservas
    if (contarReservas(leitor) >= leitor->getLimiteReservas()) {
        cout << "Leitor " << leitor->getNome() << " atingiu o limite de reservas.\n";
        return false;
    }

    // Adicionar o leitor à fila com sua prioridade
    int prioridade = leitor->getPrioridadeReserva(tipo_livro);
    fila_reservas.emplace_back(leitor, prioridade);

    // Ordenar a fila com base na prioridade (menor valor = maior prioridade)
    sort(fila_reservas.begin(), fila_reservas.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    cout << "Leitor " << leitor->getNome() << " adicionou reserva para o livro '" << tipo_livro << "'.\n";
    return true;
}

void Reserva::mostrarFilaReservas() {
    cout << "Fila de reservas para o livro '" << livro << "':\n";
    /*for (auto [leitor, prioridade] : fila_reservas) {
        cout << " - " << leitor->getNome() << " (Prioridade: " << prioridade << ")\n";
    }*/
    for(auto f : fila_reservas) {
        shared_ptr<Pessoa> l = f.first;
        int p = f.second;
        cout << " - " << l->getNome() << " (Prioridade: " << p << ")\n";
    }
}

int Reserva::contarReservas(shared_ptr<Pessoa> leitor) {
    int count = 0;
    for(auto reserva : fila_reservas) {
        if(reserva.first == leitor) {
            count++;
        }
    }
    return count;
}
