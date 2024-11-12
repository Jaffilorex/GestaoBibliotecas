#ifndef SENIOR_H
#define SENIOR_H


class Senior : public Pessoa
{
    public:
        Senior();
        virtual ~Senior();

    protected:

    private:
        static const int MAX_LIVROS_EMPRESTADOS = 20;
        static const double DESCONTO_MULTA = 7.25;
};

#endif // SENIOR_H
