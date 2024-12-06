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
        file << livro->formatoArchivo() << "\n";
    }

    // Save readers
    file << "LEITORES\n";
    for (auto* leitor : leitores) {
        file << leitor->formatoArchivo() << "\n";
    }

    // Save loans
    file << "EMPRESTIMOS\n";
    for (auto* emprestimo : emprestimos) {
        file << emprestimo->getID() << " "
             << emprestimo->getLeitor()->getID() << " "
             << emprestimo->getPrazoDevolucao() << "\n";
    }

    file.close();
    return true;
}

bool Biblioteca::LoadFile(string nf)
{
    ifstream file(nf);
    if (!file.is_open()) {
        cerr << "Error ao abrir o arquivo para carregar!\n";
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line == "LIVROS") {
            while (getline(file, line) && !line.empty()) {
                char type = line[0]; // Tipo do livro
                stringstream ss(line.substr(2)); // Ignora o tipo (F, C, etc.)
                Geral* livro = nullptr;

                int id, numPaginas;
                string titulo, autor;

                // Identificar o tipo do livro
                if (type == 'F') {
                    livro = new LivroFiccao();
                } else if (type == 'C') {
                    livro = new LivroCientifico();
                } else if (type == 'R') {
                    livro = new Revista();
                } else if (type == 'J') {
                    livro = new Jornal();
                } else {
                    continue; // Tipo inválido
                }

                // Ler campos
                ss >> id;
                ss.ignore(); // Ignorar tabulação
                getline(ss, titulo, '\t');
                getline(ss, autor, '\t');
                ss >> numPaginas;

                // Atribuir valores ao objeto livro
                if (livro) {
                    livro->setID(id);
                    livro->setTitulo(titulo);
                    livro->setAutor(autor);
                    livro->setNumPags(numPaginas);
                    Add_Livro(livro);
                }
            }
        } else if (line == "LEITORES") {
            while (getline(file, line) && !line.empty()) {
                char type = line[0]; // Tipo do leitor
                stringstream ss(line.substr(2)); // Ignora o tipo (E, S, etc.)
                Pessoa* leitor = nullptr;

                int id;
                string nome;

                // Identificar o tipo do leitor
                if (type == 'E') {
                    leitor = new Estudante();
                } else if (type == 'S') {
                    leitor = new Senior();
                } else if (type == 'P') {
                    leitor = new Professor();
                } else if (type == 'C') {
                    leitor = new LeitorComum();
                } else {
                    continue; // Tipo inválido
                }

                // Ler campos
                ss >> id;
                ss.ignore(); // Ignorar tabulação
                getline(ss, nome, '\t');

                // Atribuir valores ao objeto leitor
                if (leitor) {
                    leitor->setID(id);
                    leitor->setNome(nome);
                    Add_Leitor(leitor);
                }
            }
        } else if (line == "EMPRESTIMOS") {
            while (getline(file, line) && !line.empty()) {
                stringstream ss(line);
                int livro_ID, leitor_ID;
                time_t prazoDevolucao;

                // Ler os dados do empréstimo
                ss >> livro_ID >> leitor_ID >> prazoDevolucao;

                Geral* livro = nullptr;
                Pessoa* leitor = nullptr;

                // Buscar livro e leitor pelo ID
                for (auto* l : livros) {
                    if (l->getID() == livro_ID) {
                        livro = l;
                        break;
                    }
                }

                for (auto* p : leitores) {
                    if (p->getID() == leitor_ID) {
                        leitor = p;
                        break;
                    }
                }

                // Criar empréstimo se os dados forem válidos
                if (livro && leitor) {
                    Emprestimo* e = new Emprestimo(leitor, livro, prazoDevolucao);
                    Add_Emprestimo(e);
                }
            }
        }
    }

    file.close();
    return true;
}

void Biblioteca::RelatorioLivrosCategoria()
{
    cout << "Relatorio de livros por categoria: " << endl;

    // Livros cientificos
    cout << "Livros cientificos: " << endl;
    for(auto* livro : livros) {
        if(typeid(*livro) == typeid(LivroCientifico)) {
            livro->Show(cout);
        }
    }

    // Livros ficcao
    cout << "Livros de ficcao: " << endl;
    for(auto* livro : livros) {
        if(typeid(*livro) == typeid(LivroFiccao)) {
            livro->Show(cout);
        }
    }

    // Revistas
    cout << "Revistas: " << endl;
    for(auto* livro : livros) {
        if(typeid(*livro) == typeid(Revista)) {
            livro->Show(cout);
        }
    }

    // Jornals
    cout << "Jornals: " << endl;
    for(auto* livro : livros) {
        if(typeid(*livro) == typeid(Jornal)) {
            livro->Show(cout);
        }
    }
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
        liv->Show(cout);
    }
}

void Biblioteca::Listagem_Leitores()
{
    for(Pessoa* p : leitores) {
        p->Show(cout);
    }
}

void Biblioteca::Listagem_Emprestimos()
{
    for(Emprestimo* e : emprestimos) {
        e->mostrarDetalhes();
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

void Biblioteca::EditarInformacoesLivros(int ID_livro)
{
    bool found = false;
    for (Geral* livro : livros) {

        if (livro->getID() == ID_livro) {
            livro->editarInformacoes();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Livro with ID " << ID_livro << " not found.\n";
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

void Biblioteca::registrarLivro()
{
    int tipo;
    cout << "Seleccione el tipo de libro:\n";
    cout << "1. Livro de Ficcao\n";
    cout << "2. Livro Cientifico\n";
    cout << "3. Livro Educativo\n";
    cout << "4. Revista\n";
    cout << "5. Jornal\n";
    cout << "Seleccione una opcion: ";
    cin >> tipo;

    Geral* novoLivro = nullptr;

    switch (tipo) {
        case 1:
            novoLivro = new LivroFiccao();
            break;
        case 2:
            novoLivro = new LivroCientifico();
            break;
        case 3:
            novoLivro = new LivroEducativo();
            break;
        case 4:
            novoLivro = new Revista();
            break;
        case 5:
            novoLivro = new Jornal();
            break;
        default:
            cout << "Opción inválida. No se creó el libro.\n";
            return;
    }

    if(novoLivro) {
        // Solicita los datos comunes a todos los libros
        int id, numPags;
        string titulo, autor;
        cout << "Ingrese el ID del libro: ";
        cin >> id;
        cin.ignore();
        // Check if id is already assigned
        Geral* livro = buscarLivro(id);
        if (livro) {
            cout << "ID already assigned.\n";
            return;
        }
        cout << "Ingrese el titulo del libro: ";
        getline(cin, titulo);
        cout << "Ingrese el autor del libro: ";
        getline(cin, autor);
        cout << "Ingrese el numero de paginas del libro: ";
        cin >> numPags;

        // Establece los datos básicos en el objeto `novoLivro`
        novoLivro->setID(id);
        novoLivro->setTitulo(titulo);
        novoLivro->setAutor(autor);
        novoLivro->setNumPags(numPags);

        // Añade el libro a la lista de la biblioteca
        Add_Livro(novoLivro);
        cout << "Libro registrado exitosamente!\n";
    }
}

void Biblioteca::registrarLeitor()
{
    int tipo;
    cout << "Seleccione el tipo de Leitor:\n";
    cout << "1. Leitor Comum\n";
    cout << "2. Estudante\n";
    cout << "3. Professor\n";
    cout << "4. Senior\n";
    cout << "Seleccione una opcion: ";
    cin >> tipo;

    Pessoa* novoLeitor = nullptr;

    switch (tipo) {
        case 1:
            novoLeitor = new LeitorComum();
            break;
        case 2:
            novoLeitor = new Estudante();
            break;
        case 3:
            novoLeitor = new Professor();
            break;
        case 4:
            novoLeitor = new Senior();
            break;
        default:
            cout << "Opción inválida. No se creó el Leitor.\n";
            return;
    }

    if(novoLeitor) {
        // Solicita los datos comunes a todas las Pessoas
        int id;
        string nome;
        cout << "Ingrese el ID del leitor: ";
        cin >> id;
        // Check if id is already assigned
        Pessoa* p = buscarLeitor(id);
        if (p) {
            cout << "ID already assigned.\n";
            return;
        }
        cin.ignore();
        cout << "Ingrese el nome del leitor: ";
        getline(cin, nome);

        // Establece los datos básicos en el objeto `novoLivro`
        novoLeitor->setID(id);
        novoLeitor->setNome(nome);

        // Añade el libro a la lista de la biblioteca
        Add_Leitor(novoLeitor);
        cout << "Leitor registrado exitosamente!\n";
    }
}

const vector<Geral*>& Biblioteca::getLivros() const {
    return livros; // Devuelve una referencia constante para acceso de solo lectura
}

const vector<Pessoa*>& Biblioteca::getLeitores() const {
    return leitores; // Devuelve una referencia constante para acceso de solo lectura
}

Pessoa* Biblioteca::buscarLeitor(int id)
{
    for (auto* leitor : leitores) {
        if (leitor->getID() == id) {
            return leitor;
        }
    }
    return nullptr;
}

Geral* Biblioteca::buscarLivro(int id)
{
    for (auto* livro : livros) {
        if (livro->getID() == id) {
            return livro;
        }
    }
    return nullptr;
}

void Biblioteca::reservarLivro(int id_livro, Pessoa* leitor)
{
    Geral* livro = buscarLivro(id_livro);
    if (!livro) {
        cout << "Livro não encontrado.\n";
        return;
    }
    if(livro->isEmprestado()){
        if(livro->getReservas().size() < leitor->getLimiteReservas()) {
            livro->addReserva(leitor);
            cout << "Reserva realizada como sucesso!" << endl;
        } else {
            cout << "Limite de reservas alcanzado para este leitor" << endl;
        }
    } else {
        cout << "O livro nao esta emprestado, nao e possivel reserva-lo" << endl;
    }
    cout << "Reserva registrada para el libro: " << livro->getTitulo() << "\n";
}

Emprestimo* Biblioteca::getEmprestimoPorLivro(int id_livro) {
    for (auto* emprestimo : emprestimos) {
        if (emprestimo->getLivro()->getID() == id_livro) {
            return emprestimo;
        }
    }
    return nullptr; // Retorna nullptr si no encuentra un préstamo con ese libro
}

void Biblioteca::devolverLivro(int id_livro, Pessoa* leitor)
{
    Geral* livro = buscarLivro(id_livro);
    if (!livro) {
        cout << "Livro nao encontrado.\n";
        return;
    }

    Emprestimo* emprestimo = getEmprestimoPorLivro(id_livro);
    if (!emprestimo) {
        cout << "Nenhum emprestimo ativo para este livro.\n";
        return;
    }

    // Verificar si el préstamo pertenece al lector actual
    if (emprestimo->getLeitor() != leitor) {
        cout << "O leitor informado nao corresponde ao emprestimo.\n";
        return;
    }

    // Verificar se o empréstimo já passou do prazo
    if (emprestimo->isOverdue()) {
        double multa = emprestimo->getDiasAtraso() * leitor->getDescontoMulta(); // Aplica desconto dependendo do tipo de leitor
        leitor->registrarMulta(multa);
        cout << "Livro devolvido com atraso. Multa registrada: " << multa << " euros.\n";
    } else {
        cout << "Livro devolvido no prazo.\n";
    }

    // Atualizar status do livro e do empréstimo
    livro->setEmprestado(false);
    removerEmprestimo(emprestimo); // Método para remover empréstimo da lista
    cout << "Devolucao concluida.\n";
}

void Biblioteca::realizarEmprestimo()
{
    int idLeitor, id_livro;

    // Solicitar ID del lector
    cout << "Ingrese el ID del lector: ";
    cin >> idLeitor;
    Pessoa* leitor = buscarLeitor(idLeitor);
    if (!leitor) {
        cout << "Lector no encontrado.\n";
        return;
    }

    // Solicitar ID del libro
    cout << "Ingrese el ID del libro: ";
    cin >> id_livro;
    Geral* livro = buscarLivro(id_livro);
    if (!livro) {
        cout << "Livro nao encontrado.\n";
        return;
    }

    // Verificar que el libro no esté prestado
    if (livro->isEmprestado()) {
        cout << "El libro ya está prestado. ¿Desea reservarlo? (s/n): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta == 's' || respuesta == 'S') {
            reservarLivro(livro->getID(), leitor);
        }
        return;
    }

    // Verificar restricciones del lector
    if (leitor->getLivrosEmprestados() >= leitor->getLimiteReservas()) {
        cout << "El lector ya alcanzó su límite de libros prestados.\n";
        return;
    }

    // Calcular la fecha de devolución según el tipo de lector y libro
    string tipoLivro = livro->getTipo();
    int diasPrazo = leitor->getPrazoDevolucao(tipoLivro);

    // Calcular la fecha de devolución
    time_t now = time(nullptr);
    time_t prazoDevolucao = now + (diasPrazo * 24 * 60 * 60); // Sumar días en segundos

    // Registrar el préstamo
    Emprestimo* emprestimo = new Emprestimo(leitor, livro, prazoDevolucao);
    Add_Emprestimo(emprestimo);

    // Actualizar el estado del libro
    livro->setEmprestado(true);
    leitor->registrarEmprestimo(tipoLivro, livro->getTitulo());

    // Mostrar información de la fecha
    tm* prazo_tm = localtime(&prazoDevolucao);
    cout << "Préstamo registrado. Fecha de devolución: " << put_time(prazo_tm, "%d-%m-%Y %H:%M:%S") << "\n";

    cout << "Emprestimo realizado con exito!" << endl;
}

void Biblioteca::removerEmprestimo(Emprestimo* e)
{
    for (int i = 0; i < emprestimos.size(); ++i) {
        if (emprestimos[i] == e) {
            delete emprestimos[i]; // Liberar memória do empréstimo
            emprestimos.erase(emprestimos.begin() + i); // Remover do vetor
            break; // Sair do loop depois de encontrar o empréstimo
        }
    }
}

void Biblioteca::listarEmprestimosPorTipo() const
{
    map<string, vector<Emprestimo*>> emprestimos_por_tipo;

    // Percorrer a lista de empréstimos
    for (const auto& emprestimo : emprestimos) {
        string tipo_livro = emprestimo->getLivro()->getTipo();
        emprestimos_por_tipo[tipo_livro].push_back(emprestimo);
    }

    // Mostrar os resultados
    for (const auto& par : emprestimos_por_tipo) {
        cout << "Tipo de livro: " << par.first << "\n";
        for (const auto& emprestimo : par.second) {
            cout << "\t";
            emprestimo->mostrarDetalhes(); // Exibe os detalhes do empréstimo
        }
    }

}
