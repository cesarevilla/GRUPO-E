#include "RH.hpp"

RH::RH(std::string nome,
       std::string senha,
       int codigo,
       Ponto* ponto)
    : Funcionario(nome, senha, codigo, ponto)
{
}

void RH::adicionarFuncionario(Funcionario* funcionario)
{
    if (funcionario != nullptr)
    {
        funcionarios.push_back(funcionario);
    }
}

std::string RH::consultarFuncionarios()
{
    if (funcionarios.empty())
    {
        return "Nenhum funcionario cadastrado.";
    }

    std::string resultado;

    for (int i = 0; i < funcionarios.size(); i++)
    {
        resultado += "Funcionario " + std::to_string(i + 1) + ":\n";
        resultado += "Nome: " + funcionarios[i]->consultarNome() + "\n";
        resultado += "Codigo: " +
                     std::to_string(funcionarios[i]->consultarCodigo()) +
                     "\n\n";
    }

    return resultado;
}

std::string RH::consultarRegistros(Funcionario* funcionario)
{
    if (funcionario == nullptr)
    {
        return "Funcionario invalido.";
    }

    std::string resultado;

    resultado += "Funcionario: " + funcionario->consultarNome() + "\n";
    resultado += "Codigo: " +
                 std::to_string(funcionario->consultarCodigo()) +
                 "\n";

    resultado += "Horario do ultimo registro: ";
    resultado += funcionario->consultarHoras();
    resultado += "\n";

    return resultado;
}

std::string RH::consultarHorasFuncionarios()
{
    if (funcionarios.empty())
    {
        return "Nenhum funcionario cadastrado.";
    }

    std::string resultado;

    for (int i = 0; i < funcionarios.size(); i++)
    {
        resultado += "Funcionario: ";
        resultado += funcionarios[i]->consultarNome();

        resultado += "\nCodigo: ";
        resultado += std::to_string(funcionarios[i]->consultarCodigo());

        resultado += "\nUltimo horario registrado: ";
        resultado += funcionarios[i]->consultarHoras();

        resultado += "\n\n";
    }

    return resultado;
}

std::string RH::consultarJustificativasFuncionarios()
{
    if (funcionarios.empty())
    {
        return "Nenhum funcionario cadastrado.";
    }

    std::string resultado;

    for (int i = 0; i < funcionarios.size(); i++)
    {
        resultado += "Funcionario: ";
        resultado += funcionarios[i]->consultarNome();
        resultado += "\n";

        resultado += funcionarios[i]->consultarJustificativa();
        resultado += "\n";
    }

    return resultado;
}

void RH::aceitarJustificativa(Justificativa& justificativa)
{
    justificativa.aceitar();
}

void RH::rejeitarJustificativa(Justificativa& justificativa)
{
    justificativa.rejeitar();
}
