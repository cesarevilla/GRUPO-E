#include "Funcionario.hpp"

Funcionario::Funcionario(std::string nome, std::string senha, int codigo)
{

    this->nome = nome;
    this->senha = senha;
    this->codigo = codigo;
}

void Funcionario::registrarEntrada()
{
    horario_entrada = consultarHoras();                                                 //pegar o horario formatado
    horario_minutos_entrada = getHorarioEntrada();                                    //horario em minutos, para fazer calculos PRECISO CRIAR A FUNÇÃO AINDA
}

void Funcionario::registrarSaida()
{
    horario_saida = getHorario();                                                   //pegar o horario formatado
    horario_minutos_saida = getHorarioSaida();                                        //horario em minutos, para fazer calculos PRECISO CRIAR A FUNÇÃO AINDA
}

void Funcionario::criarJustificativa(std::string data, std::string motivo, std::string status)
{
    Justificativa j(data, motivo, status, nome);
    justificativas.push_back(j);
}

std::string Funcionario::consultarHoras()
{
    Ponto p;
    return p.getHorario(codigo);
}

std::string Funcionario::consultarJustificativa()
{
    Justificativa j;
    return j.consultar(codigo);
}

std::string Funcionario::consultarNome()
{
    return nome;
}                          

int Funcionario::consultarCodigo()
{
    return codigo;
}

