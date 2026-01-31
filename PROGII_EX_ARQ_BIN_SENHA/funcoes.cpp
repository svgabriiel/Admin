#include <conio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "cliente.h"
#include "funcoes.h"

void enterChoice(char& menuChoice)
{
    system("cls");
    cout << "----------------MANUTEN??O DE CONTAS----------------\n"
         << "1 - Insere informa??es em uma nova conta\n"
         << "2 - Atualiza uma conta que ja contenha informa??es\n"
         << "3 - Apaga informa??es de uma conta\n"
         << "4 - Lista os dados na tela\n"
         << "5 - Armazena os dados no arquivo texto \"print.txt\"\n"
         << "----------------------------------------------------\n"
         << "[x] Para sair pressiona qualquer outra tecla.\n"
         << "----------------------------------------------------\n";
    menuChoice = getch();
    system("cls");
}

void create(fstream &f)
{
    cliente clienteVazio = {0, "", "", 0.0};
    f.seekp(0);
    for (int i = 0; i < 100; i++)
        f.write((const char *)(&clienteVazio),sizeof(cliente));
}

void openFile(fstream &f)
{
    f.open("credito.dat", ios::in | ios::out | ios::binary);

    if (!f)
    {
        f.open("credito.dat", ios::out | ios::binary);
        f.close();
        f.open("credito.dat", ios::in | ios::out | ios::binary);
        create(f);
    }
}

bool autenticar(fstream &f, int conta, cliente &c)
{
    char senhaDigitada[10];

    f.seekg((conta - 1) * sizeof(cliente));
    f.read((char *)(&c), sizeof(cliente));

    if (c.numero == 0)
        return false;

    cout << "Informe a senha: ";
    cin >> senhaDigitada;

    return strcmp(c.senha, senhaDigitada) == 0;
}

void outputLine(ostream &output, const cliente &c, int flag)
{
    if (flag == 0)
    {
        output << setiosflags(ios::left)
        << setw(10) << c.numero
        << setw(30) << c.nome
        << setw(10) << setprecision(2) << resetiosflags(ios::left)
        << setiosflags(ios::fixed | ios::showpoint) << c.saldo << '\n';
    }
    else
    {
        output << setiosflags(ios::left)
        << setw(10) << c.numero
        << setw(30) << c.nome
        << setw(10) << c.senha
        << setw(10) << setprecision(2) << resetiosflags(ios::left)
        << setiosflags(ios::fixed | ios::showpoint) << c.saldo << '\n';
    }
}

void screen(fstream &f)
{
    cout << "----------------MANUTEN??O DE CONTAS----------------\n";
    cout << "               Lista os dados na tela               \n";
    cout << "----------------------------------------------------\n";
    cliente c;

    cout << setiosflags(ios::left)
         << setw(10) << "Conta"
         << setw(30) << "Nome"
         << resetiosflags(ios::left) << setw(10) << "Saldo" << endl;

    f.seekg(0);
    f.read((char *)(&c),sizeof(cliente));
    while(!f.eof())
    {
        if(c.numero != 0)
            outputLine(cout,c,0);
        f.read((char *)(&c),sizeof(cliente));
    }
}

void textFile(fstream &f)
{
    cout << "----------------MANUTEN??O DE CONTAS----------------\n";
    cout << "        Armazena os dados no arquivo texto          \n";
    cout << "----------------------------------------------------\n";
    cliente c;
    ofstream outPrintFile("print.txt",ios::out);

    if(! outPrintFile)
    {
        cerr << "Arquivo print.txt n?o pode ser aberto." << endl;
        exit(1);
    }

    outPrintFile << setiosflags(ios::left)
    << setw(10) << "Conta"
    << setw(30) << "Nome"
    << setw(10) << "Senha"
    << resetiosflags(ios::left) << setw(10) << "Saldo" << endl;

    f.seekg(0);
    f.read((char *)(&c),sizeof(cliente));
    while(! f.eof())
    {
        if(c.numero != 0)
            outputLine(outPrintFile,c,1);
        f.read((char *)(&c),sizeof(cliente));
    }
    outPrintFile.close();
    cout << "          Dados armazenados com sucesso!\n";
}

int getAccount(string msg)
{
    int conta;

    do
    {
        cout << msg << " (1 - 100): ";
        cin >> conta;
    }
    while (conta < 1 || conta > 100);

    return conta;
}

void updateRecord(fstream &f)
{
    cout << "----------------MANUTEN??O DE CONTAS----------------\n";
    cout << "                   Atualiza Conta                   \n";
    cout << "----------------------------------------------------\n";

    int conta;
    cliente c;
    float transacao;

    conta = getAccount("Conta a ser atualizada");

    if (!autenticar(f, conta, c))
    {
        cerr << "Conta inexistente ou senha incorreta." << endl;
        return;
    }

    outputLine(cout,c,0);
    cout << "\nEntre deposito (+) ou retirada (-): ";
    cin >> transacao;
    c.saldo += transacao;
    outputLine(cout,c,0);
    f.seekp((conta - 1) * sizeof(cliente));
    f.write((const char *)(&c),sizeof(cliente));
}

void newRecord(fstream &f)
{
    cout << "----------------MANUTEN??O DE CONTAS----------------\n";
    cout << "                     Nova Conta                     \n";
    cout << "----------------------------------------------------\n";

    int conta;
    cliente c;

    conta = getAccount("N?mero da nova conta");
    f.seekg((conta-1) * sizeof(cliente));
    f.read((char *)(&c),sizeof(cliente));
    if(c.numero == 0)
    {
        cout << "Nome: ";
        cin >> c.nome;
        cout << "Senha de acesso: ";
        cin >> c.senha;
        cout << "Saldo: R$ ";
        cin >> c.saldo;
        c.numero = conta;
        f.seekp((conta - 1) * sizeof(cliente));
        f.write((const char *)(&c),sizeof(cliente));
    }
    else
        cerr << "Conta #" << conta << " ja possui informa??o." << endl;
}

void deleteRecord(fstream &f)
{
    cout << "----------------MANUTEN??O DE CONTAS----------------\n";
    cout << "                    Apaga Conta                     \n";
    cout << "----------------------------------------------------\n";

    int conta;
    cliente c, clienteVazio = {0, "", "", 0.0};

    conta = getAccount("Conta a ser apagada");

    if (!autenticar(f, conta, c))
    {
        cerr << "Conta inexistente ou senha incorreta." << endl;
        return;
    }

    f.seekp((conta-1) * sizeof(cliente));
    f.write((const char *)(&clienteVazio),sizeof(cliente));
    cout << "Conta #" << conta << " apagada." << endl;
}
