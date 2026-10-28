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

public:
    Funcionario(std::string nome, std::string senha, int codigo, Ponto* ponto);

    void registrarEntrada();
    void registrarSaida();

    void criarJustificativa(std::string data,
                            std::string motivo,
                            std::string status);

    std::string consultarHoras();
    std::string consultarJustificativa();

    std::string consultarNome();
    int consultarCodigo();
};

#endif
