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
        return "Nenhuma justificativa cadastrada.\n";
    }

    std::string resultado;

    for (int i = 0; i < justificativas.size(); i++)
    {
        resultado += "Justificativa ";
        resultado += std::to_string(i + 1);
        resultado += ":\n";

        resultado += "Data: ";
        resultado += justificativas[i].getData();
        resultado += "\n";

        resultado += "Motivo: ";
        resultado += justificativas[i].getMotivo();
        resultado += "\n";

        resultado += "Funcionario: ";
        resultado += justificativas[i].getFuncionario();
        resultado += "\n";

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

bool Funcionario::verificarSenha(std::string senha)
{
    return this->senha == senha;
}

void Funcionario::aceitarJustificativa(int indice)
{
    if (indice >= 0 && indice < justificativas.size())
    {
        justificativas[indice].aceitar();
    }
}

void Funcionario::rejeitarJustificativa(int indice)
{
    if (indice >= 0 && indice < justificativas.size())
    {
        justificativas[indice].rejeitar();
    }
}
