#ifndef JUSTIFICATIVA_HPP
#define JUSTIFICATIVA_HPP

#include <string>

enum class StatusJustificativa
{
    PENDENTE,
    ACEITA,
    REJEITADA
};

class Justificativa
{
private:
    std::string data;
    std::string motivo;
    StatusJustificativa status;
    std::string funcionario;

public:
    Justificativa(std::string data,
                  std::string motivo,
                  std::string status,
                  std::string funcionario);

    void consultar() const;
    void aceitar();
    void rejeitar();

    std::string getData() const;
    std::string getMotivo() const;
    StatusJustificativa getStatus() const;
    std::string getFuncionario() const;
};

#endif
