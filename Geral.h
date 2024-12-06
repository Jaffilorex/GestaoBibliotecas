#ifndef GERAL_H
#define GERAL_H
#include <iostream>
#include <string>
#include <vector>
#include "Pessoa.h"

using namespace std;

class Geral
{
    public:
        Geral();
        Geral(int, string, string, int);
        virtual ~Geral();
        virtual void Show(ostream& os) const;
        virtual void editarInformacoes();
        string getTitulo() const;
        string getAutor() const;
        int getNumPags() const;
        int getID() const;
        void setID(int n);
        void setTitulo(string t);
        void setAutor(string a);
        void setNumPags(int n);
        virtual string getTipo() const;
        friend ostream& operator<<(ostream& os, const Geral& geral);
        friend istream& operator>>(istream& is, Geral& geral);
        bool isEmprestado();
        void setEmprestado(bool e);
        void emprestar();
        const vector<Pessoa*>& getReservas() const;
        void addReserva(Pessoa* p);
        virtual string formatoArchivo() const;
    private:
        bool emprestado;
        vector<Pessoa*> reservas; // Lista de reservas

    protected:
        int id;
        string titulo;
        string autor;
        int num_pags;
};

#endif // GERAL_H
