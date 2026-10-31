#include "Relatorio.hpp"

#include <string>

Relatorio::Relatorio(Ponto* ponto)
{
    this->ponto = ponto;
}

std::string Relatorio::gerarRelatorioDiario(int codigoFuncionario,
                                            std::string data)
{
    std::string resultado;

    resultado += "RELATORIO DIARIO\n";
    resultado += "Funcionario: ";
    resultado += std::to_string(codigoFuncionario);
    resultado += "\n";

    resultado += "Data: ";
    resultado += data;
    resultado += "\n\n";

    resultado += consultarRegistros(codigoFuncionario);

    resultado += "\n";
    resultado += calcularHorasTrabalhadas(codigoFuncionario, data);

    return resultado;
}

std::string Relatorio::gerarRelatorioMensal(int codigoFuncionario,
                                            int mes,
                                            int ano)
{
    std::string resultado;

    resultado += "RELATORIO MENSAL\n";
    resultado += "Funcionario: ";
    resultado += std::to_string(codigoFuncionario);
    resultado += "\n";

    resultado += "Mes: ";
    resultado += std::to_string(mes);
    resultado += "/";
    resultado += std::to_string(ano);
    resultado += "\n\n";

    resultado += consultarHistorico(codigoFuncionario);

    return resultado;
}

std::string Relatorio::calcularHorasTrabalhadas(int codigoFuncionario,
                                                std::string data)
{
    std::string entrada = ponto->getHorarioEntrada(codigoFuncionario, data);
    std::string saida = ponto->getHorarioSaida(codigoFuncionario, data);

    if (entrada == "" || saida == "")
    {
        return "Nao foi possivel calcular as horas trabalhadas.";
    }

    int horaEntrada = std::stoi(entrada.substr(0, 2));
    int minutoEntrada = std::stoi(entrada.substr(3, 2));
    int segundoEntrada = std::stoi(entrada.substr(6, 2));

    int horaSaida = std::stoi(saida.substr(0, 2));
    int minutoSaida = std::stoi(saida.substr(3, 2));
    int segundoSaida = std::stoi(saida.substr(6, 2));

    int segundosEntrada =
        horaEntrada * 3600 +
        minutoEntrada * 60 +
        segundoEntrada;

    int segundosSaida =
        horaSaida * 3600 +
        minutoSaida * 60 +
        segundoSaida;

    int segundosTrabalhados = segundosSaida - segundosEntrada;

    if (segundosTrabalhados < 0)
    {
        return "Erro: horario de saida anterior ao horario de entrada.";
    }

    int horas = segundosTrabalhados / 3600;
    int minutos = (segundosTrabalhados % 3600) / 60;
    int segundos = segundosTrabalhados % 60;

    std::string resultado;

    resultado += "Horas trabalhadas: ";
    resultado += std::to_string(horas);
    resultado += "h ";
    resultado += std::to_string(minutos);
    resultado += "min ";
    resultado += std::to_string(segundos);
    resultado += "s";

    return resultado;
}

std::string Relatorio::consultarHistorico(int codigoFuncionario)
{
    return ponto->consultarHistorico(codigoFuncionario);
}

std::string Relatorio::consultarRegistros(int codigoFuncionario)
{
    return ponto->consultarRegistros(codigoFuncionario);
}
