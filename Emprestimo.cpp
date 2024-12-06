#include "Emprestimo.h"

int Emprestimo::ultimoID = 0;

Emprestimo::Emprestimo(Pessoa* _leitor, Geral* _livro, time_t prazo)
{
    id = ++ultimoID;
    leitor = _leitor;
    livro = _livro;
    livro->emprestar();
    devolvido = false;
    prazo_devolucao = prazo;
    auto now = std::chrono::system_clock::now();
    data_emprestimo = chrono::system_clock::to_time_t(now);
}

Emprestimo::~Emprestimo()
{
    //dtor
}

time_t Emprestimo::getPrazoDevolucao() const
{
    return prazo_devolucao;
}

int Emprestimo::getDiasAtraso()
{
    return dias_atraso;
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
    cout << "\tLeitor: " << leitor->getNome() << endl;
    cout << "\tLivro: " << livro->getTitulo() << endl;
    tm* prazo_tm = localtime(&prazo_devolucao);
    cout << "\tPrazo de devolucao: " << put_time(prazo_tm, "%d-%m-%Y %H:%M:%S") << "\n";
    if(devolvido) cout << "\tDias de atraso: " << dias_atraso << endl;
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

Geral* Emprestimo::getLivro()
{
    return livro;
}

int Emprestimo::getID()
{
    return id;
}

bool Emprestimo::isOverdue()
{
    time_t now = time(0); // Tiempo atual
    double seconds_since_loan = difftime(now, data_emprestimo);
    int days_since_loan = seconds_since_loan / (60 * 60 * 24); // Convert seconds to days
    return (days_since_loan > prazo_devolucao);
}
