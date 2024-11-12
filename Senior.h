#ifndef SENIOR_H
#define SENIOR_H


class Senior : public Pessoa
{
    public:
        Senior();
        virtual ~Senior();

    protected:

    private:
        const int max_libros = 20;
        const bool recebe_desconto = true;
};

#endif // SENIOR_H
