#include "cours.h"
#include "qsqlquery.h"

// Constructeur par défaut
COURS::COURS()
{
    ID_COUR = 0;
    prix = 0;
    id_formateur=9;
}

// Constructeur avec paramètres
COURS::COURS(int ID_COUR,
             QString nom,
             QString description,

             QDate date_debut,
             QDate date_fin,
             int prix,
             QString niveau,

             int id_formateur)
{
    this->ID_COUR = ID_COUR;
    this->nom = nom;
    this->description = description;

    this->date_debut = date_debut;
    this->date_fin = date_fin;
    this->prix = prix;
    this->niveau = niveau;

    this->id_formateur=id_formateur;
}

// ==================== SETTERS ====================

void COURS::setIdCour(int id)
{
    ID_COUR = id;
}

void COURS::setNom(QString nom)
{
    this->nom = nom;
}

void COURS::setDescription(QString description)
{
    this->description = description;
}


void COURS::setDateDebut(QDate date_debut)
{
    this->date_debut = date_debut;
}

void COURS::setDateFin(QDate date_fin)
{
    this->date_fin = date_fin;
}

void COURS::setPrix(int prix)
{
    this->prix = prix;
}

void COURS::setNiveau(QString niveau)
{
    this->niveau = niveau;
}


void COURS::setIdFormateur(int id_formateur)
{
    this->id_formateur = id_formateur;
}

// ==================== GETTERS ====================

int COURS::getIdCour()
{
    return ID_COUR;
}

QString COURS::getNom()
{
    return nom;
}

QString COURS::getDescription()
{
    return description;
}



QDate COURS::getDateDebut()
{
    return date_debut;
}

QDate COURS::getDateFin()
{
    return date_fin;
}

int COURS::getPrix()
{
    return prix;
}

QString COURS::getNiveau()
{
    return niveau;
}



int COURS::getIdFormateur()
{
    return id_formateur;
}

// ==================== CRUD ====================

bool COURS::ajouter()
{
    QSqlQuery query;

    query.prepare(
        "INSERT INTO COURS "
        "(ID_COUR, NOM, DESCRIPTION, DATE_DEBUT, DATE_FIN, PRIX, NIVEAU ,ID_FORMATEUR) "
        "VALUES "
        "(:id, :nom, :description, :date_debut, :date_fin, :prix, :niveau, :id_formateur)"
        );

    query.bindValue(":id", ID_COUR);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":prix", prix);
    query.bindValue(":niveau", niveau);
    query.bindValue(":id_formateur", id_formateur);

    bool test = query.exec();

    if (test)
        return true;
    else
        return false;
}


bool COURS::modifier()
{
    QSqlQuery query;

    query.prepare(
        "UPDATE COURS SET "
        "NOM=:nom, "
        "DESCRIPTION=:description, "
        "DATE_DEBUT=:date_debut, "
        "DATE_FIN=:date_fin, "
        "PRIX=:prix, "
        "NIVEAU=:niveau, "
        "ID_FORMATEUR=:id_formateur "
        "WHERE ID_COUR=:id"
        );

    query.bindValue(":id", ID_COUR);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":prix", prix);
    query.bindValue(":niveau", niveau);
    query.bindValue(":id_formateur", id_formateur);

    bool test = query.exec();

    if (test)
        return true;
    else
        return false;
}


bool COURS::supprimer(int id)
{
    QSqlQuery query;

    query.prepare(
        "DELETE FROM COURS "
        "WHERE ID_COUR=:id"
        );

    query.bindValue(":id", id);

    bool test = query.exec();

    if (test)
        return true;
    else
        return false;
}


QSqlQueryModel* COURS::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM COURS");

    return model;
}


bool COURS::idExists(int id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM COURS WHERE ID_COUR = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0; //true
    }

    return false;
}


QList<int> COURS::ListIdFORMATEUR(){
    QList<int> Liste;

    QSqlQuery query;
    query.prepare("SELECT ID_FORMATEUR FROM FORMATEURS ");
    if(query.exec())
    {
        while(query.next())
        {
            Liste.append(query.value(0).toInt());
        }
    }
    return Liste;

}


QSqlQueryModel* COURS::chercher(QString column, QString text)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM COURS WHERE " + column + " LIKE '%" + text + "%'"); // NOM   LIKE  '%az%'  = az
    return model;
}

QSqlQueryModel* COURS::tri(QString column, QString choix)//(SELECT * FROM FORMATEURS ORDER BY  nom ASC)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM COURS ORDER BY " + column + " " + choix);
    return model;
}

QMap<QString, int> COURS::statistiquesParNiveau() {
    QMap<QString, int> niveauStats;

    QSqlQuery query;
    query.prepare("SELECT NIVEAU, COUNT(*) as count FROM COURS GROUP BY NIVEAU");

    //list=QMap
    if (query.exec()) {
        while (query.next()) {
            QString niveau = query.value(0).toString();
            int count = query.value(1).toInt();
            niveauStats[niveau] = count;
        }
    }

    return niveauStats;
}
