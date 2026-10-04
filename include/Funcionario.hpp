#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include <vector>

class Funcionario {
private:
    int _id;
    std::string _nome;
    std::string _cpf;

public:
    Funcionario(int id, const std::string& nome, const std::string& cpf);

    int getId() const;
    std::string getNome() const;

    void solicitarRegistroEntrada();
    void solicitarRegistroSaida();
    double consultarHorasTrabalhadas() const;
    void criarJustificativa(const std::string& data, const std::string& motivo);
    void consultarJustificativas() const;
};

#endif
