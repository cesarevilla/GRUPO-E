#include "Ponto.hpp"

#include <ctime>
#include <iomanip>
#include <sstream>

Ponto::Registro Ponto::criarRegistro(int codigoFuncionario,
                                      std::string tipo)
{
    Registro registro;

    registro.codigoFuncionario = codigoFuncionario;
    registro.tipo = tipo;

    std::time_t agora = std::time(nullptr);
    std::tm* tempo = std::localtime(&agora);

    std::ostringstream data;

    data << std::setfill('0')
         << std::setw(2) << tempo->tm_mday
         << "/"
         << std::setw(2) << tempo->tm_mon + 1
         << "/"
         << tempo->tm_year + 1900;

    registro.data = data.str();

    std::ostringstream horario;

    horario << std::setfill('0')
            << std::setw(2) << tempo->tm_hour
            << ":"
            << std::setw(2) << tempo->tm_min
            << ":"
            << std::setw(2) << tempo->tm_sec;

    registro.horario = horario.str();

    return registro;
}

void Ponto::registrarEntrada(int codigoFuncionario)
{
    Registro registro = criarRegistro(codigoFuncionario, "entrada");

    registros.push_back(registro);
}

void Ponto::registrarSaida(int codigoFuncionario)
{
    Registro registro = criarRegistro(codigoFuncionario, "saida");

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

std::string Ponto::getHorarioEntrada(int codigoFuncionario,
                                      std::string data)
{
    for (int i = 0; i < registros.size(); i++)
    {
        if (registros[i].codigoFuncionario == codigoFuncionario &&
            registros[i].data == data &&
            registros[i].tipo == "entrada")
        {
            return registros[i].horario;
        }
    }

    return "";
}

std::string Ponto::getHorarioSaida(int codigoFuncionario,
                                   std::string data)
{
    for (int i = registros.size() - 1; i >= 0; i--)
    {
        if (registros[i].codigoFuncionario == codigoFuncionario &&
            registros[i].data == data &&
            registros[i].tipo == "saida")
        {
            return registros[i].horario;
        }
    }

    return "";
}

std::string Ponto::consultarRegistros(int codigoFuncionario)
{
    std::string resultado;

    bool encontrou = false;

    for (int i = 0; i < registros.size(); i++)
    {
        if (registros[i].codigoFuncionario == codigoFuncionario)
        {
            encontrou = true;

            resultado += "Data: ";
            resultado += registros[i].data;
            resultado += "\n";

            resultado += "Horario: ";
            resultado += registros[i].horario;
            resultado += "\n";

            resultado += "Tipo: ";
            resultado += registros[i].tipo;
            resultado += "\n\n";
        }
    }

    if (!encontrou)
    {
        return "Nenhum registro encontrado.\n";
    }

    return resultado;
}

std::string Ponto::consultarHistorico(int codigoFuncionario)
{
    return consultarRegistros(codigoFuncionario);
}
