#include "Funcionario.hpp"
#include "Ponto.hpp"

Funcionario::Funcionario(std::string nome,
                         std::string senha,
                         int codigo,
                         Ponto* ponto)
{
    this->nome = nome;
    this->senha = senha;
    this->codigo = codigo;
    this->ponto = ponto;
}

void Funcionario::registrarEntrada()
{
    ponto->registrarEntrada(codigo);
}

void Funcionario::registrarSaida()
{
    ponto->registrarSaida(codigo);
}

void Funcionario::criarJustificativa(std::string data,
                                     std::string motivo,
                                     std::string status)
{
    Justificativa j(data, motivo, status, nome);

    justificativas.push_back(j);
}

std::string Funcionario::consultarHoras()
{
    return ponto->getHorario(codigo);
}

std::string Funcionario::consultarJustificativa()
{
    if (justificativas.empty())
    {
        return "Nenhuma justificativa cadastrada.";
    }

    std::string resultado;

    for (int i = 0; i < justificativas.size(); i++)
    {
        resultado += "Justificativa " + std::to_string(i + 1) + ":\n";
        resultado += "Data: " + justificativas[i].getData() + "\n";
        resultado += "Motivo: " + justificativas[i].getMotivo() + "\n";
        resultado += "Funcionario: " + justificativas[i].getFuncionario() + "\n";

        resultado += "Status: ";

        switch (justificativas[i].getStatus())
        {
            case StatusJustificativa::PENDENTE:
                resultado += "Pendente";
                break;

            case StatusJustificativa::ACEITA:
                resultado += "Aceita";
                break;

            case StatusJustificativa::REJEITADA:
                resultado += "Rejeitada";
                break;
        }

        resultado += "\n\n";
    }

    return resultado;
}

std::string Funcionario::consultarNome()
{
    return nome;
}

int Funcionario::consultarCodigo()
{
    return codigo;
}
