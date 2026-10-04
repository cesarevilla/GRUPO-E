#ifndef REGISTRO_PONTO_HPP
#define REGISTRO_PONTO_HPP

#include <string>

/**
 * @file RegistroPonto.hpp
 * @brief Definição da classe RegistroPonto.
 */

/**
 * @class RegistroPonto
 * @brief Responsável pelo controle e validação de batidas de ponto (check-in/check-out).
 */
class RegistroPonto {
private:
    int _idRegistro;
    int _idFuncionario;
    std::string _data;
    std::string _horarioEntrada;
    std::string _horarioSaida;
    bool _emAberto;

public:
    /**
     * @brief Construtor do RegistroPonto.
     * @param idRegistro Identificador do registro.
     * @param idFuncionario Identificador do funcionário associado.
     */
    RegistroPonto(int idRegistro, int idFuncionario);

    /**
     * @brief Registra a data e o horário exato de entrada.
     * @param data Data no formato DD/MM/AAAA.
     * @param hora Horário no formato HH:MM:SS.
     * @return Verdadeiro se o check-in foi bem-sucedido.
     */
    bool registrarEntrada(const std::string& data, const std::string& hora);

    /**
     * @brief Registra o horário exato de saída.
     * @param hora Horário no formato HH:MM:SS.
     * @return Verdadeiro se houver check-in em aberto correspondente.
     */
    bool registrarSaida(const std::string& hora);

    /**
     * @brief Verifica se existe um check-in em aberto sem check-out correspondente.
     * @return Verdadeiro se estiver em aberto.
     */
    bool estaEmAberto() const;

    /**
     * @brief Retorna o ID do funcionário associado a este registro.
     * @return ID do funcionário.
     */
    int getIdFuncionario() const;
};

#endif // REGISTRO_PONTO_HPP
