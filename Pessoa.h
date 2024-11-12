#ifndef PESSOA_H
#define PESSOA_H


class Pessoa
{
    public:
        Pessoa(int, string);
        virtual ~Pessoa();
        void fazerLeitor();
        void removerLeitor();
        virtual void tipo();
        int getLivrosEmprestados();

    protected:

    private:
        bool e_leitor;
        string nome;
        int id;
        int livros_emprestados;
        virtual int max_livros_emprestados;
        virtual double desconto_multa;
};


#endif // PESSOA_H
