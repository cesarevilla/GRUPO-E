#ifndef JUSTIFICATIVA_HPP
#define JUSTIFICATIVA_HPP

#include <string>

/**
 * @file Justificativa.hpp
 * @brief Enum e classe para gestão de justificativas de falta ou ajuste de ponto.
 */

/**
 * @enum StatusJustificativa
 * @brief Situação da avaliação pelo RH.
 */
enum class StatusJustificativa {
    PENDENTE,
    ACEITA,
    REJEITADA
};

/**
 * @class Justificativa
 * @brief Representa um pedido de justificativa enviado pelo funcionário para análise do RH.
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
     * @brief Construtor da Justificativa.
     * @param id Identificador da justificativa.
     * @param idFuncionario Identificador do funcionário criador.
     * @param data Data referente à ocorrência.
     * @param motivo Texto do motivo inserido pelo funcionário.
     */
    Justificativa(int id, int idFuncionario, const std::string& data, const std::string& motivo);

    /**
     * @brief Atualiza o status da justificativa após análise do RH.
     * @param novoStatus Novo estado (ACEITA ou REJEITADA).
     */
    void atualizarStatus(StatusJustificativa novoStatus);

    /**
     * @brief Obtém o status atual da justificativa.
     * @return StatusJustificativa (PENDENTE, ACEITA, REJEITADA).
     */
    StatusJustificativa getStatus() const;

    /**
     * @brief Obtém o ID do funcionário dono da justificativa.
     * @return ID do funcionário.
     */
    int getIdFuncionario() const;
};

#endif // JUSTIFICATIVA_HPP
