#include "Justificativa.hpp"
#include <iostream>

Justificativa::Justificativa(std::string data,
                             std::string motivo,
                             std::string status,
                             std::string funcionario)
{
    this->data = data;
    this->motivo = motivo;
    this->funcionario = funcionario;

    if (status == "pendente")
    {
        this->status = StatusJustificativa::PENDENTE;
    }
    else if (status == "aceita")
    {
        this->status = StatusJustificativa::ACEITA;
    }
    else if (status == "rejeitada")
    {
        this->status = StatusJustificativa::REJEITADA;
    }
    else
    {
        this->status = StatusJustificativa::PENDENTE;
    }
}

void Justificativa::consultar() const
{
    std::cout << "Data: " << data << '\n';
    std::cout << "Motivo: " << motivo << '\n';
    std::cout << "Funcionario: " << funcionario << '\n';

    std::cout << "Status: ";

    switch (status)
    {
        case StatusJustificativa::PENDENTE:
            std::cout << "Pendente";
            break;

        case StatusJustificativa::ACEITA:
            std::cout << "Aceita";
            break;

        case StatusJustificativa::REJEITADA:
            std::cout << "Rejeitada";
            break;
    }

    std::cout << '\n';
}

void Justificativa::aceitar()
{
    status = StatusJustificativa::ACEITA;
}

void Justificativa::rejeitar()
{
    status = StatusJustificativa::REJEITADA;
}

std::string Justificativa::getData() const
{
    return data;
}

std::string Justificativa::getMotivo() const
{
    return motivo;
}

StatusJustificativa Justificativa::getStatus() const
{
    return status;
}

std::string Justificativa::getFuncionario() const
{
    return funcionario;
}
