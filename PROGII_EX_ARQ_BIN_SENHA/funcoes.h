#ifndef FUNCOES_H
#define FUNCOES_H

#include <fstream>
using namespace std;
void enterChoice(char& menuChoice);
void create(fstream &f);
void openFile(fstream &f);
bool autenticar(fstream &f, int conta, cliente &c);
void outputLine(ostream &output, const cliente &c, int flag);
void screen(fstream &f);
void textFile(fstream &f);
int getAccount(string msg);
void updateRecord(fstream &f);
void newRecord(fstream &f);
void deleteRecord(fstream &f);

#endif
