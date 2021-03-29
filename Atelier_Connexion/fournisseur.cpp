#include "fournisseur.h"

Fournisseur::Fournisseur()
{
id_Fournisseur=0;
adresse_Fournisseur="";
matricule_fiscale="";
nom_Fournisseur="";


}

Fournisseur::Fournisseur(int id,QString nom,QString adresse,QString matricule)
{this->id_Fournisseur=id;
this->adresse_Fournisseur=adresse;
this->matricule_fiscale=matricule;
this->nom_Fournisseur=nom;}


int Fournisseur::getid_Fournisseur(){return id_Fournisseur;}
void Fournisseur::setid_Fournisseur(int id){this->id_Fournisseur =id;}


QString Fournisseur::getnom_Fournisseur(){return nom_Fournisseur;}
void Fournisseur::setnom_Fournisseur(QString nom){this->nom_Fournisseur=nom;}
QString Fournisseur::getadresse_Fournisseur(){return adresse_Fournisseur;}
void Fournisseur::setadresse_Fournisseur(QString adresse){this->adresse_Fournisseur=adresse;}
QString Fournisseur::getmatricule_fiscale(){return matricule_fiscale;}
void Fournisseur::setmatricule_fiscale(QString matricule) {this->matricule_fiscale=matricule;}

bool ajouter_Fournisseur();
QSqlQueryModel * afficher_Fournisseur();
bool supprimer_Fournisseur(int);
