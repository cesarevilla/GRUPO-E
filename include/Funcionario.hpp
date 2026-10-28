#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>


class Funcionario
{
    private:
        std::string nome;
        std::string senha;
        int codigo;

    public:
        void registrarEntrada();                             //funcao que vai registrar quando o funcionario entrou no expediente
        void registrarSaida();                               //funcao que vai registrar quando o funcionario saiu do expediente
        void criarJustificativa();                           //cria justificativas de faltas
        std::string consultarHoras();                        //conslutas os horarios de entrada e saida
        std::string consultarJustificativa();                //consulta as justificativas
        std::string consultarNome();                                
        int consultarCodigo();
};

#endif