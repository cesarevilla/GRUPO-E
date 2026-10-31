#ifndef GERENCIADORSISTEMA_HPP
#define GERENCIADORSISTEMA_HPP

#include "Funcionario.hpp"
#include "RH.hpp"
#include "Ponto.hpp"
#include "Relatorio.hpp"

#include <string>
#include <vector>

class GerenciadorSistema
{
private:
    std::vector<Funcionario*> funcionarios;
    std::vector<RH*> rhs;

    Ponto* ponto;
    Relatorio* relatorio;

public:
    GerenciadorSistema(Ponto* ponto);

    void adicionarFuncionario(Funcionario* funcionario);
    void adicionarRH(RH* rh);

    Funcionario* login(int codigo, std::string senha);

    void registrarEntrada(Funcionario* funcionario);
    void registrarSaida(Funcionario* funcionario);

    std::string consultarHistorico(Funcionario* funcionario);

    void enviarJustificativa(Funcionario* funcionario,
                             std::string data,
                             std::string motivo,
                             std::string status);

    std::string consultarJustificativas(Funcionario* funcionario);

    Relatorio* getRelatorio();
};

#endif
