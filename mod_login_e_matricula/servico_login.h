#ifndef SERVICO_LOGIN_H
#define SERVICO_LOGIN_H

#include "../headers.h"

// valida login (versão engessada — sempre ADMIN)
login_info validar_login(const int* id_usuario, const char* senha);

#endif
