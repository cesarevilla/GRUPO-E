#include <iostream>
#include "httplib.h"
#include "GerenciadorSistema.hpp"
#include "Funcionario.hpp"
#include "RH.hpp"
#include "Ponto.hpp"

static const char* PAGINA = R"HTML(
<!DOCTYPE html>
<html lang="pt-br"><head><meta charset="utf-8">
<title>Sistema de Ponto</title>
<style>
 body{font-family:sans-serif;max-width:640px;margin:30px auto;padding:0 12px}
 input,button{padding:8px;margin:3px}
 pre{background:#f2f2f2;padding:12px;min-height:150px;white-space:pre-wrap}
</style></head><body>
<h2>Sistema de Ponto</h2>
<div><input id="cod" placeholder="Código"><input id="senha" type="password" placeholder="Senha">
<button onclick="enviar('/login',{codigo:cod.value,senha:senha.value})">Entrar</button></div>
<div>
 <button onclick="enviar('/entrada')">Registrar entrada</button>
 <button onclick="enviar('/saida')">Registrar saída</button>
 <button onclick="enviar('/historico')">Histórico</button>
 <button onclick="enviar('/justificativas')">Ver justificativas</button>
</div>
<div><input id="data" placeholder="DD/MM/AAAA"><input id="motivo" placeholder="Motivo" size="30">
<button onclick="enviar('/justificativa',{data:data.value,motivo:motivo.value})">Enviar justificativa</button></div>
<pre id="saida"></pre>
<script>
async function enviar(rota, dados){
  const r = await fetch(rota,{method:'POST',body:new URLSearchParams(dados||{})});
  document.getElementById('saida').textContent = await r.text();
}
</script></body></html>
)HTML";

int main() {
    // ===== USUÁRIOS DE TESTE (troque pelos reais quando quiser) =====
    Ponto* ponto = new Ponto();
    GerenciadorSistema sistema(ponto);

    Funcionario* ana   = new Funcionario("Ana",   "123", 1, ponto);
    Funcionario* bruno = new Funcionario("Bruno", "456", 2, ponto);
    RH* carla          = new RH("Carla", "789", 100, ponto);

    sistema.adicionarFuncionario(ana);
    sistema.adicionarFuncionario(bruno);
    sistema.adicionarRH(carla);

    carla->adicionarFuncionario(ana);
    carla->adicionarFuncionario(bruno);
    // ================================================================

    Funcionario* logado = nullptr;
    httplib::Server svr;
    const char* TXT = "text/plain; charset=utf-8";

    svr.Get("/", [&](const httplib::Request&, httplib::Response& res) {
        res.set_content(PAGINA, "text/html; charset=utf-8");
    });

    svr.Post("/login", [&](const httplib::Request& req, httplib::Response& res) {
        try {
            logado = sistema.login(std::stoi(req.get_param_value("codigo")),
                                   req.get_param_value("senha"));
        } catch (...) { logado = nullptr; }
        res.set_content(logado ? "Login realizado: " + logado->consultarNome()
                               : std::string("Codigo ou senha invalidos."), TXT);
    });

    svr.Post("/entrada", [&](const httplib::Request&, httplib::Response& res) {
        if (!logado) { res.set_content("Faca login primeiro.", TXT); return; }
        sistema.registrarEntrada(logado);
        res.set_content("Entrada registrada.", TXT);
    });

    svr.Post("/saida", [&](const httplib::Request&, httplib::Response& res) {
        if (!logado) { res.set_content("Faca login primeiro.", TXT); return; }
        sistema.registrarSaida(logado);
        res.set_content("Saida registrada.", TXT);
    });

    svr.Post("/historico", [&](const httplib::Request&, httplib::Response& res) {
        res.set_content(sistema.consultarHistorico(logado), TXT);
    });

    svr.Post("/justificativas", [&](const httplib::Request&, httplib::Response& res) {
        res.set_content(sistema.consultarJustificativas(logado), TXT);
    });

    svr.Post("/justificativa", [&](const httplib::Request& req, httplib::Response& res) {
        if (!logado) { res.set_content("Faca login primeiro.", TXT); return; }
        sistema.enviarJustificativa(logado, req.get_param_value("data"),
                                    req.get_param_value("motivo"), "Pendente");
        res.set_content("Justificativa enviada.", TXT);
    });

    std::cout << "Servidor rodando na porta 8080" << std::endl;
    svr.listen("0.0.0.0", 8080);
}
