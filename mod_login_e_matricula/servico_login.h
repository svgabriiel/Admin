#ifndef SERVICO_LOGIN_H
#define SERVICO_LOGIN_H

#include "../headers.h"

// Exibe a janela de login e retorna as informações do usuário autenticado
login_info janela_login();

// valida login (versão engessada - sempre ADMIN)
login_info validar_login(const int* id_usuario, const char* senha);

#endif
