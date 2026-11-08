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
    // Dono dos objetos: todos os RH tambem ficam neste vetor.
    std::vector<Funcionario*> funcionarios;

    // Apenas referencias aos RH (a memoria e liberada via "funcionarios").
    std::vector<RH*> rhs;

    Ponto* ponto;

    Relatorio relatorio;

public:
    GerenciadorSistema(Ponto* ponto);

    ~GerenciadorSistema();

    // Evita copias acidentais (causariam delete duplo)
    GerenciadorSistema(const GerenciadorSistema&) = delete;
    GerenciadorSistema& operator=(const GerenciadorSistema&) = delete;

    // Os objetos devem ser criados com "new"
    void adicionarFuncionario(Funcionario* funcionario);

    void adicionarRH(RH* rh);

    Funcionario* login(int codigo, std::string senha);

    Funcionario* buscarPorCodigo(int codigo);

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
