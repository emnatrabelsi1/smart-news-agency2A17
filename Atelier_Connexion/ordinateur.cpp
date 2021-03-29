#include "ordinateur.h"

ordinateur::ordinateur()
{
id_Ordinateur=0;
RAM="";
CPU="";
}

ordinateur::ordinateur(int id,QString ram1,QString cpu1)
{this->id_Ordinateur=id;
this->RAM=ram1;
this->CPU=cpu1;}



int ordinateur::getid_Ordinateur() {return id_Ordinateur;}
void ordinateur::setid_Ordinateur(int id) {this->id_Ordinateur=id;}
QString ordinateur::get_RAM(){return RAM;}
void ordinateur::setRAM(QString ram1) {this->RAM=ram1;}
QString ordinateur::getCPU() {return CPU;}
void ordinateur::setCPU(QString cpu1) {this->CPU=cpu1;}

bool ajouter_Ordinateur();
QSqlQueryModel * afficher_Ordinateur();
bool supprimer_Ordinateur(int);
