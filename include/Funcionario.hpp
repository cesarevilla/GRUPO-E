#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include <vector>

#include "Justificativa.hpp"

class Ponto;

class Funcionario
{
private:
    std::string nome;
    std::string senha;
    int codigo;
    std::vector<Justificativa> justificativas;
    Ponto* ponto;

    friend class RH;

    void aceitarJustificativa(int indice);
    void rejeitarJustificativa(int indice);

public:
    Funcionario(std::string nome,
                std::string senha,
                int codigo,
                Ponto* ponto);

    virtual ~Funcionario() = default;

    void registrarEntrada();
    void registrarSaida();

    void criarJustificativa(std::string data,
                            std::string motivo,
                            std::string status);

    std::string consultarHoras();
    std::string consultarJustificativa();
    std::string consultarNome();
    int consultarCodigo();
    bool verificarSenha(std::string senha);
};

#endif