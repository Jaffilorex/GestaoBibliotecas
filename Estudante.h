#ifndef ESTUDANTE_H
#define ESTUDANTE_H


class Estudante : public Pessoa
{
    public:
        Estudante();
        virtual ~Estudante();

    protected:

    private:
        static const int MAX_LIVROS_EMPRESTADOS = 10;
        static const double DESCONTO_MULTA = 1.5;
};

#endif // ESTUDANTE_H
