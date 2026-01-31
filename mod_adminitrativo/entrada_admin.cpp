#include <iostream>
#include <locale.h>
#include "../headers.h"
#include "../utilidades.h"
#include "../mod_login_e_matricula/entrada_cadastro.h"

using namespace std;

void janela_admin(login_info info) {
    int i = 0;
    int escolha = -1;
    while (escolha != 0) {
        limpar_tela();
        cout << "----------------------------------------\n";
        cout << "> Administrador/\n";
        cout << "----------------------------------------\n";
        cout << enumerado_para_texto(info.chave_acesso) << " : ";
        cout << info.info_basica.nome << "\n";
        cout << "ID: " << info.info_basica.id;
        if (info.info_basica.especialidade != "") {
            cout << " - Especialidade: " << info.info_basica.especialidade << "\n";
        }
        cout << "----------------------------------------\n";
        cout << "\n";
        cout << "##########  PAINEL DO ADMINISTRADOR  ##\n";
        cout << "########################################\n";
        cout << "#                                      #\n";
        cout << "#  1 - Cadastrar                       #\n";
        cout << "#                                      #\n";
        cout << "#  0 - Sair                            #\n";
        cout << "#                                      #\n";
        cout << "########################################\n";
        cout << "\n";
        cout << "Escolha uma opção: ";
        cin >> escolha; 
        if (escolha == 1) {
            janela_cadastro();
        }  
        //chamar função de cadastro
        system("pause");
    }
}

