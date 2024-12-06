#ifndef RESERVA_H
#define RESERVA_H

#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "Pessoa.h"

using namespace std;


class Reserva
{
    public:
        Reserva(string livro);
        virtual ~Reserva();
        bool adicionarReserva(shared_ptr<Pessoa> leitor, string tipo_livro);
        void mostrarFilaReservas();

    protected:

    private:
        string livro;
        vector<pair<shared_ptr<Pessoa>, int>> fila_reservas; // (leitor, prioridade)
        int contarReservas(shared_ptr<Pessoa> leitor);
};

#endif // RESERVA_H
