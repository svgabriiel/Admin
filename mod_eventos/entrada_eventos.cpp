#include <iostream>

using namespace std;

void janela_eventos() {
    int escolha = -1;
    while (escolha != 0) {
        cout << "\nGerenciamento de Eventos da Escola\n";
        cout << "1 - Criar Novo Evento\n";
        cout << "2 - Editar Evento\n";
        cout << "3 - Listar Eventos Agendados\n";
        cout << "4 - Visualizar Inscritos em Evento\n";
        cout << "5 - Cancelar Evento\n";
        cout << "6 - Gerar Relatório de Eventos\n";
        cout << "0 - Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;
        cin.ignore();
        
        switch (escolha) {
            case 1:
                cout << "Criando novo evento...\n";
                break;
            case 2:
                cout << "Editando evento...\n";
                break;
            case 3:
                cout << "Listando eventos agendados...\n";
                break;
            case 4:
                cout << "Visualizando inscritos no evento...\n";
                break;
            case 5:
                cout << "Cancelando evento...\n";
                break;
            case 6:
                cout << "Gerando relatório de eventos...\n";
                break;
            case 0:
                cout << "Voltando ao painel anterior...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    }
}
