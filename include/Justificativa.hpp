/**
 * @file Justificativa.hpp
 * @brief Declara a classe Justificativa.
 */

#ifndef JUSTIFICATIVA_HPP
#define JUSTIFICATIVA_HPP

#include <string>

/**
 * @enum StatusJustificativa
 * @brief Representa os possíveis estados da justificativa.
 */
enum class StatusJustificativa {
    PENDENTE,
    ACEITA,
    REJEITADA
};

/**
 * @class Justificativa
 * @brief Representa uma justificativa enviada por um funcionário.
 */
class Justificativa {
private:
    int _idJustificativa;
    int _idFuncionario;
    std::string _dataOcorrencia;
    std::string _motivo;
    StatusJustificativa _status;

public:
    /**
     * @brief Cria uma justificativa com status pendente.
     */
    Justificativa(int id, int idFuncionario,
                  const std::string& data,
                  const std::string& motivo);

    /** @brief Consulta os dados da justificativa. */
    void consultar() const;

    /** @brief Aceita a justificativa. */
    void aceitar();

    /** @brief Rejeita a justificativa. */
    void rejeitar();

    /** @brief Retorna a data da ocorrência. */
    std::string getData() const;

    /** @brief Retorna o motivo da justificativa. */
    std::string getMotivo() const;

    /** @brief Retorna o status atual. */
    StatusJustificativa getStatus() const;

    /** @brief Retorna o identificador do funcionário associado. */
    int getFuncionario() const;
};

#endif
