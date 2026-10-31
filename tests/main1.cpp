#include <iostream>
#include <string>

#include "Funcionario.hpp"
#include "RH.hpp"
#include "Ponto.hpp"
#include "Relatorio.hpp"
#include "GerenciadorSistema.hpp"

using namespace std;

void pausar()
{
    cout << "\nPressione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void menuFuncionario(GerenciadorSistema& sistema,
                     Funcionario* funcionario)
{
    int opcao = 0;

    do
    {
        limparTela();

        cout << "====================================\n";
        cout << "          MENU FUNCIONARIO\n";
        cout << "====================================\n";
        cout << "Funcionario: " << funcionario->consultarNome() << "\n";
        cout << "Codigo: " << funcionario->consultarCodigo() << "\n\n";

        cout << "1 - Registrar entrada\n";
        cout << "2 - Registrar saida\n";
        cout << "3 - Consultar historico\n";
        cout << "4 - Criar justificativa\n";
        cout << "5 - Consultar justificativas\n";
        cout << "6 - Relatorio diario\n";
        cout << "7 - Relatorio mensal\n";
        cout << "0 - Sair da conta\n";
        cout << "\nEscolha uma opcao: ";

        cin >> opcao;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "\nOpcao invalida! Digite um numero.\n";
            pausar();
            continue;
        }

        cin.ignore(10000, '\n');

        switch (opcao)
        {
            case 1:
            {
                sistema.registrarEntrada(funcionario);

                cout << "\nEntrada registrada com sucesso!\n";
                pausar();
                break;
            }

            case 2:
            {
                sistema.registrarSaida(funcionario);

                cout << "\nSaida registrada com sucesso!\n";
                pausar();
                break;
            }

            case 3:
            {
                cout << "\n========== HISTORICO ==========\n\n";

                cout << sistema.consultarHistorico(funcionario);

                pausar();
                break;
            }

            case 4:
            {
                string data;
                string motivo;

                cout << "\n========== NOVA JUSTIFICATIVA ==========\n";

                cout << "Data (dd/mm/aaaa): ";
                getline(cin, data);

                cout << "Motivo: ";
                getline(cin, motivo);

                sistema.enviarJustificativa(
                    funcionario,
                    data,
                    motivo,
                    "pendente"
                );

                cout << "\nJustificativa enviada com sucesso!\n";

                pausar();
                break;
            }

            case 5:
            {
                cout << "\n========== JUSTIFICATIVAS ==========\n\n";

                cout << sistema.consultarJustificativas(funcionario);

                pausar();
                break;
            }

            case 6:
            {
                string data;

                cout << "\n========== RELATORIO DIARIO ==========\n";

                cout << "Data (dd/mm/aaaa): ";
                getline(cin, data);

                cout << "\n";

                cout << sistema.getRelatorio()
                            ->gerarRelatorioDiario(
                                funcionario->consultarCodigo(),
                                data
                            );

                pausar();
                break;
            }

            case 7:
            {
                int mes;
                int ano;

                cout << "\n========== RELATORIO MENSAL ==========\n";

                cout << "Mes: ";
                cin >> mes;

                cout << "Ano: ";
                cin >> ano;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');

                    cout << "\nMes ou ano invalido!\n";
                    pausar();
                    break;
                }

                cin.ignore(10000, '\n');

                cout << "\n";

                cout << sistema.getRelatorio()
                            ->gerarRelatorioMensal(
                                funcionario->consultarCodigo(),
                                mes,
                                ano
                            );

                pausar();
                break;
            }

            case 0:
            {
                cout << "\nSaindo da conta...\n";
                break;
            }

            default:
            {
                cout << "\nOpcao invalida!\n";
                pausar();
                break;
            }
        }

    } while (opcao != 0);
}

void menuRH(GerenciadorSistema& sistema,
            RH* rh)
{
    int opcao = 0;

    do
    {
        limparTela();

        cout << "====================================\n";
        cout << "              MENU RH\n";
        cout << "====================================\n";
        cout << "RH: " << rh->consultarNome() << "\n";
        cout << "Codigo: " << rh->consultarCodigo() << "\n\n";

        cout << "1 - Consultar funcionarios\n";
        cout << "2 - Consultar registros de funcionario\n";
        cout << "3 - Consultar horas dos funcionarios\n";
        cout << "4 - Consultar justificativas\n";
        cout << "5 - Aceitar justificativa\n";
        cout << "6 - Rejeitar justificativa\n";
        cout << "0 - Sair da conta\n";
        cout << "\nEscolha uma opcao: ";

        cin >> opcao;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "\nOpcao invalida! Digite um numero.\n";
            pausar();
            continue;
        }

        cin.ignore(10000, '\n');

        switch (opcao)
        {
            case 1:
            {
                cout << "\n========== FUNCIONARIOS ==========\n\n";

                cout << rh->consultarFuncionarios();

                pausar();
                break;
            }

            case 2:
            {
                int codigo;

                cout << "\n========== REGISTROS ==========\n";

                cout << "Codigo do funcionario: ";
                cin >> codigo;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');

                    cout << "\nCodigo invalido!\n";
                    pausar();
                    break;
                }

                cin.ignore(10000, '\n');

                Funcionario* funcionario = sistema.login(codigo, "");

                /*
                    Como o login exige senha, procuramos o funcionario
                    atraves da lista conhecida pelo RH.

                    Para este teste, usamos o codigo e percorremos
                    os funcionarios cadastrados.
                */

                cout << "\nDigite a senha do funcionario: ";

                string senha;
                getline(cin, senha);

                funcionario = sistema.login(codigo, senha);

                if (funcionario == nullptr)
                {
                    cout << "\nFuncionario nao encontrado ou senha incorreta.\n";
                }
                else
                {
                    cout << "\n";
                    cout << rh->consultarRegistros(funcionario);
                }

                pausar();
                break;
            }

            case 3:
            {
                cout << "\n========== HORAS DOS FUNCIONARIOS ==========\n\n";

                cout << rh->consultarHorasFuncionarios();

                pausar();
                break;
            }

            case 4:
            {
                cout << "\n========== JUSTIFICATIVAS ==========\n\n";

                cout << rh->consultarJustificativasFuncionarios();

                pausar();
                break;
            }

            case 5:
            {
                int codigo;
                int indice;

                cout << "\n========== ACEITAR JUSTIFICATIVA ==========\n";

                cout << "Codigo do funcionario: ";
                cin >> codigo;

                cout << "Numero da justificativa: ";
                cin >> indice;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');

                    cout << "\nEntrada invalida!\n";
                    pausar();
                    break;
                }

                cin.ignore(10000, '\n');

                cout << "Senha do funcionario: ";

                string senha;
                getline(cin, senha);

                Funcionario* funcionario =
                    sistema.login(codigo, senha);

                if (funcionario == nullptr)
                {
                    cout << "\nFuncionario nao encontrado ou senha incorreta.\n";
                }
                else
                {
                    rh->aceitarJustificativa(
                        funcionario,
                        indice - 1
                    );

                    cout << "\nJustificativa aceita!\n";
                }

                pausar();
                break;
            }

            case 6:
            {
                int codigo;
                int indice;

                cout << "\n========== REJEITAR JUSTIFICATIVA ==========\n";

                cout << "Codigo do funcionario: ";
                cin >> codigo;

                cout << "Numero da justificativa: ";
                cin >> indice;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');

                    cout << "\nEntrada invalida!\n";
                    pausar();
                    break;
                }

                cin.ignore(10000, '\n');

                cout << "Senha do funcionario: ";

                string senha;
                getline(cin, senha);

                Funcionario* funcionario =
                    sistema.login(codigo, senha);

                if (funcionario == nullptr)
                {
                    cout << "\nFuncionario nao encontrado ou senha incorreta.\n";
                }
                else
                {
                    rh->rejeitarJustificativa(
                        funcionario,
                        indice - 1
                    );

                    cout << "\nJustificativa rejeitada!\n";
                }

                pausar();
                break;
            }

            case 0:
            {
                cout << "\nSaindo da conta...\n";
                break;
            }

            default:
            {
                cout << "\nOpcao invalida!\n";
                pausar();
                break;
            }
        }

    } while (opcao != 0);
}

int main()
{
    Ponto ponto;

    GerenciadorSistema sistema(&ponto);

    /*
        ====================================
        CADASTRO DOS FUNCIONARIOS
        ====================================
    */

    Funcionario funcionario1(
        "Carlos",
        "1234",
        1,
        &ponto
    );

    Funcionario funcionario2(
        "Maria",
        "5678",
        2,
        &ponto
    );

    RH rh(
        "Administrador",
        "admin",
        100,
        &ponto
    );

    sistema.adicionarFuncionario(&funcionario1);
    sistema.adicionarFuncionario(&funcionario2);

    rh.adicionarFuncionario(&funcionario1);
    rh.adicionarFuncionario(&funcionario2);

    sistema.adicionarRH(&rh);

    /*
        ====================================
        LOGIN
        ====================================
    */

    while (true)
    {
        limparTela();

        cout << "====================================\n";
        cout << "       SISTEMA DE CONTROLE DE PONTO\n";
        cout << "====================================\n\n";

        cout << "Digite 0 para sair.\n\n";

        int codigo;

        cout << "Codigo: ";
        cin >> codigo;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "\nCodigo invalido! Digite um numero.\n";
            pausar();
            continue;
        }

        if (codigo == 0)
        {
            cout << "\nEncerrando sistema...\n";
            break;
        }

        cin.ignore(10000, '\n');

        string senha;

        cout << "Senha: ";
        getline(cin, senha);

        Funcionario* usuario =
            sistema.login(codigo, senha);

        if (usuario == nullptr)
        {
            cout << "\nCodigo ou senha incorretos!\n";
            pausar();
            continue;
        }

        /*
            Se o usuario for o RH, abre o menu de RH.
        */

        if (usuario == &rh)
        {
            menuRH(sistema, &rh);
        }
        else
        {
            menuFuncionario(sistema, usuario);
        }
    }

    return 0;
}