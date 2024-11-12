#ifndef ESTUDANTE_H
#define ESTUDANTE_H


class Estudante : public Pessoa
{
    public:
        Estudante();
        virtual ~Estudante();

    protected:

    private:
        const int max_libros = 10;
        const bool recebe_desconto = true;
};

#endif // ESTUDANTE_H
