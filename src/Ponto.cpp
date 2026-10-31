#include "Ponto.hpp"

#include <ctime>

void Ponto::registrarEntrada(int codigoFuncionario)
{
    Registro registro;

    registro.codigoFuncionario = codigoFuncionario;
    registro.tipo = "entrada";

    registros.push_back(registro);
}

void Ponto::registrarSaida(int codigoFuncionario)
{
    Registro registro;

    registro.codigoFuncionario = codigoFuncionario;
    registro.tipo = "saida";

    registros.push_back(registro);
}

std::string Ponto::getData(int codigoFuncionario)
{
    for (int i = registros.size() - 1; i >= 0; i--)
    {
        if (registros[i].codigoFuncionario == codigoFuncionario)
        {
            return registros[i].data;
        }
    }

    return "";
}

std::string Ponto::getHorario(int codigoFuncionario)
{
    for (int i = registros.size() - 1; i >= 0; i--)
    {
        if (registros[i].codigoFuncionario == codigoFuncionario)
        {
            return registros[i].horario;
        }
    }

    return "";
}

std::string Ponto::getTipo(int codigoFuncionario)
{
    for (int i = registros.size() - 1; i >= 0; i--)
    {
        if (registros[i].codigoFuncionario == codigoFuncionario)
        {
            return registros[i].tipo;
        }
    }

    return "";
}

int Ponto::getFuncionario(int codigoFuncionario)
{
    for (int i = registros.size() - 1; i >= 0; i--)
    {
        if (registros[i].codigoFuncionario == codigoFuncionario)
        {
            return registros[i].codigoFuncionario;
        }
    }

    return -1;
}
