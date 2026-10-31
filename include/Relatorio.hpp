#ifndef RELATORIO_HPP
#define RELATORIO_HPP

#include "Ponto.hpp"

#include <string>

class Relatorio
{
private:
    Ponto* ponto;

public:
    Relatorio(Ponto* ponto);

    std::string gerarRelatorioDiario(int codigoFuncionario,
                                     std::string data);

    std::string gerarRelatorioMensal(int codigoFuncionario,
                                     int mes,
                                     int ano);

    std::string calcularHorasTrabalhadas(int codigoFuncionario,
                                         std::string data);

    std::string consultarHistorico(int codigoFuncionario);

    std::string consultarRegistros(int codigoFuncionario);
};

#endif
