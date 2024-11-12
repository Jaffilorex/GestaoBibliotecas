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
    private:
        string get_titulo();
        string get_autor();
        int get_num_pags();
    protected:
        int id;
        string titulo;
        string autor;
        int num_pags;
};

#endif // GERAL_H
