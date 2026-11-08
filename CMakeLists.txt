cmake_minimum_required(VERSION 3.16)

project(SistemaDePontos
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Arquivos-fonte
set(SOURCES
    src/Funcionario.cpp
    src/GerenciadorSistema.cpp
    src/Justificativa.cpp
    src/Ponto.cpp
    src/Relatorio.cpp
    src/RH.cpp
)

# Executável
add_executable(SistemaDePontos
    ${SOURCES}
    tests/main.cpp
)

# Diretório dos headers
target_include_directories(SistemaDePontos
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)