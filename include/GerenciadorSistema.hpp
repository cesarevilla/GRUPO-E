#ifndef GERENCIADOR_SISTEMA_HPP
#define GERENCIADOR_SISTEMA_HPP

#include "Funcionario.hpp"
#include "RH.hpp"
#include "RegistroPonto.hpp"
#include "Justificativa.hpp"
#include "Relatorio.hpp"
#include <vector>

/**
 * @file GerenciadorSistema.hpp
 * @brief Definição do orquestrador principal do sistema.
 */

/**
 * @class GerenciadorSistema
 * @brief Classe principal que gerencia o fluxo de controle, autenticação e dados do sistema.
 */
class GerenciadorSistema {
private:
    std::vector<Funcionario> _funcionarios;
    std::vector<RegistroPonto> _registros;
    std::vector<Justificativa> _justificativas;

public:
    /**
     * @brief Construtor do GerenciadorSistema.
     */
    GerenciadorSistema();

    /**
     * @brief Controla o acesso e valida credenciais do usuário.
     * @param idUsuario Identificador ou usuário cadastrado.
     * @return Verdadeiro se o login for válido.
     */
    bool autenticarUsuario(int idUsuario);

    /**
     * @brief Direciona a requisição de entrada ou saída para a classe RegistroPonto.
     * @param idFuncionario Identificador do funcionário.
     * @param ehEntrada Verdadeiro se for entrada, falso se for saída.
     */
    void registrarJornada(int idFuncionario, bool ehEntrada);

    /**
     * @brief Administra e exibe requisições de histórico diário e mensal.
     * @param idFuncionario Identificador do funcionário.
     */
    void processarConsultaHistorico(int idFuncionario);

    /**
     * @brief Encaminha justificativa criada para a fila de análise do RH.
     * @param justificativa Objeto da justificativa gerada.
     */
    void enviarJustificativaParaRH(const Justificativa& justificativa);

    /**
     * @brief Mantém o histórico consolidado de todas as atividades para uso administrativo.
     */
    void exibirHistoricoGeral() const;
};

#endif // GERENCIADOR_SISTEMA_HPP
