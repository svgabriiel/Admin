#include <conio.h>

#include <iostream>
#include "cliente.h"
#include "funcoes.h"

int main()
{
    setlocale(LC_ALL,"portuguese");

    fstream inOutCredito;
    openFile(inOutCredito);

    char opcao;
    enterChoice(opcao);
    while ( (opcao=='1') || (opcao=='2') || (opcao=='3') ||
            (opcao=='4') || (opcao=='5')
          )
    {
        switch (opcao)
        {
        case '1':
            newRecord(inOutCredito);
            break;
        case '2':
            updateRecord(inOutCredito);
            break;
        case '3':
            deleteRecord(inOutCredito);
            break;
        case '4':
            screen(inOutCredito);
            break;
        case '5':
            textFile(inOutCredito);
            break;
        default:
            cerr << "Op??o incorreta\n";
            break;
        }
        inOutCredito.clear();
        cout << "----------------------------------------------------\n";
        cout << "Pressione qualquer tecla para retornar ao [MENU].\n";
        getch();
        enterChoice(opcao);
    }
}
