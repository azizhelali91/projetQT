#include "mainwindow.h"
#include "qmessagebox.h"
#include "ui_mainwindow.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QTextDocument>
#include <QPrinter>
#include <QTextStream>
#include <QVBoxLayout>
#include <QProgressBar>
#include "email.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //lors de l'execution ! ,  une seul fois ! ,
    ui->setupUi(this);
    remplir_comboBox_formateur();

    //affichage
    ui->tableView_formateur->setModel(f.afficher());
    ui->tableView_cour->setModel(c.afficher());
    ui->tableView_calendrier->setModel(c.afficher());


    ui->embauche_formateur->setDate(QDate::currentDate());

    QIntValidator *intValidator = new QIntValidator(0, 100000000, this); // Only allows integers from 0 to 100000
    ui->id_formateur->setValidator(intValidator);
    ui->cin_formateur->setValidator(intValidator);
    ui->telephone_formateur->setValidator(intValidator);

    ui->id_cour->setValidator(intValidator);
    ui->prix_cour->setValidator(intValidator);


    QRegularExpression charRegex("[a-zA-Z]*");
    QRegularExpressionValidator* charValidator = new QRegularExpressionValidator(charRegex, this);
    ui->nom_formateur->setValidator(charValidator);
    ui->prenom_formateur->setValidator(charValidator);

    ui->nom_cour->setValidator(charValidator);

    ui->debut_cour->setDate(QDate::currentDate());
    ui->fin_cour->setDate(QDate::currentDate());




    //calendrier !!
    QCalendarWidget* calendarWidget = ui->calendarWidget;

    // Clear existing date text formats
    calendarWidget->setDateTextFormat(QDate(), QTextCharFormat());

    QList<QDate> datesList = c.getDatesFromDatabase();

    for (const QDate& targetDate : datesList)
    {
        QTextCharFormat format =
            calendarWidget->dateTextFormat(targetDate);

        format.setForeground(Qt::blue);

        calendarWidget->setDateTextFormat(targetDate, format);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_formateur_clicked()
{
//Etape1: récupération des donné d'apres ui !
    int id_formateur= ui->id_formateur->text().toInt();
    QString nom=ui->nom_formateur->text();
    QString prenom=ui->prenom_formateur->text();
    QString email=ui->email_formateur->text();
    QString cin=ui->cin_formateur->text();
    QString telephone=ui->telephone_formateur->text();
    QString specialite =ui->specialite_formateur->currentText();
    QDate embauche=ui->embauche_formateur->date();

//Etape2: controle de saisie


    if(f.idExists(id_formateur)==true)
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le id deja existe"), QMessageBox::Cancel);
        return;

    }

    // Create a QRegularExpression object for email validation
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");//aa@aa.aa
    // Check if the email is valid
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("L'adresse email est invalide"), QMessageBox::Cancel);
        return;
    }

    // Check if the telephone number has exactly 8 characters
    if (telephone.length() != 8) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le numéro de téléphone doit contenir 8 numéro"), QMessageBox::Cancel);
        return;
    }

    if (cin.length() != 8) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le cin doit contenir 8 numéro"), QMessageBox::Cancel);
        return;
    }


    if(nom==""||cin==""||prenom==""||email==""||telephone==""||id_formateur==0)
    {

        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Tu dois remplir tous les champs"), QMessageBox::Cancel);
        return;
    }

    if(QDate::currentDate()>embauche)    //19/08/2026 >15/08/2026
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Tu ne peut pas donner un date dans le passer"), QMessageBox::Cancel);
        return;
    }

//Etape3: appel du fonction ajout !

    formateurs f( id_formateur,
                nom,
                prenom,
                cin,
                email,
                telephone,
                specialite,
                embauche);

    bool  test= f.ajouter();

//Etape4:  affichage du message succés ou échoué

    if(test==true)
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                              QObject::tr("Ajout avec succées"), QMessageBox::Cancel);
        ui->tableView_formateur->setModel(f.afficher());

        ui->id_formateur->clear();
        ui->nom_formateur->clear();
        ui->prenom_formateur->clear();
        ui->email_formateur->clear();
        ui->cin_formateur->clear();
        ui->telephone_formateur->clear();
        ui->embauche_formateur->setDate(QDate::currentDate());

        remplir_comboBox_formateur();
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Ajout échoué"), QMessageBox::Cancel);
    }


}


void MainWindow::on_tableView_formateur_clicked(const QModelIndex &index)
{
    //etape1: numero du ligne ! clicked !
    QAbstractItemModel* model = ui->tableView_formateur->model();

    int row = index.row();
    //etape2:  table du format matrice , recuperation du donne
    QString id_formateur = model->data(model->index(row, 0)).toString();
    QString nom = model->data(model->index(row, 1)).toString();
    QString prenom = model->data(model->index(row, 2)).toString();
    QString cin = model->data(model->index(row, 3)).toString();
    QString email = model->data(model->index(row, 4)).toString();
    QString telephone = model->data(model->index(row, 5)).toString();
    QString specialite = model->data(model->index(row, 6)).toString();
    QDate embauche = model->data(model->index(row, 7)).toDate();

    //etape3: insertion dans ui  ( lineEdit , comboBox)

    ui->id_formateur->setText(id_formateur);
    ui->nom_formateur->setText(nom);
    ui->prenom_formateur->setText(prenom);
    ui->cin_formateur->setText(cin);
    ui->email_formateur->setText(email);
    ui->telephone_formateur->setText(telephone);
    ui->specialite_formateur->setCurrentText(specialite);
    ui->embauche_formateur->setDate(embauche);
}


void MainWindow::on_modifier_formateur_clicked()
{
    //Etape1: récupération des donné d'apres ui !
    int id_formateur= ui->id_formateur->text().toInt();
    QString nom=ui->nom_formateur->text();
    QString prenom=ui->prenom_formateur->text();
    QString email=ui->email_formateur->text();
    QString cin=ui->cin_formateur->text();
    QString telephone=ui->telephone_formateur->text();
    QString specialite =ui->specialite_formateur->currentText();
    QDate embauche=ui->embauche_formateur->date();

    //Etape2: controle de saisie


    if(f.idExists(id_formateur)==false)
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le id n'existe pas"), QMessageBox::Cancel);
        return;

    }

    // Create a QRegularExpression object for email validation
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");//aa@aa.aa
    // Check if the email is valid
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("L'adresse email est invalide"), QMessageBox::Cancel);
        return;
    }

    // Check if the telephone number has exactly 8 characters
    if (telephone.length() != 8) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le numéro de téléphone doit contenir 8 numéro"), QMessageBox::Cancel);
        return;
    }

    if (cin.length() != 8) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le cin doit contenir 8 numéro"), QMessageBox::Cancel);
        return;
    }


    if(nom==""||cin==""||prenom==""||email==""||telephone==""||id_formateur==0)
    {

        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Tu dois remplir tous les champs"), QMessageBox::Cancel);
        return;
    }



    //Etape3: appel du fonction ajout !

    formateurs f( id_formateur,
                 nom,
                 prenom,
                 cin,
                 email,
                 telephone,
                 specialite,
                 embauche);

    bool  test= f.modifier();

    //Etape4:  affichage du message succés ou échoué

    if(test==true)
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Modification avec succées"), QMessageBox::Cancel);
        ui->tableView_formateur->setModel(f.afficher());

        ui->id_formateur->clear();
        ui->nom_formateur->clear();
        ui->prenom_formateur->clear();
        ui->email_formateur->clear();
        ui->cin_formateur->clear();
        ui->telephone_formateur->clear();
        ui->embauche_formateur->setDate(QDate::currentDate());


    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Modification échoué"), QMessageBox::Cancel);
    }

}


void MainWindow::on_supprimer_formateur_clicked()
{

    //récuperation d'apres ui
    int id_formateur= ui->id_formateur->text().toInt();

//controle de saisie
    if(f.idExists(id_formateur)==false)
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le id n'existe pas"), QMessageBox::Cancel);
        return;

    }
//action supprimer
    bool test= f.supprimer(id_formateur);
    //affichage du message
    if(test==true)
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Suppression avec succées"), QMessageBox::Cancel);
        ui->tableView_formateur->setModel(f.afficher());

        ui->id_formateur->clear();
        ui->nom_formateur->clear();
        ui->prenom_formateur->clear();
        ui->email_formateur->clear();
        ui->cin_formateur->clear();
        ui->telephone_formateur->clear();
        ui->embauche_formateur->setDate(QDate::currentDate());
        remplir_comboBox_formateur();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                                 QObject::tr("Suppression échoué"), QMessageBox::Cancel);
    }
}


void MainWindow::on_tri_formateur_clicked()
{

    QString column=ui->choix_formateur->currentText();
    QString ordre=ui->ordre_formateur->currentText();
    ui->tableView_formateur->setModel(f.tri(column,ordre));
}


void MainWindow::on_recherche_formateur_clicked()
{
    QString text=ui->text_chercher_formateur->text();
    QString column=ui->choix_formateur->currentText();
    ui->tableView_formateur->setModel(f.chercher(column,text));

}


void MainWindow::on_refresh_formateur_clicked()
{
    ui->tableView_formateur->setModel(f.afficher());

}

void MainWindow::remplir_comboBox_formateur()
{
    ui->id_formateur_cour->clear();

    QList<int> liste=c.ListIdFORMATEUR();

    for(int i=0 ;i<liste.length();i++)
    {
        ui->id_formateur_cour->addItem(QString::number(liste[i]));
    }


}



void MainWindow::on_ajouter_cour_clicked()
{
    int id_cour=ui->id_cour->text().toInt();
    QString nom =ui->nom_cour->text();
    QString description=ui->description_cour->text();
    QDate date_debut=ui->debut_cour->date();
    QDate date_fin=ui->fin_cour->date();
    int prix=ui->prix_cour->text().toInt();
    QString niveau=ui->niveau_cour->currentText();
    int id_formateur_cour=ui->id_formateur_cour->currentText().toInt();


    //Etape2: controle de saisie


    if(c.idExists(id_cour)==true)
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le id deja existe"), QMessageBox::Cancel);
        return;

    }

    if (date_debut> date_fin) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("date de fin doit etre supérieur à la date de debut "), QMessageBox::Cancel);
        return;
    }


    if(nom==""||description==""||id_cour==0||prix==0)
    {

        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Tu dois remplir tous les champs"), QMessageBox::Cancel);
        return;
    }


    //Etape3: appel du fonction ajout !

    COURS c( id_cour,
                 nom,
                 description,
                 date_debut,
                 date_fin,
                 prix,
                 niveau,
                 id_formateur_cour);

    bool  test= c.ajouter();

    //Etape4:  affichage du message succés ou échoué

    if(test==true)
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Ajout avec succées"), QMessageBox::Cancel);
        ui->tableView_cour->setModel(c.afficher());

        ui->id_cour->clear();
        ui->nom_cour->clear();
        ui->description_cour->clear();
        ui->debut_cour->setDate(QDate::currentDate());
        ui->fin_cour->setDate(QDate::currentDate());
        ui->prix_cour->clear();


        QString destinataireEmail=f.getEmailByIdFormateur(id_formateur_cour);
        QString objetEmail="Nouveau cours attribué – " +nom;

        QString bodyEmail =
            "Nous vous informons qu’un nouveau cours vous a été attribué au sein du centre de formation.\n\n"
            "📚 Informations du cours\n\n"
            "ID du cours : " + QString::number(id_cour) + "\n"
                                         "Nom du cours : " + nom + "\n"
                         "Description : " + description + "\n"
                                 "Date de début : " + date_debut.toString("dd/MM/yyyy") + "\n"
                                                  "Date de fin : " + date_fin.toString("dd/MM/yyyy") + "\n"
                                                "Prix : " + QString::number(prix) + " DT\n"
                                      "Niveau : " + niveau + "\n\n"
                       "Nous vous invitons à prendre connaissance de ces informations "
                       "et à vous préparer en conséquence pour le démarrage du cours.\n\n"
                       "Pour toute question ou information complémentaire, veuillez "
                       "contacter l’administration du centre.\n\n"
                       "Cordialement,\n\n"
                       "Administration du centre de formation";

        mailer::sendEmail(destinataireEmail,
                          objetEmail,
                          bodyEmail);



        //calendrier !!
        QCalendarWidget* calendarWidget = ui->calendarWidget;

        // Clear existing date text formats
        calendarWidget->setDateTextFormat(QDate(), QTextCharFormat());

        QList<QDate> datesList = c.getDatesFromDatabase();

        for (const QDate& targetDate : datesList)
        {
            QTextCharFormat format =
                calendarWidget->dateTextFormat(targetDate);

            format.setForeground(Qt::blue);

            calendarWidget->setDateTextFormat(targetDate, format);
        }

    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Ajout échoué"), QMessageBox::Cancel);
    }

}


void MainWindow::on_tableView_cour_clicked(const QModelIndex &index)
{
    //etape1: numero du ligne ! clicked !
    QAbstractItemModel* model = ui->tableView_cour->model();

    int row = index.row();
    //etape2:  table du format matrice , recuperation du donne
    QString id_cour = model->data(model->index(row, 0)).toString();
    QString nom = model->data(model->index(row, 1)).toString();
    QString description = model->data(model->index(row, 2)).toString();
    QDate date_debut = model->data(model->index(row, 3)).toDate();
    QDate date_fin = model->data(model->index(row, 4)).toDate();
    QString prix = model->data(model->index(row, 5)).toString();
    QString niveau = model->data(model->index(row, 6)).toString();
    QString id_formateur_cour = model->data(model->index(row, 7)).toString();

    //etape3: insertion dans ui  ( lineEdit , comboBox)
    ui->id_cour->setText(id_cour);
    ui->nom_cour->setText(nom);
    ui->description_cour->setText(description);
    ui->debut_cour->setDate(date_debut);
    ui->fin_cour->setDate(date_fin);
    ui->prix_cour->setText(prix);
    ui->niveau_cour->setCurrentText(niveau);
    ui->id_formateur_cour->setCurrentText(id_formateur_cour);
}


void MainWindow::on_modifier_cour_clicked()
{
    int id_cour=ui->id_cour->text().toInt();
    QString nom =ui->nom_cour->text();
    QString description=ui->description_cour->text();
    QDate date_debut=ui->debut_cour->date();
    QDate date_fin=ui->fin_cour->date();
    int prix=ui->prix_cour->text().toInt();
    QString niveau=ui->niveau_cour->currentText();
    int id_formateur_cour=ui->id_formateur_cour->currentText().toInt();


    //Etape2: controle de saisie


    if(c.idExists(id_cour)==false)
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le id n'existe pas "), QMessageBox::Cancel);
        return;

    }

    if (date_debut> date_fin) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("date de fin doit etre supérieur à la date de debut "), QMessageBox::Cancel);
        return;
    }


    if(nom==""||description==""||id_cour==0||prix==0)
    {

        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Tu dois remplir tous les champs"), QMessageBox::Cancel);
        return;
    }


    //Etape3: appel du fonction ajout !

    COURS c( id_cour,
            nom,
            description,
            date_debut,
            date_fin,
            prix,
            niveau,
            id_formateur_cour);

    bool  test= c.modifier();

    //Etape4:  affichage du message succés ou échoué

    if(test==true)
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Modification avec succées"), QMessageBox::Cancel);
        ui->tableView_cour->setModel(c.afficher());

        ui->id_cour->clear();
        ui->nom_cour->clear();
        ui->description_cour->clear();
        ui->debut_cour->setDate(QDate::currentDate());
        ui->fin_cour->setDate(QDate::currentDate());
        ui->prix_cour->clear();


        //calendrier !!
        QCalendarWidget* calendarWidget = ui->calendarWidget;

        // Clear existing date text formats
        calendarWidget->setDateTextFormat(QDate(), QTextCharFormat());

        QList<QDate> datesList = c.getDatesFromDatabase();

        for (const QDate& targetDate : datesList)
        {
            QTextCharFormat format =
                calendarWidget->dateTextFormat(targetDate);

            format.setForeground(Qt::blue);

            calendarWidget->setDateTextFormat(targetDate, format);
        }

    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Modification échoué"), QMessageBox::Cancel);
    }

}



void MainWindow::on_supprimer_cour_clicked()
{
    {

        //récuperation d'apres ui
        int id_cour= ui->id_cour->text().toInt();

        //controle de saisie
        if(c.idExists(id_cour)==false)
        {
            QMessageBox::critical(nullptr, QObject::tr(""),
                                  QObject::tr("Le id n'existe pas"), QMessageBox::Cancel);
            return;

        }
        //action supprimer
        bool test= c.supprimer(id_cour);
        //affichage du message
        if(test==true)
        {
            QMessageBox::information(nullptr, QObject::tr(""),
                                     QObject::tr("Suppression avec succées"), QMessageBox::Cancel);
            ui->tableView_cour->setModel(c.afficher());

            ui->id_cour->clear();
            ui->nom_cour->clear();
            ui->description_cour->clear();
            ui->debut_cour->setDate(QDate::currentDate());
            ui->fin_cour->setDate(QDate::currentDate());
            ui->prix_cour->clear();


            //calendrier !!
            QCalendarWidget* calendarWidget = ui->calendarWidget;

            // Clear existing date text formats
            calendarWidget->setDateTextFormat(QDate(), QTextCharFormat());

            QList<QDate> datesList = c.getDatesFromDatabase();

            for (const QDate& targetDate : datesList)
            {
                QTextCharFormat format =
                    calendarWidget->dateTextFormat(targetDate);

                format.setForeground(Qt::blue);

                calendarWidget->setDateTextFormat(targetDate, format);
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr(""),
                                  QObject::tr("Suppression échoué"), QMessageBox::Cancel);
        }
    }

}


void MainWindow::on_tri_cour_clicked()
{
    QString ordre = ui->ordre_cour->currentText();
   QString column= ui->choix_cour->currentText();
    ui->tableView_cour->setModel(c.tri(column,ordre));

}


void MainWindow::on_refresh_cour_clicked()
{
    ui->tableView_cour->setModel(c.afficher());
}


void MainWindow::on_recherche_cour_clicked()
{
    QString text = ui->chercher_text_cour->text();
    QString column= ui->choix_cour->currentText();
    ui->tableView_cour->setModel(c.chercher(column,text));
}


void MainWindow::on_pdf_cour_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_cour->model()->rowCount();
    const int columnCount = ui->tableView_cour->model()->columnCount();

    out << "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           "<title>%1</title>\n"
           "<style>\n"
           "table {\n"
           "    width: 100%;\n"
           "    border-collapse: collapse;\n"
           "}\n"
           "th, td {\n"
           "    padding: 8px;\n"
           "    text-align: left;\n"
           "    border-bottom: 1px solid #ddd;\n"
           "}\n"
           "tr:nth-child(even) {\n"
           "    background-color: #f2f2f2;\n"
           "}\n"
           "</style>\n"
           "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"
           "<center> <H1>Liste des cours</H1></center><br/><br/>\n"
           "<table>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
    {
        if (!ui->tableView_cour->isColumnHidden(column))
        {
            out << QString("<th>%1</th>").arg(ui->tableView_cour->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView_cour->isColumnHidden(column))
            {
                QString data = ui->tableView_cour->model()->data(ui->tableView_cour->model()->index(row, column)).toString().simplified();
                out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }



    QString fileName = QFileDialog::getSaveFileName((QWidget *)0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);

}

void MainWindow::on_pdf_formateur_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_formateur->model()->rowCount();
    const int columnCount = ui->tableView_formateur->model()->columnCount();

    out << "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           "<title>%1</title>\n"
           "<style>\n"
           "table {\n"
           "    width: 100%;\n"
           "    border-collapse: collapse;\n"
           "}\n"
           "th, td {\n"
           "    padding: 8px;\n"
           "    text-align: left;\n"
           "    border-bottom: 1px solid #ddd;\n"
           "}\n"
           "tr:nth-child(even) {\n"
           "    background-color: #f2f2f2;\n"
           "}\n"
           "</style>\n"
           "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"
           "<center> <H1>Liste des formateurs</H1></center><br/><br/>\n"
           "<table>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
    {
        if (!ui->tableView_formateur->isColumnHidden(column))
        {
            out << QString("<th>%1</th>").arg(ui->tableView_formateur->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView_formateur->isColumnHidden(column))
            {
                QString data = ui->tableView_formateur->model()->data(ui->tableView_formateur->model()->index(row, column)).toString().simplified();
                out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }



    QString fileName = QFileDialog::getSaveFileName((QWidget *)0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);

}

void MainWindow::on_stat_formateur_clicked()
{
    QMap<QString, int> stats = f.statistiquesParSPECIALITE();

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des formateurs par spécialité");
    dialog->resize(650, 450);

    // =========================
    // STYLE DU DIALOG
    // =========================
    dialog->setStyleSheet(
        "QDialog {"
        "    background-color: #1e1e1e;"
        "}"
        "QLabel {"
        "    color: white;"
        "}"
        "QProgressBar {"
        "    border: none;"
        "    background-color: #3a3a3a;"
        "    border-radius: 8px;"
        "    height: 14px;"
        "    text-align: center;"
        "}"
        "QProgressBar::chunk {"
        "    background-color: #e50914;"
        "    border-radius: 8px;"
        "}"
        );

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
    mainLayout->setContentsMargins(25, 25, 25, 25);
    mainLayout->setSpacing(18);

    // =========================
    // TITRE
    // =========================
    QLabel *title = new QLabel(
        "Répartition des formateurs par spécialité"
        );

    title->setStyleSheet(
        "QLabel {"
        "    color: white;"
        "    font-size: 20px;"
        "    font-weight: bold;"
        "    padding-bottom: 10px;"
        "}"
        );

    mainLayout->addWidget(title);

    // =========================
    // CALCUL DU TOTAL
    // =========================
    int total = 0;

    for (auto it = stats.begin(); it != stats.end(); ++it)
    {
        total += it.value();
    }

    // =========================
    // STATISTIQUES
    // =========================
    for (auto it = stats.begin(); it != stats.end(); ++it)
    {
        QString specialite = it.key();
        int nombre = it.value();

        double pourcentage = 0;

        if (total > 0)
        {
            pourcentage = (nombre * 100.0) / total;
        }

        // =========================
        // CARD
        // =========================
        QFrame *card = new QFrame();

        card->setStyleSheet(
            "QFrame {"
            "    background-color: #292929;"
            "    border: 1px solid #3d3d3d;"
            "    border-radius: 12px;"
            "}"
            );

        QVBoxLayout *cardLayout = new QVBoxLayout(card);

        cardLayout->setContentsMargins(18, 15, 18, 15);
        cardLayout->setSpacing(10);

        // =========================
        // LIGNE DU HAUT
        // =========================
        QHBoxLayout *topLayout = new QHBoxLayout();

        QLabel *specialiteLabel = new QLabel(
            specialite
            );

        specialiteLabel->setStyleSheet(
            "QLabel {"
            "    color: white;"
            "    font-size: 15px;"
            "    font-weight: bold;"
            "    border: none;"
            "}"
            );

        QLabel *nombreLabel = new QLabel(
            QString::number(nombre) +
            " formateur(s)"
            );

        nombreLabel->setStyleSheet(
            "QLabel {"
            "    color: #aaaaaa;"
            "    font-size: 13px;"
            "    border: none;"
            "}"
            );

        topLayout->addWidget(specialiteLabel);
        topLayout->addStretch();
        topLayout->addWidget(nombreLabel);

        cardLayout->addLayout(topLayout);

        // =========================
        // PROGRESS BAR + %
        // =========================
        QHBoxLayout *progressLayout = new QHBoxLayout();

        QProgressBar *progressBar = new QProgressBar();

        progressBar->setMinimum(0);
        progressBar->setMaximum(100);
        progressBar->setValue(static_cast<int>(pourcentage));

        // On cache le texte par défaut
        progressBar->setTextVisible(false);

        QLabel *percentageLabel = new QLabel(
            QString::number(pourcentage, 'f', 1) + "%"
            );

        percentageLabel->setFixedWidth(55);
        percentageLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

        percentageLabel->setStyleSheet(
            "QLabel {"
            "    color: #e50914;"
            "    font-size: 14px;"
            "    font-weight: bold;"
            "    border: none;"
            "}"
            );

        progressLayout->addWidget(progressBar);
        progressLayout->addWidget(percentageLabel);

        cardLayout->addLayout(progressLayout);

        // =========================
        // AJOUT DE LA CARD
        // =========================
        mainLayout->addWidget(card);
    }

    mainLayout->addStretch();

    dialog->exec();
}

void MainWindow::on_statistique_cour_clicked()
{
    QMap<QString, int> stats = c.statistiquesParNiveau();

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des cours par niveau");
    dialog->resize(650, 450);

    // =========================
    // STYLE DU DIALOG
    // =========================
    dialog->setStyleSheet(
        "QDialog {"
        "    background-color: #1e1e1e;"
        "}"
        "QLabel {"
        "    color: white;"
        "}"
        "QProgressBar {"
        "    border: none;"
        "    background-color: #3a3a3a;"
        "    border-radius: 8px;"
        "    height: 14px;"
        "    text-align: center;"
        "}"
        "QProgressBar::chunk {"
        "    background-color: #e50914;"
        "    border-radius: 8px;"
        "}"
        );

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
    mainLayout->setContentsMargins(25, 25, 25, 25);
    mainLayout->setSpacing(18);

    // =========================
    // TITRE
    // =========================
    QLabel *title = new QLabel(
        "Répartition des cours par niveau"
        );

    title->setStyleSheet(
        "QLabel {"
        "    color: white;"
        "    font-size: 20px;"
        "    font-weight: bold;"
        "    padding-bottom: 10px;"
        "}"
        );

    mainLayout->addWidget(title);

    // =========================
    // CALCUL DU TOTAL
    // =========================
    int total = 0;

    for (auto it = stats.begin(); it != stats.end(); ++it)
    {
        total += it.value();
    }

    // =========================
    // STATISTIQUES
    // =========================
    for (auto it = stats.begin(); it != stats.end(); ++it)
    {
        QString specialite = it.key();
        int nombre = it.value();

        double pourcentage = 0;

        if (total > 0)
        {
            pourcentage = (nombre * 100.0) / total;
        }

        // =========================
        // CARD
        // =========================
        QFrame *card = new QFrame();

        card->setStyleSheet(
            "QFrame {"
            "    background-color: #292929;"
            "    border: 1px solid #3d3d3d;"
            "    border-radius: 12px;"
            "}"
            );

        QVBoxLayout *cardLayout = new QVBoxLayout(card);

        cardLayout->setContentsMargins(18, 15, 18, 15);
        cardLayout->setSpacing(10);

        // =========================
        // LIGNE DU HAUT
        // =========================
        QHBoxLayout *topLayout = new QHBoxLayout();

        QLabel *specialiteLabel = new QLabel(
            specialite
            );

        specialiteLabel->setStyleSheet(
            "QLabel {"
            "    color: white;"
            "    font-size: 15px;"
            "    font-weight: bold;"
            "    border: none;"
            "}"
            );

        QLabel *nombreLabel = new QLabel(
            QString::number(nombre) +
            " cour(s)"
            );

        nombreLabel->setStyleSheet(
            "QLabel {"
            "    color: #aaaaaa;"
            "    font-size: 13px;"
            "    border: none;"
            "}"
            );

        topLayout->addWidget(specialiteLabel);
        topLayout->addStretch();
        topLayout->addWidget(nombreLabel);

        cardLayout->addLayout(topLayout);

        // =========================
        // PROGRESS BAR + %
        // =========================
        QHBoxLayout *progressLayout = new QHBoxLayout();

        QProgressBar *progressBar = new QProgressBar();

        progressBar->setMinimum(0);
        progressBar->setMaximum(100);
        progressBar->setValue(static_cast<int>(pourcentage));

        // On cache le texte par défaut
        progressBar->setTextVisible(false);

        QLabel *percentageLabel = new QLabel(
            QString::number(pourcentage, 'f', 1) + "%"
            );

        percentageLabel->setFixedWidth(55);
        percentageLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

        percentageLabel->setStyleSheet(
            "QLabel {"
            "    color: #e50914;"
            "    font-size: 14px;"
            "    font-weight: bold;"
            "    border: none;"
            "}"
            );

        progressLayout->addWidget(progressBar);
        progressLayout->addWidget(percentageLabel);

        cardLayout->addLayout(progressLayout);

        // =========================
        // AJOUT DE LA CARD
        // =========================
        mainLayout->addWidget(card);
    }

    mainLayout->addStretch();

    dialog->exec();
}









void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    ui->tableView_calendrier->setModel(c.afficherd(date));
}
