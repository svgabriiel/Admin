#include <iostream>
#include <cstring>
#include "servico_login.h"
#include "../utilidades.h"
#include "../headers.h"

using namespace std;


login_info janela_login() {
    limpar_tela();
    cout << "----------------------------------------\n";
    cout << "> Login/\n";
    cout << "----------------------------------------\n";
    cout << "\n";
    cout << "#########  JANELA DE LOGIN  ###########\n";
    cout << "########################################\n";
    cout << "#                                      #\n";
    cout << "#  Insira suas credenciais abaixo:     #\n";
    cout << "#                                      #\n";
    cout << "########################################\n";
    cout << "\n";

    int id_usuario;
    char senha[30];

    cout << "Digite seu ID de usuário: ";
    cin >> id_usuario;
    cin.ignore();

    cout << "Digite sua senha: ";
    cin.getline(senha, 30);

    cout << "\nFazendo verificação de login...\n";
    login_info info = validar_login(&id_usuario, senha);

    if (info.status == VALIDO) {
        cout << "Login bem-sucedido! Bem-vindo! " << ".\n";
        cout << "\n";
        cout << "identidade do usuario: \n";
        cout << "Nome: " << info.info_basica.nome << "\n"; 
        cout << "CPF: " << info.info_basica.cpf << "\n";

        cout << "Categoria: " << enumerado_para_texto(info.info_basica.categoria) << "\n"; 
        
        if (info.info_basica.especialidade != "") { 
            cout << "Especialidade: " << info.info_basica.especialidade << "\n" << "\n" << "\n";
        }
    } else {
        cout << "Falha no login. ID ou senha inválidos.\n";
    }


    system("pause");

    return info;
}

login_info validar_login(const int* id_usuario, const char* senha) {

    login_info info;

    // ===== Login engessado =====
    info.status = VALIDO;
    info.chave_acesso = ADMIN;

    // ===== Preencher info_basica com dados fixos =====
    info.info_basica.id = 1;
    info.info_basica.ativo = 1;

    generate_random_name(info.info_basica.nome);
    generate_random_cpf(info.info_basica.cpf);

    info.info_basica.categoria = ADMIN;
    std::strcpy(info.info_basica.especialidade, "Diretor(a)");

    return info;
}
