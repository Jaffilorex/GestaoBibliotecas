#ifndef REVISTA_H
#define REVISTA_H

#include <Geral.h>


class Revista : public Geral
{
    public:
        Revista(int, string, string, int, int);
        virtual ~Revista();
        string tipo();
        void Show();

    protected:

    private:
        int num_edicao;
};

#endif // REVISTA_H
