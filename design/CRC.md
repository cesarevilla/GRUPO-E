CRC 01 — Funcionário: 

Responsabilidades:

Armazenar os dados do funcionário.
Identificar o funcionário.
Registrar informações de identificação.
Solicitar registro de entrada.
Solicitar registro de saída.
Consultar suas horas trabalhadas.
Criar justificativas.
Consultar suas justificativas. Colaborações:
RegistroPonto.
Justificativa
Relatório

CRC 02 — RH:
Responsabilidades:
Armazenar os dados de acesso do RH.
Consultar funcionários.
Consultar registros de ponto.
Consultar horas trabalhadas.
Consultar justificativas.
Analisar justificativas.
Aceitar justificativas.
Rejeitar justificativas.
Colaborações:
Funcionario
Justificativa
Relatorio

CRC 03 - RegistroPonto:
Identificar o funcionário antes de concluir o registro do ponto.
Registrar a data exata do check-in ou check-out.
Registrar o horário exato do check-in ou check-out.
Impedir o registro de dois check-ins consecutivos sem que haja um check-out correspondente.
Verificar no momento da saída se existe um check-in correspondente em aberto.
Associar os registros de horário de entrada e saída ao funcionário identificado.
Colaboradores: 
Funcionário 
Relatório

CRC 04 - Justificativa:
Armazenar a data da ocorrência.
Armazenar um motivo inserido pelo funcionário.
Associar a justificativa criada ao funcionário.
Manter a justificativa disponível e pendente para análise do RH.
Receber o resultado da análise feita pelo RH.
Colaboradores:
Funcionário
RH

CRC 05 - Relatório:
Apresentar os registros de um determinado período para consultas.
Apresentar os horários de cada entrada e saída.
Calcular o período trabalhado a partir dos registros de entrada e saída.
Apresentar o total de horas trabalhadas no dia/mês.
Permitir consultas detalhadas e apresentar o histórico mensal do trabalho.
Colaboradores:
Funcionário
RegistroPonto
RH

CRC 06 - GerenciadorSistema:
Identificar usuários e controlar o acesso ao sistema.
Direcionar a ação de registrar início e término de jornada para a classe correspondente.
Direcionar e administrar as requisições de consulta de histórico mensal e diário.
Associar e interligar os dados das justificativas enviadas para a tela de análise do RH.
Manter o histórico consolidado de todas as atividades (entradas, saídas e justificativas) para a administração.
Colaboradores:
Funcionário
RH
RegistroPonto
Justificativa


