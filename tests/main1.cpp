#include <iostream>

#include "Ponto.hpp"
#include "Funcionario.hpp"
#include "RH.hpp"
#include "GerenciadorSistema.hpp"

int main()
{
    Ponto ponto;

    Funcionario funcionario(
        "Carlos",
        "1234",
        1001,
        &ponto
    );

    RH rh(
        "Joao RH",
        "9999",
        2001,
        &ponto
    );

    GerenciadorSistema sistema(&ponto);

    sistema.adicionarFuncionario(&funcionario);
    sistema.adicionarRH(&rh);

    rh.adicionarFuncionario(&funcionario);

    std::cout << "===== TESTE 4 =====\n\n";

    // 1. Login do funcionario
    Funcionario* usuario =
        sistema.login(1001, "1234");

    if (usuario == nullptr)
    {
        std::cout << "Falha no login do funcionario.\n";
        return 0;
    }

    std::cout << "Login do funcionario realizado.\n\n";

    // 2. Funcionario envia justificativa
    std::cout << "Enviando justificativa...\n";

    sistema.enviarJustificativa(
        usuario,
        "31/10/2026",
        "Consulta medica",
        "pendente"
    );

    // 3. Funcionario consulta a justificativa
    std::cout << "\n===== JUSTIFICATIVA DO FUNCIONARIO =====\n";

    std::cout << sistema.consultarJustificativas(usuario);

    // 4. RH consulta as justificativas
    std::cout << "\n===== JUSTIFICATIVAS VISTAS PELO RH =====\n";

    std::cout << rh.consultarJustificativasFuncionarios();

    // 5. Criamos uma justificativa para testar
    //    as operacoes de aceitar/rejeitar do RH
    Justificativa justificativa(
        "31/10/2026",
        "Consulta medica",
        "pendente",
        "Carlos"
    );

    std::cout << "\n===== ANTES DA ANALISE DO RH =====\n";

    justificativa.consultar();

    // 6. RH aceita
    rh.aceitarJustificativa(justificativa);

    std::cout << "\n===== DEPOIS DA ANALISE DO RH =====\n";

    justificativa.consultar();

    // 7. Funcionario consulta novamente
    std::cout << "\n===== JUSTIFICATIVA DO FUNCIONARIO NOVAMENTE =====\n";

    std::cout << sistema.consultarJustificativas(usuario);

    return 0;
}