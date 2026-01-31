#include <iostream>
#include <locale.h>
#include "../utilidades.h"
using namespace std;

void janela_cadastro() {
    int escolha = -1;
    while (escolha != 0) {
        limpar_tela();
        cout << "----------------------------------------\n";
        cout << "Navegação: Admin/Cadastro/\n";
        cout << "----------------------------------------\n";
        cout << "\n";
        cout << "#########  CADASTRO DE USUÁRIOS  ######\n";
        cout << "########################################\n";
        cout << "#                                      #\n";
        cout << "#  1 - Cadastrar Alunos                #\n";
        cout << "#  2 - Cadastrar Professores           #\n";
        cout << "#  3 - Cadastrar Administradores       #\n";
        cout << "#  4 - Cadastrar Vendedores            #\n";
        cout << "#  5 - Cadastrar Locadores             #\n";
        cout << "#                                      #\n";
        cout << "#  0 - Voltar                          #\n";
        cout << "#                                      #\n";
        cout << "########################################\n";
        cout << "\n";
        cout << "Escolha uma opção: ";

        cin >> escolha;
        cin.ignore();
        
        switch (escolha) {
            case 1:
                cout << "Cadastrando alunos...\n";
                break;
            case 2:
                cout << "Cadastrando professores...\n";
                break;
            case 3:
                cout << "Cadastrando administradores...\n";
                break;
            case 4:
                cout << "Cadastrando vendedores...\n";
                break;
            case 5:
                cout << "Cadastrando locadores...\n";
                break;
            case 0:
                cout << "Voltando ao painel anterior...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    }
}
