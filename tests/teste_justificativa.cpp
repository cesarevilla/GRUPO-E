
#include <cassert>
#include <iostream>
#include "Justificativa.hpp"

int main() {
    Justificativa j(1, 10, "20/10/2026", "Atraso");

    assert(j.getStatus() == StatusJustificativa::PENDENTE);
    assert(j.getIdFuncionario() == 10);

    j.atualizarStatus(StatusJustificativa::ACEITA);
    assert(j.getStatus() == StatusJustificativa::ACEITA);

    j.atualizarStatus(StatusJustificativa::REJEITADA);
    assert(j.getStatus() == StatusJustificativa::REJEITADA);

    std::cout << "Todos os testes passaram!" << std::endl;

    return 0;
}
