#ifndef PONTO_HPP
#define PONTO_HPP

#include <string>
#include <vector>

class Ponto
{
private:
    struct Registro
    {
        std::string data;
        std::string horario;
        std::string tipo;
        int codigoFuncionario;
    };

    std::vector<Registro> registros;

public:
    void registrarEntrada(int codigoFuncionario);
    void registrarSaida(int codigoFuncionario);

    std::string getData(int codigoFuncionario);
    std::string getHorario(int codigoFuncionario);
    std::string getTipo(int codigoFuncionario);
    int getFuncionario(int codigoFuncionario);
};

#endif
