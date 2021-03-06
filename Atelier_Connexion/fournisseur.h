#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int,QString,QString,QString);
    int getid_Fournisseur();
    void setid_Fournisseur(int);
    QString getnom_Fournisseur();
    void setnom_Fournisseur(QString);
    QString getadresse_Fournisseur();
    void setadresse_Fournisseur(QString);
    QString getmatricule_fiscale();
    void setmatricule_fiscale(QString);
    bool ajouter_Fournisseur();
    QSqlQueryModel * afficher_Fournisseur();
    bool supprimer_Fournisseur(int);



private:
    int id_Fournisseur;
    QString nom_Fournisseur;
    QString adresse_Fournisseur;
    QString matricule_fiscale;

};

#endif // FOURNISSEUR_H
