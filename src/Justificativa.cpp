
#include "Justificativa.hpp"

Justificativa::Justificativa(int id, int idFuncionario,
                             const std::string& data,
                             const std::string& motivo)
    : _idJustificativa(id),
      _idFuncionario(idFuncionario),
      _dataOcorrencia(data),
      _motivo(motivo),
      _status(StatusJustificativa::PENDENTE) {
}

void Justificativa::atualizarStatus(StatusJustificativa novoStatus) {
    _status = novoStatus;
}

StatusJustificativa Justificativa::getStatus() const {
    return _status;
}

int Justificativa::getIdFuncionario() const {
    return _idFuncionario;
}
