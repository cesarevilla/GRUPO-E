#ifndef RH_HPP
#define RH_HPP

#include "Funcionario.hpp"
#include "Justificativa.hpp"

#include <string>
#include <vector>

class RH : public Funcionario
{
private:
    std::vector<Funcionario*> funcionarios;

public:
    RH(std::string nome,
       std::string senha,
       int codigo,
       Ponto* ponto);

    void adicionarFuncionario(Funcionario* funcionario);

    std::string consultarFuncionarios();
    std::string consultarRegistros(Funcionario* funcionario);
    std::string consultarHorasFuncionarios();
    std::string consultarJustificativasFuncionarios();

    void aceitarJustificativa(Justificativa& justificativa);
    void rejeitarJustificativa(Justificativa& justificativa);
};

#endif
