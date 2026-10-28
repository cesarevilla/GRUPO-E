```cpp
#include "Funcionario.hpp"
#include "Ponto.hpp"

Funcionario::Funcionario(std::string nome,
                         std::string senha,
                         int codigo,
                         Ponto* ponto)
{
    this->nome = nome;
    this->senha = senha;
    this->codigo = codigo;
    this->ponto = ponto;
}

void Funcionario::registrarEntrada()
{
    ponto->registrarEntrada(codigo);
}

void Funcionario::registrarSaida()
{
    ponto->registrarSaida(codigo);
}

void Funcionario::criarJustificativa(std::string data,
                                     std::string motivo,
                                     std::string status)
{
    Justificativa j(data, motivo, status, nome);

    justificativas.push_back(j);
}

std::string Funcionario::consultarHoras()
{
    return ponto->getHorario(codigo);
}

std::string Funcionario::consultarJustificativa()
{
    // Implementar depois, quando definirmos como
    // a classe Justificativa fará a consulta.

    return "";
}

std::string Funcionario::consultarNome()
{
    return nome;
}

int Funcionario::consultarCodigo()
{
    return codigo;
}
```
