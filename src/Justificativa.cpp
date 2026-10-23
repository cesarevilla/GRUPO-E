
##include "Justificativa.hpp"
#include <iostream>

Justificativa::Justificativa(int id, int idFuncionario,
                             const std::string& data,
                             const std::string& motivo)
    : _idJustificativa(id),
      _idFuncionario(idFuncionario),
      _dataOcorrencia(data),
      _motivo(motivo),
      _status(StatusJustificativa::PENDENTE) {
}

void Justificativa::consultar() const {
    std::cout << "Data: " << _dataOcorrencia << '\n';
    std::cout << "Motivo: " << _motivo << '\n';
    std::cout << "Funcionario: " << _idFuncionario << '\n';
    std::cout << "Status: " << static_cast<int>(_status) << '\n';
}

void Justificativa::aceitar() {
    _status = StatusJustificativa::ACEITA;
}

void Justificativa::rejeitar() {
    _status = StatusJustificativa::REJEITADA;
}

std::string Justificativa::getData() const {
    return _dataOcorrencia;
}

std::string Justificativa::getMotivo() const {
    return _motivo;
}

StatusJustificativa Justificativa::getStatus() const {
    return _status;
}

int Justificativa::getFuncionario() const {
    return _idFuncionario;
}
