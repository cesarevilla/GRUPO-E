SISTEMA DE CONTROLE DE PONTO
==============================

Descrição
---------
Sistema de controle de ponto desenvolvido em C++, com arquitetura orientada
a objetos. O sistema permite o gerenciamento de funcionários, registros de
entrada e saída, justificativas, usuários de RH e geração de relatórios.

O projeto foi estruturado de forma modular, separando as responsabilidades
entre as classes responsáveis pelo domínio do sistema e uma camada de
interação com o usuário.

Funcionalidades
---------------
- Login de funcionários e usuários de RH.
- Registro de entrada.
- Registro de saída.
- Registro automático da data e do horário do computador.
- Consulta do histórico de registros de ponto.
- Criação de justificativas.
- Consulta de justificativas.
- Consulta de justificativas de todos os funcionários pelo RH.
- Aceitação de justificativas pelo RH.
- Rejeição de justificativas pelo RH.
- Consulta de funcionários cadastrados.
- Consulta dos horários registrados pelos funcionários.
- Geração de relatório diário.
- Geração de relatório mensal.
- Tratamento de entradas inválidas.
- Proteção contra operações com funcionários inexistentes ou ponteiros nulos.

Estrutura do Projeto
--------------------
include/
    Funcionario.hpp
    GerenciadorSistema.hpp
    Justificativa.hpp
    Ponto.hpp
    Relatorio.hpp
    RH.hpp

src/
    Funcionario.cpp
    GerenciadorSistema.cpp
    Justificativa.cpp
    Ponto.cpp
    Relatorio.cpp
    RH.cpp

tests/
    main1.cpp

Principais Classes
------------------
Funcionario
    Representa um funcionário do sistema. É responsável por operações
    relacionadas ao registro de ponto e às suas próprias justificativas.

RH
    Especialização de Funcionario responsável pelas operações administrativas,
    incluindo consulta de funcionários, consulta de justificativas e decisão
    sobre justificativas.

Ponto
    Responsável pelo armazenamento dos registros de entrada e saída. A data
    e o horário são obtidos automaticamente a partir do relógio do sistema
    operacional.

Justificativa
    Representa uma justificativa enviada por um funcionário. Possui três
    estados possíveis: PENDENTE, ACEITA e REJEITADA.

Relatorio
    Responsável pela geração de relatórios diários e mensais e pelo cálculo
    das horas trabalhadas.

GerenciadorSistema
    Atua como camada central de coordenação entre os usuários e as demais
    classes do sistema, encaminhando as operações para os objetos responsáveis.

Registro de Data e Hora
-----------------------
O horário dos registros não é informado manualmente pelo usuário.

A classe Ponto utiliza as funções da biblioteca padrão de C++:

    std::time(nullptr)
    std::localtime(...)

Essas funções obtêm a data e o horário atuais configurados no computador
em que o programa está sendo executado.

O registro é armazenado no formato:

    Data:     dd/mm/aaaa
    Horário:  hh:mm:ss

Tecnologias
-----------
- C++
- C++17
- Programação Orientada a Objetos
- Biblioteca padrão do C++

Compilação
----------
O projeto pode ser compilado com o compilador g++ utilizando C++17.

Comando:

    g++ -std=c++17 -Iinclude src\Funcionario.cpp src\GerenciadorSistema.cpp src\Justificativa.cpp src\Ponto.cpp src\Relatorio.cpp src\RH.cpp tests\main1.cpp -o tests\main1.exe

Execução
--------
Após a compilação:

    .\tests\main1.exe

Usuários de Teste
-----------------
Funcionário:
    Nome: Carlos
    Código: 1
    Senha: 1234

Funcionário:
    Nome: Maria
    Código: 2
    Senha: 5678

Administrador / RH:
    Nome: Administrador
    Código: 100
    Senha: admin

Interface
---------
A versão atual possui uma interface interativa baseada em terminal.

Após iniciar o programa, o usuário informa seu código e senha. De acordo
com o usuário autenticado, o sistema apresenta o menu correspondente.

Menu do Funcionário:
    1 - Registrar entrada
    2 - Registrar saída
    3 - Consultar histórico
    4 - Criar justificativa
    5 - Consultar justificativas
    6 - Relatório diário
    7 - Relatório mensal
    0 - Sair da conta

Menu do RH:
    1 - Consultar funcionários
    2 - Consultar registros de funcionário
    3 - Consultar horas dos funcionários
    4 - Consultar justificativas
    5 - Aceitar justificativa
    6 - Rejeitar justificativa
    0 - Sair da conta

Estados das Justificativas
--------------------------
PENDENTE
    Estado inicial de uma justificativa.

ACEITA
    Estado atribuído quando o RH aprova uma justificativa.

REJEITADA
    Estado atribuído quando o RH rejeita uma justificativa.

Arquitetura
-----------
O sistema utiliza composição, agregação, herança e encapsulamento para
organizar suas responsabilidades.

A classe RH herda de Funcionario.

O GerenciadorSistema mantém referências para funcionários e usuários de RH
e coordena o acesso às funcionalidades do sistema.

A classe Relatorio utiliza a classe Ponto para consultar os registros e
calcular informações relacionadas à jornada.

A classe Funcionario mantém suas justificativas e utiliza a classe Ponto
para registrar suas entradas e saídas.

Objetivo do Projeto
-------------------
O projeto tem como objetivo implementar um sistema de controle de ponto
utilizando conceitos de programação orientada a objetos em C++, com
separação de responsabilidades entre as entidades do sistema.