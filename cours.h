#ifndef COURS_H
#define COURS_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
class COURS
{
public:
    // Constructeur par défaut
    COURS();

    // Constructeur avec paramètres
    COURS(int ID_COUR,
          QString nom,
          QString description,
          QDate date_debut,
          QDate date_fin,
          int prix,
          QString niveau,
          int id_formateur);

    // Setters
    void setIdCour(int id);
    void setNom(QString nom);
    void setDescription(QString description);
    void setDateDebut(QDate date_debut);
    void setDateFin(QDate date_fin);
    void setPrix(int prix);
    void setNiveau(QString niveau);
    void setIdFormateur(int id_formateur);
    // Getters
    int getIdCour();
    QString getNom();
    QString getDescription();
    QDate getDateDebut();
    QDate getDateFin();
    int getPrix();
    QString getNiveau();

    int getIdFormateur();



    //CRUD
    bool ajouter();
    bool modifier();
    bool supprimer(int id);
    QSqlQueryModel* afficher();

    bool idExists(int id);


    QList<int> ListIdFORMATEUR();

    QSqlQueryModel* chercher(QString column, QString text);
    QSqlQueryModel* tri(QString column, QString choix);
    QMap<QString, int> statistiquesParNiveau();

    QList<QDate> getDatesFromDatabase();
    QSqlQueryModel* afficherd(QDate date);

private:
    int ID_COUR;
    QString nom;
    QString description;

    QDate date_debut;
    QDate date_fin;
    int prix;
    QString niveau;

    int id_formateur;
};

#endif // COURS_H
