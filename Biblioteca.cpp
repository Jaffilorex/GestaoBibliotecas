#include "Biblioteca.h"

Biblioteca::Biblioteca()
{
    //ctor
}

Biblioteca::~Biblioteca()
{
    //dtor
    for (auto livro : livros) delete livro;
    for (auto leitor : leitores) delete leitor;
    for (auto emprestimo : emprestimos) delete emprestimo;

    livros.clear();
    leitores.clear();
    emprestimos.clear();
}

bool Biblioteca::SaveToFile(string nf)
{
    ofstream file(nf);
    if(!file.is_open()) {
        cerr << "Error ao abrir o arquivo a salvar!" << endl;
        return false;
    }

    // Save books
    file << "LIVROS\n";
    for(auto* livro : livros) {
        if(typeid(*livro) == typeid(LivroFiccao)) file << "F " << *livro << "\n";
        else if (typeid(*livro) == typeid(LivroCientifico)) file << "C " << *livro << "\n";
        else if (typeid(*livro) == typeid(LivroEducativo)) file << "E " << *livro << "\n";
        else if (typeid(*livro) == typeid(Revista)) file << "R " << *livro << "\n";
        else if (typeid(*livro) == typeid(Jornal)) file << "J " << *livro << "\n";
    }

    // Save readers
    file << "LEITORES\n";
    for (auto* leitor : leitores) {
        if (typeid(*leitor) == typeid(Professor)) file << "P " << *leitor << "\n";
        else if (typeid(*leitor) == typeid(LeitorComum)) file << "C " << *leitor << "\n";
        else if (typeid(*leitor) == typeid(Senior)) file << "S " << *leitor << "\n";
        else if (typeid(*leitor) == typeid(Estudante)) file << "E " << *leitor << "\n";
    }

    // Save loans
    file << "EMPRESTIMOS\n";
    for (auto* emprestimo : emprestimos) {
        file << emprestimo->getID() << " "
             << emprestimo->getLeitor()->getID() << " "
             << emprestimo->GetDuracao() << "\n";
    }

    file.close();
    return true;
}

bool Biblioteca::LoadFile(string nf)
{
    ifstream file(nf);
    if(!file.is_open()) {
        cerr << "Error ao abrir o arquivo para carregar!\n";
    }

    string section;
    while(file >> section) {
        if(section == "LIVROS") {
            char type;
            while(file >> type) {
                if(type == 'F') {
                    LivroFiccao* l = new LivroFiccao();
                    file >> *l;
                    Add_Livro(l);
                } else if (type == 'C') {
                    LivroCientifico* l = new LivroCientifico();
                    file >> *l;
                    Add_Livro(l);
                } else if (type == 'R') {
                    Revista* r = new Revista();
                    file >> *r;
                    Add_Livro(r);
                } else if (type == 'J') {
                    Jornal* j = new Jornal();
                    file >> *j;
                    Add_Livro(j);
                } else break;
            }
        } else if (section == "LEITORES") {
            char type;
            while(file >> type) {
                if(type == 'P') {
                    Professor* p = new Professor();
                    file >> *p;
                    Add_Leitor(p);
                } else if (type == 'C') {
                    LeitorComum* l = new LeitorComum();
                    file >> *l;
                    Add_Leitor(l);
                } else if (type == 'S') {
                    Senior* s = new Senior();
                    file >> *s;
                    Add_Leitor(s);
                } else if (type == 'E') {
                    Estudante* e = new Estudante();
                    file >> *e;
                    Add_Leitor(e);
                } else break;
            }
        } else if(section == "EMPRESTIMOS") {
            int livro_ID, leitor_ID, duracao;
            while(file >> livro_ID >> leitor_ID >> duracao) {
                Geral* livro = nullptr;
                Pessoa* leitor = nullptr;

                for (auto* l : livros) {
                    if(l->getID() == livro_ID) {
                        livro = l;
                        break;
                    }
                }

                for (auto* p : leitores) {
                    if(p->getID() == leitor_ID) {
                        leitor = p;
                        break;
                    }
                }

                if(livro && leitor) {
                    Emprestimo* e = new Emprestimo(leitor, livro, duracao);
                    Add_Emprestimo(e);
                }
            }
        }
    }
    file.close();
    return true;
}
void Biblioteca::RelatorioLivrosCategoria(string cat)
{
    cout << "Relatorio de livros por categoria: " << endl;

    // Livros cientificos
    cout << "Livros cientificos: " << endl;
    for(auto* livro : livros) {
        if(typeid(*livro) == typeid(LivroCientifico)) {
            livro->Show();
        }
    }

    // Livros ficcao
    cout << "Livros de ficcao: " << endl;
    for(auto* livro : livros) {
        if(typeid(*livro) == typeid(LivroFiccao)) {
            livro->Show();
        }
    }

    // Revistas
    cout << "Revistas: " << endl;
    for(auto* livro : livros) {
        if(typeid(*livro) == typeid(Revista)) {
            livro->Show();
        }
    }

    // Jornals
    cout << "Jornals: " << endl;
    for(auto* livro : livros) {
        if(typeid(*livro) == typeid(Jornal)) {
            livro->Show();
        }
    }
}
void Biblioteca::Prorrogacao_Emprestimos()
{
    cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
}
void Biblioteca::Sistema_Notificacoes_Atraso()
{
    cout << "Checking overdue loans: " << endl;

    for (Emprestimo* e : emprestimos) {
        if(e->isOverdue()) {
            Pessoa* leitor = e->getLeitor();
            cout << "Sending notificacion to: " << leitor->getNome() << endl;
            leitor->sendNotification();
        }
    }
}
void Biblioteca::Listagem_Livros()
{
    for(Geral* liv : livros) {
        liv->Show();
    }
}

bool Biblioteca::Add_Leitores(vector<Pessoa*>* _leitores)
{
    for(Pessoa* l : *_leitores) {
        leitores.push_back(l);
    }
    return true;
}

bool Biblioteca::Add_Leitor(Pessoa *P)
{
    leitores.push_back(P);
    return true;
}

bool Biblioteca::Add_Emprestimo(Emprestimo *E)
{
    emprestimos.push_back(E);
    return true;
}

bool Biblioteca::Add_Livro(Geral *G)
{
    livros.push_back(G);
    return true;
}

void Biblioteca::RelatorioMultasPendentes() {
    map<string, double> total_multas_por_tipo_leitor;

    for (Pessoa* leitor : leitores) {
        /*if (double multas = leitor->getMultasPendentes(); multas > 0) {  // Only include readers with outstanding fines
            cout << "Tipo leitor: " << leitor->tipo() << ", Multa/s pendente/s: " << multas << endl;
            total_multas_por_tipo_leitor[leitor->tipo()] += multas;
        }*/
        double multas_pendentes = leitor->getMultasPendentes();
        if(multas_pendentes > 0) {
            string tipo_leitor = leitor->tipo();
            total_multas_por_tipo_leitor[tipo_leitor] += multas_pendentes;

            cout << "Tipo leitor: " << tipo_leitor << ", Multa pendente: " << multas_pendentes << endl;
        }
    }

    // Display summary by reader type
    cout << "\nSummary of Pending Fines by Reader Type:\n";
    for (auto m : total_multas_por_tipo_leitor) {
        string tipo = m.first;
        double total = m.second;
        cout << "Tipo: " << tipo << ", Total: " << total << endl;
    }
}

void Biblioteca::EditarInformacoesLeitores(int ID_leitor)
{
    bool found = false;
    for (Pessoa* leitor : leitores) {
        // Assuming each reader has a unique ID field (implement a getID() method if necessary)
        if (leitor->getID() == ID_leitor) {
            cout << "Editing information for reader ID: " << ID_leitor << "\n";
            leitor->edit_informacoes();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Reader with ID " << ID_leitor << " not found.\n";
    }
}

void Biblioteca::ExtendLoanForReader(int ID_leitor)
{
    for (Emprestimo* e : emprestimos) {
        if(e->getLeitor()->getID() == ID_leitor) {
            e->extendLoan();
        }
    }
    cout << "No loan found for reader with ID " << ID_leitor << endl;
}
