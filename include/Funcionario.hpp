#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include <vector>

/**
 * @file Funcionario.hpp
 * @brief Definição da classe Funcionario.
 */

/**
 * @class Funcionario
 * @brief Representa um funcionário e gerencia suas informações e ações no sistema de ponto.
 */
class Funcionario {
private:
    int _id;
    std::string _nome;
    std::string _cpf;

public:
    /**
     * @brief Construtor da classe Funcionario.
     * @param id Identificador único do funcionário.
     * @param nome Nome completo.
     * @param cpf CPF do funcionário.
     */
    Funcionario(int id, const std::string& nome, const std::string& cpf);

    /**
     * @brief Obtém o ID do funcionário.
     * @return Identificador do funcionário.
     */
    int getId() const;

    /**
     * @brief Obtém o nome do funcionário.
     * @return Nome do funcionário.
     */
    std::string getNome() const;

    /**
     * @brief Solicita o registro de entrada (check-in) no sistema.
     */
    void solicitarRegistroEntrada();

    /**
     * @brief Solicita o registro de saída (check-out) no sistema.
     */
    void solicitarRegistroSaida();

    /**
     * @brief Consulta as horas trabalhadas em determinado período.
     * @return Total de horas trabalhadas em formato decimal/duplo.
     */
    double consultarHorasTrabalhadas() const;

    /**
     * @brief Cria uma nova justificativa de ausência/ponto.
     * @param data Data da ocorrência.
     * @param motivo Descrição da justificativa.
     */
    void criarJustificativa(const std::string& data, const std::string& motivo);

    /**
     * @brief Exibe no console as justificativas enviadas pelo funcionário.
     */
    void consultarJustificativas() const;
};

#endif // FUNCIONARIO_HPP
