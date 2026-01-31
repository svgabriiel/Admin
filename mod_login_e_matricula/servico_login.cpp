#include <cstring>
#include "servico_login.h"


login_info validar_login(const int* id_usuario, const char* senha) {

    login_info info;

    // ===== Login engessado =====
    info.status = VALIDO;
    info.chave_acesso = ADMIN;

    // ===== Preencher info_basica com dados fixos =====
    info.info_basica.id = 1;
    info.info_basica.ativo = 1;

    std::strcpy(info.info_basica.nome, "Administrador Padrao");
    std::strcpy(info.info_basica.cpf, "00000000000");

    info.info_basica.categoria = ADMIN;
    std::strcpy(info.info_basica.especialidade, "Administrador");

    return info;
}
