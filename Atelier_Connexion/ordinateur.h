#ifndef ORDINATEUR_H
#define ORDINATEUR_H

#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class ordinateur
{
public:
    ordinateur();
    ordinateur(int,QString,QString);
    int getid_Ordinateur();
    void setid_Ordinateur(int);
    QString get_RAM();
    void setRAM(QString);
    QString getCPU();
    void setCPU(QString);
    bool ajouter_Ordinateur();
    QSqlQueryModel * afficher_Ordinateur();
    bool supprimer_Ordinateur(int);



private:
    int id_Ordinateur;
    QString RAM;
    QString CPU;

};

#endif // ORDINATEUR_H
