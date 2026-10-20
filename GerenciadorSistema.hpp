#ifndef GERENCIADOR_SISTEMA_HPP
#define GERENCIADOR_SISTEMA_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Funcionario.hpp"
#include "RH.hpp"
#include "Ponto.hpp"
#include "Justificativa.hpp"
#include "Relatorio.hpp"

using namespace std;

class GerenciadorSistema {
private:
    vector<Funcionario*> funcionarios;
    vector<RH*> rhs;
    vector<Ponto> pontos;
    vector<Justificativa> justificativas;
    Relatorio relatorio;

public:
    Funcionario* login(string codigo, string senha);

    void registrarEntrada(Funcionario* funcionario);
    void registrarSaida(Funcionario* funcionario);
    void consultarHistorico(Funcionario* funcionario);
    void enviarJustificativa(Funcionario* funcionario);
    void consultarJustificativas(Funcionario* funcionario);
};


// LOGIN
inline Funcionario* GerenciadorSistema::login(
    string codigo,
    string senha
) {
    for (Funcionario* funcionario : funcionarios) {
        if (funcionario->consultarCodigo() == codigo &&
            funcionario->autenticar(senha)) {
            return funcionario;
        }
    }

    return nullptr;
}


// REGISTRAR ENTRADA
inline void GerenciadorSistema::registrarEntrada(
    Funcionario* funcionario
) {
    if (funcionario == nullptr) {
        cout << "Usuario nao autenticado." << endl;
        return;
    }

    funcionario->registrarEntrada();
}


// REGISTRAR SAIDA
inline void GerenciadorSistema::registrarSaida(
    Funcionario* funcionario
) {
    if (funcionario == nullptr) {
        cout << "Usuario nao autenticado." << endl;
        return;
    }

    funcionario->registrarSaida();
}


// CONSULTAR HISTORICO
inline void GerenciadorSistema::consultarHistorico(
    Funcionario* funcionario
) {
    if (funcionario == nullptr) {
        cout << "Usuario nao autenticado." << endl;
        return;
    }

    relatorio.consultarHistorico(
        funcionario->consultarNome()
    );
}


// ENVIAR JUSTIFICATIVA
inline void GerenciadorSistema::enviarJustificativa(
    Funcionario* funcionario
) {
    if (funcionario == nullptr) {
        cout << "Usuario nao autenticado." << endl;
        return;
    }

    string data;
    string motivo;

    cout << "Informe a data (DD/MM/AAAA): ";
    getline(cin >> ws, data);

    cout << "Informe o motivo da justificativa: ";
    getline(cin, motivo);

    justificativas.emplace_back(
        data,
        motivo,
        funcionario->consultarNome()
    );

    funcionario->criarJustificativa();
}


// CONSULTAR JUSTIFICATIVAS
inline void GerenciadorSistema::consultarJustificativas(
    Funcionario* funcionario
) {
    if (funcionario == nullptr) {
        cout << "Usuario nao autenticado." << endl;
        return;
    }

    for (const Justificativa& justificativa : justificativas) {
        if (justificativa.getFuncionario() ==
            funcionario->consultarNome()) {
            justificativa.consultar();
        }
    }
}

#endif
