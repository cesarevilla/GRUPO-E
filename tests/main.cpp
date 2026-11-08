#include <iostream>
#include <string>
#include <cstdlib>

#include "Funcionario.hpp"
#include "RH.hpp"
#include "Ponto.hpp"
#include "Relatorio.hpp"
#include "GerenciadorSistema.hpp"

using namespace std;

void pausar()
{
    // O buffer ja esta limpo antes de toda chamada, por isso so cin.get()
    cout << "\nPressione ENTER para continuar...";
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

                Funcionario* funcionario = sistema.buscarPorCodigo(codigo);

                if (funcionario == nullptr)
                {
                    cout << "\nFuncionario nao encontrado.\n";
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

                Funcionario* funcionario = sistema.buscarPorCodigo(codigo);

                if (funcionario == nullptr)
                {
                    cout << "\nFuncionario nao encontrado.\n";
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

                Funcionario* funcionario = sistema.buscarPorCodigo(codigo);

                if (funcionario == nullptr)
                {
                    cout << "\nFuncionario nao encontrado.\n";
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

Funcionario* telaLogin(GerenciadorSistema& sistema)
{
    limparTela();

    cout << "====================================\n";
    cout << "               ENTRAR\n";
    cout << "====================================\n\n";

    int codigo;
    cout << "Codigo: ";
    cin >> codigo;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "\nCodigo invalido! Digite um numero.\n";
        pausar();
        return nullptr;
    }

    cin.ignore(10000, '\n');

    string senha;
    cout << "Senha: ";
    getline(cin, senha);

    Funcionario* usuario = sistema.login(codigo, senha);

    if (usuario == nullptr)
    {
        cout << "\nCodigo ou senha incorretos!\n";
        pausar();
    }

    return usuario;
}

void criarConta(GerenciadorSistema& sistema, Ponto* ponto)
{
    limparTela();

    cout << "====================================\n";
    cout << "            CRIAR CONTA\n";
    cout << "====================================\n\n";

    cout << "1 - Funcionario\n";
    cout << "2 - RH\n";
    cout << "0 - Voltar\n";
    cout << "\nTipo de conta: ";

    int tipo;
    cin >> tipo;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "\nOpcao invalida!\n";
        pausar();
        return;
    }

    cin.ignore(10000, '\n');

    if (tipo == 0)
    {
        return;
    }

    if (tipo != 1 && tipo != 2)
    {
        cout << "\nOpcao invalida!\n";
        pausar();
        return;
    }

    string nome;
    cout << "Nome: ";
    getline(cin, nome);

    int codigo;
    cout << "Codigo (numero maior que 0): ";
    cin >> codigo;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "\nCodigo invalido! Digite um numero.\n";
        pausar();
        return;
    }

    cin.ignore(10000, '\n');

    if (codigo <= 0)
    {
        cout << "\nO codigo deve ser maior que 0.\n";
        pausar();
        return;
    }

    if (sistema.buscarPorCodigo(codigo) != nullptr)
    {
        cout << "\nEsse codigo ja esta em uso.\n";
        pausar();
        return;
    }

    string senha;
    cout << "Senha: ";
    getline(cin, senha);

    if (nome.empty() || senha.empty())
    {
        cout << "\nNome e senha nao podem ficar vazios.\n";
        pausar();
        return;
    }

    if (tipo == 1)
    {
        sistema.adicionarFuncionario(
            new Funcionario(nome, senha, codigo, ponto)
        );
    }
    else
    {
        sistema.adicionarRH(
            new RH(nome, senha, codigo, ponto)
        );
    }

    cout << "\nConta criada com sucesso! Agora voce ja pode entrar.\n";
    pausar();
}

int main()
{
    Ponto ponto;

    GerenciadorSistema sistema(&ponto);

    while (true)
    {
        limparTela();

        cout << "====================================\n";
        cout << "       SISTEMA DE CONTROLE DE PONTO\n";
        cout << "====================================\n\n";

        cout << "1 - Entrar\n";
        cout << "2 - Criar conta\n";
        cout << "0 - Sair\n";
        cout << "\nEscolha uma opcao: ";

        int opcao;
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

        if (opcao == 0)
        {
            cout << "\nEncerrando sistema...\n";
            break;
        }

        if (opcao == 2)
        {
            criarConta(sistema, &ponto);
            continue;
        }

        if (opcao != 1)
        {
            cout << "\nOpcao invalida!\n";
            pausar();
            continue;
        }

        Funcionario* usuario = telaLogin(sistema);

        if (usuario == nullptr)
        {
            continue;
        }

        if (RH* rh = dynamic_cast<RH*>(usuario))
        {
            menuRH(sistema, rh);
        }
        else
        {
            menuFuncionario(sistema, usuario);
        }
    }

    return 0;
}
