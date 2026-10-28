#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include <vector>
#include "Justificativa.hpp"
#include "Ponto.hpp"



class Funcionario
{
    private:
        std::string nome;
        std::string senha;
        int codigo;

        std::vector<Justificativa> justificativas;

        int horario_minutos_entrada;
        int horario_minutos_saida;

        std::string horario_entrada;
        std::string horario_saida;

    public:
        Funcionario(std::string nome, std::string senha, int codigo);
        void registrarEntrada();                                                                                       //funcao que vai registrar quando o funcionario entrou no expediente
        void registrarSaida();                                                                                         //funcao que vai registrar quando o funcionario saiu do expediente
        void criarJustificativa(std::string data, std::string motivo, std::string status);                             //cria justificativas de faltas
        std::string consultarHoras();                                                                                  //conslutas os horarios de entrada e saida
        std::string consultarJustificativa();                                                                          //consulta as justificativas
        std::string consultarNome();                                
        int consultarCodigo();
};

#endif
