#ifndef RH_HPP
#define RH_HPP

#include <string>
#include <vector>

class RH {
private:
    std::string _usuarioAdmin;
    std::string _senha;

public:
    RH(const std::string& usuario, const std::string& senha);

    bool autenticar(const std::string& usuario, const std::string& senha) const;
    void consultarFuncionario(int idFuncionario) const;
    void consultarRegistrosPonto(int idFuncionario) const;
    void consultarHorasTrabalhadas(int idFuncionario) const;
    void consultarJustificativas() const;
    void analisarJustificativa(int idJustificativa, bool aprovado);
};

#endif
