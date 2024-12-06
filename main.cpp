#include <iostream>

using namespace std;

#include "Biblioteca.h"
#include "Emprestimo.h"

#include <ctime>


void mostrarMenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1. Registro de libros\n";
    cout << "2. Inscripcion de lectores\n";
    cout << "3. Mostrar livros\n";
    cout << "4. Mostrar leitores\n";
    cout << "5. Mostrar emprestimos\n";
    cout << "6. Realizar prestamos\n";
    cout << "7. Devolucion de libros y control de multas\n";
    cout << "8. Reservas de un libro\n";
    cout << "9. Lista de prestamos por tipo de libro\n";
    cout << "10. Mostrar todos los prestamos\n";
    cout << "11. Lista de multas pendientes\n";
    cout << "12. Edicion de datos de lectores\n";
    cout << "13. Edicion de datos de libros\n";
    cout << "14. Lista de libros por categoria\n";
    cout << "15. Carga de datos\n";
    cout << "16. Salvado de datos\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}


int main()
{
    Biblioteca bib;

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpia el buffer de entrada

        switch(opcion) {
            case 0: {
                cout << "Saliendo del programa...\n";
                break;
            }
            case 1: {
                cout << "Registro de livro\n";
                bib.registrarLivro();
                break;
            }
            case 2: {
                cout << "Registro de leitor\n";
                bib.registrarLeitor();
                break;
            }
            case 3: {
                // Acceder a la lista de libros
                const vector<Geral*>& livros = bib.getLivros();
                cout << "Lista de libros registrados:\n";
                /*for (const auto* livro : livros) {
                    livro->Show(cout); // Llamada polimórfica
                    cout << endl;
                }*/
                bib.Listagem_Livros();
                break;
            }
            case 4: {
                // Acceder a la lista de leitores
                const vector<Pessoa*>& leitores = bib.getLeitores();
                cout << "Lista de leitores registrados:\n";
                bib.Listagem_Leitores();
            }
            case 5: {
                cout << "Mostrar Emprestimos:\n";
                bib.Listagem_Emprestimos();
                break;
            }
            case 6: {
                cout << "Realizar Emprestimo:\n";
                bib.realizarEmprestimo();
                break;
            }
            case 7: {
                cout << "Devolucion de libros y control de multas:\n";

                int idLivro, idLeitor;
                cout << "Digite o ID do livro a ser devolvido: ";
                cin >> idLivro;
                cout << "Digite o ID do leitor que esta devolvendo o livro: ";
                cin >> idLeitor;

                Pessoa* leitor = bib.buscarLeitor(idLeitor);
                if (!leitor) {
                    cout << "Leitor não encontrado.\n";
                    break;
                }

                bib.devolverLivro(idLeitor, leitor);
                break;
            }
            case 8: {
                cout << "Reservas de un libro:\n";

                int idLivro;
                int idLeitor;

                cout << "Digite o ID do livro a ser reservado: ";
                cin >> idLivro;
                cout << "Digite o ID do leitor que quer reservar: ";
                cin >> idLeitor;

                Pessoa* leitor = bib.buscarLeitor(idLeitor);
                if (!leitor) {
                    cout << "Leitor não encontrado.\n";
                    break;
                }

                bib.reservarLivro(idLivro, leitor);

                break;
            }
            case 9: {
                cout << "Lista de empréstimos por tipo de livro:\n";
                bib.listarEmprestimosPorTipo();
                break;
            }
            case 10: {
                cout << "Mostrar todos los prestamos:\n";
                bib.Listagem_Emprestimos();
                break;
            }
            case 11: {
                cout << "Lista de multas pendientes:\n";
                bib.RelatorioMultasPendentes();
                break;
            }
            case 12: {
                int id;
                cout << "Edicion de datos de lectores:\n";
                cout << "Introduzca el ID del Leitor a cambiar: " << endl;
                cin >> id;
                bib.EditarInformacoesLeitores(id);
                break;
            }
            case 13: {
                int id;
                cout << "Edicion de datos de libros:\n";
                cout << "Introduzca el ID del Livro a cambiar: " << endl;
                cin >> id;
                bib.EditarInformacoesLivros(id);
                break;
            }
            case 14: {
                bib.RelatorioLivrosCategoria();
                break;
            }
            case 15: {
                string nom_fich;
                cout << "Carga de datos:\n";
                cout << "Introduzca el nome del ficheiro:\n";
                cin >> nom_fich;
                bib.LoadFile(nom_fich);
                cout << "Ficheiro carregado exitosamente" << endl;
                break;
            }
            case 16: {
                string nom_fich;
                cout << "Salvado de datos:\n";
                cout << "Introduzca el nombre del ficheiro en el que guardar los datos:" << endl;
                cin >> nom_fich;
                bib.SaveToFile(nom_fich);
                cout << "Fichero salvado correctamente" << endl;
                break;
            }
            default: {
                cout << "Opcion nao valida. Intente de novo\n";
                break;
            }
        }

    } while(opcion != 0);

    return 0;
}
