#ifndef RELATORIO_HPP
#define RELATORIO_HPP

#include <string>
#include <vector>

/**
 * @file Relatorio.hpp
 * @brief Definição da classe Relatorio.
 */

/**
 * @class Relatorio
 * @brief Consolida dados de frequência para geração de histórico mensal/diário e calculo de horas.
 */
class Relatorio {
private:
    int _idFuncionario;
    std::string _periodoInicio;
    std::string _periodoFim;

public:
    /**
     * @brief Construtor do Relatorio.
     * @param idFuncionario Identificador do funcionário.
     * @param inicio Data inicial do período.
     * @param fim Data final do período.
     */
    Relatorio(int idFuncionario, const std::string& inicio, const std::string& fim);

    /**
     * @brief Apresenta o histórico de batidas de entrada e saída.
     */
    void apresentarRegistros() const;

    /**
     * @brief Calcula a carga horária trabalhada com base nos horários de entrada e saída.
     * @return Total de horas em formato numérico.
     */
    double calcularHorasTrabalhadas() const;

    /**
     * @brief Exibe o consolidado mensal de horas trabalhadas.
     */
    void apresentarTotalHorasMensal() const;
};

#endif // RELATORIO_HPP
