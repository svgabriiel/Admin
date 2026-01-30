#include <iostream>
#include <fstream>

void inicializarArquivo();

using namespace std;

struct pessoa
{
    int id;
    char nome[30];
};

int main()
{
    pessoa p;
    inicializarArquivo();
    //escrita
    ofstream arqOut("pessoa.dat",ios::binary);

    if(!arqOut)
    {
        cout<<"erro ao abrir o arquivo";
        return 1;
    }

    int pos;
    cout<<"insira a posicão de 1 a 10: ";
    cin>>pos;
    while(pos <= 10 && pos > 0)
    {
        cout<<"insira o id: ";
        cin>>p.id;
        cin.ignore();
        cout<<"insira o nome: ";
        cin.getline(p.nome,30);

        arqOut.seekp((pos - 1)*sizeof(pessoa));
        arqOut.write((char*)&p,sizeof(pessoa));

        cout<<"insira a posicão de 1 a 10: ";
        cin>>pos;
    }
    arqOut.close();

    //leitura
    ifstream arqIn("pessoa.dat",ios::binary);
    if(!arqIn)
    {
        cout<<"erro ao abrir o arquivo";
        return 1;
    }
    int position;

    cout<<"\nDigite a posição a qual deseja ler: \n";
    cin>>position;
    while(position <=10 && position > 0)
    {
        arqIn.seekg((position - 1)*sizeof(pessoa));
        arqIn.read((char*)&p,sizeof(pessoa));
        cout<<"id: "<<p.id<<endl;
        cout<<"nome: "<<p.nome<<endl<<endl;
        cout<<"\nDigite a posição a qual deseja ler: \n";
        cin>>position;
    }
    arqIn.close();

    return 0;
}

void inicializarArquivo()
{
    pessoa p;
    ofstream arq("pessoa.dat",ios::binary);

    if(!arq)
    {
        cout<<"erro ao abrir o arquivo";
    }

    pessoa vazia = {0,""};

    for(int i = 0;i < 10; i++)
    {
        arq.write((char*)&vazia,sizeof(pessoa));
    }
    arq.close();
}
