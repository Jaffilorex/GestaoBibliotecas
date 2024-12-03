#ifndef GERAL_H
#define GERAL_H
#include <iostream>
#include <string>

using namespace std;

class Geral
{
    public:
        Geral(int, string, string, int);
        virtual ~Geral();
        //virtual string QuemEs() = 0;
        virtual void Show();
        virtual void editarInformacoes();
        string getTitulo();
        string getAutor();
        int getNumPags();
        int getID();
        void setNumPags(int n);
        virtual string getTipo() = 0;
    private:
        int id;
        string titulo;
        string autor;
        int num_pags;
    protected:
};

#endif // GERAL_H
