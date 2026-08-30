#ifndef FORMATEURS_H
#define FORMATEURS_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
class formateurs
{
public:
    // Constructeur par défaut
    formateurs();

    // Constructeur avec paramètres
    formateurs(int id_formateur,
               QString nom,
               QString prenom,
               QString cin,
               QString email,
               QString telephone,
               QString specialite,
               QDate date_embauche);

    // Setters
    void setIdFormateur(int id);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setCin(QString cin);
    void setEmail(QString email);
    void setTelephone(QString telephone);
    void setSpecialite(QString specialite);
    void setDateEmbauche(QDate date_embauche);


    // Getters
    int getIdFormateur();
    QString getNom();
    QString getPrenom();
    QString getCin();
    QString getEmail();
    QString getTelephone();
    QString getSpecialite();
    QDate getDateEmbauche();



    //CRUD
    bool ajouter();
    bool modifier();
    bool supprimer(int id);
    QSqlQueryModel* afficher();

    bool idExists(int id);


    //metier simple
    QSqlQueryModel* chercher(QString column, QString text);
    QSqlQueryModel* tri(QString column, QString choix);

    QMap<QString, int> statistiquesParSPECIALITE();

    QString getEmailByIdFormateur(int id);

private:
    int id_formateur;
    QString nom;
    QString prenom;
    QString cin;
    QString email;
    QString telephone;
    QString specialite;
    QDate date_embauche;
};

#endif // FORMATEURS_H
