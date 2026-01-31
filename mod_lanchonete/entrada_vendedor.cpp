#include <iostream>
#include <locale.h>
#include "../headers.h"
#include "../utilidades.h"

using namespace std;

void janela_vendedor(login_info info) {
    int escolha = -1;
    while (escolha != 0) {
        limpar_tela();
        cout << "----------------------------------------\n";
        cout << "Navegação: Vendedor/\n";
        cout << "----------------------------------------\n";
        cout << "\n";
        cout << "###  GERENCIADOR DE LANCHONETE  #####\n";
        cout << "########################################\n";
        cout << "#                                      #\n";
        cout << "#  1 - Adicionar Produto               #\n";
        cout << "#  2 - Remover Produto                 #\n";
        cout << "#  3 - Visualizar Estoque              #\n";
        cout << "#  4 - Registrar Venda                 #\n";
        cout << "#  5 - Visualizar Vendas               #\n";
        cout << "#                                      #\n";
        cout << "#  0 - Voltar                          #\n";
        cout << "#                                      #\n";
        cout << "########################################\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;
        cin.ignore();
        
        switch (escolha) {
            case 1:
                cout << "Adicionar produto...\n";
                break;
            case 2:
                cout << "Remover produto...\n";
                break;
            case 3:
                cout << "Visualizando estoque...\n";
                break;
            case 4:
                cout << "Registrando venda...\n";
                break;
            case 5:
                cout << "Visualizando vendas...\n";
                break;
            case 0:
                cout << "Voltando ao painel anterior...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    }
}
