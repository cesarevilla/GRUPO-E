#include "GerenciadorSistema.hpp"

GerenciadorSistema::GerenciadorSistema(Ponto* ponto)
{
    this->ponto = ponto;
    this->relatorio = new Relatorio(ponto);
}

void GerenciadorSistema::adicionarFuncionario(Funcionario* funcionario)
{
    if (funcionario != nullptr)
    {
        funcionarios.push_back(funcionario);
    }
}

void GerenciadorSistema::adicionarRH(RH* rh)
{
    if (rh != nullptr)
    {
        rhs.push_back(rh);

        adicionarFuncionario(rh);
    }
}

Funcionario* GerenciadorSistema::login(int codigo, std::string senha)
{
    for (int i = 0; i < funcionarios.size(); i++)
    {
        if (funcionarios[i]->consultarCodigo() == codigo)
        {
            // A senha ainda não possui getter em Funcionario.
            // Portanto, o login precisa ser completado quando
            // definirmos como a senha será validada.
        }
    }

    return nullptr;
}

void GerenciadorSistema::registrarEntrada(Funcionario* funcionario)
{
    if (funcionario != nullptr)
    {
        funcionario->registrarEntrada();
    }
}

void GerenciadorSistema::registrarSaida(Funcionario* funcionario)
{
    if (funcionario != nullptr)
    {
        funcionario->registrarSaida();
    }
}

std::string GerenciadorSistema::consultarHistorico(Funcionario* funcionario)
{
    if (funcionario == nullptr)
    {
        return "Funcionario invalido.";
    }

    return relatorio->consultarHistorico(funcionario->consultarCodigo());
}

void GerenciadorSistema::enviarJustificativa(Funcionario* funcionario,
                                             std::string data,
                                             std::string motivo,
                                             std::string status)
{
    if (funcionario != nullptr)
    {
        funcionario->criarJustificativa(data, motivo, status);
    }
}

std::string GerenciadorSistema::consultarJustificativas(
    Funcionario* funcionario)
{
    if (funcionario == nullptr)
    {
        return "Funcionario invalido.";
    }

    return funcionario->consultarJustificativa();
}

Relatorio* GerenciadorSistema::getRelatorio()
{
    return relatorio;
}
