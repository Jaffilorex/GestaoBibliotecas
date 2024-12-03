#include "Emprestimo.h"

Emprestimo::Emprestimo(Pessoa* _leitor, Geral* _livro, time_t _data_emprestimo)
{
    leitor = _leitor;
    livro = _livro;
    devolvido = false;
    dias_atraso = 0;
    prazo_devolucao = leitor->getPrazoDevolucao(tipo_livro);
    data_emprestimo = _data_emprestimo;
}

Emprestimo::~Emprestimo()
{
    //dtor
}

int Emprestimo::getDuracao()
{
    return prazo_devolucao;
}

void Emprestimo::registrarDevolucao(int diasEmPosse)
{
    devolvido = true;
    if(diasEmPosse > prazo_devolucao) dias_atraso = diasEmPosse - prazo_devolucao;
    else dias_atraso = 0;
}

double Emprestimo::calcularMulta(double valor_base_dia)
{
    if (!devolvido) {
        cout << "Livro nao foi devolvido" << endl;
        return 0.0;
    }

    double multa_total = valor_base_dia * dias_atraso;
    double desconto = leitor->getDescontoMulta();
    return multa_total * (1 - desconto); // Aplica o desconto
}

void Emprestimo::mostrarDetalhes()
{
    cout << "ID Leitor: " << leitor->getID() << endl;
    cout << "Leitor: " << leitor->getNome() << endl;
    cout << "Livro: " << livro->getTitulo() << endl;
    cout << "Prazo de Devolução: " << prazo_devolucao << " dias" << endl;
    if(devolvido) cout << "Dias de atraso: " << dias_atraso << endl;
    else cout << "Livro nao devolvido" << endl;
    cout << "Desconto em Multa: " << leitor->getDescontoMulta() * 100 << "%" << endl;
}

bool Emprestimo::extendLoan()
{
    if(leitor->canExtendLoan()) {
        prazo_devolucao += 7;
        cout << "Emprestimo extended for " << leitor->getNome() << ". Nova duracao: " << prazo_devolucao << endl;
        return true;
    }
    cout << "Emprestimo extension nao possivel " << leitor->getNome() << endl;
    return false;
}

Pessoa* Emprestimo::getLeitor()
{
    return leitor;
}

bool Emprestimo::isOverdue()
{
    time_t now = time(0); // Tiempo atual
    double seconds_since_loan = difftime(now, data_emprestimo);
    int days_since_loan = seconds_since_loan / (60 * 60 * 24); // Convert seconds to days
    return (days_since_loan > prazo_devolucao);
}
