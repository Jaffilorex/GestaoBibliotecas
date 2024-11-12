#ifndef JORNAL_H
#define JORNAL_H

#include <Geral.h>


class Jornal : public Geral
{
    public:
        Jornal(int, string, string, int, string);
        virtual ~Jornal();
        string tipo();
        void Show();

    protected:

    private:
        string data_publicacao;
};

#endif // JORNAL_H
