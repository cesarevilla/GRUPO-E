#include <cassert>
#include "Justificativa.hpp"

int main() {
    Justificativa j(1, 10, "20/10/2026", "Atraso");

    assert(j.getStatus() == StatusJustificativa::PENDENTE);
    assert(j.getFuncionario() == 10);
    assert(j.getData() == "20/10/2026");
    assert(j.getMotivo() == "Atraso");

    j.aceitar();
    assert(j.getStatus() == StatusJustificativa::ACEITA);

    j.rejeitar();
    assert(j.getStatus() == StatusJustificativa::REJEITADA);

    return 0;
}
