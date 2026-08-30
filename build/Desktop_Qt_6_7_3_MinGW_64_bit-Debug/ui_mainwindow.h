/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_formateur;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *id_formateur;
    QLabel *label_3;
    QLineEdit *nom_formateur;
    QLabel *label_4;
    QLineEdit *prenom_formateur;
    QLabel *label_5;
    QLineEdit *cin_formateur;
    QLabel *label_6;
    QLineEdit *email_formateur;
    QLabel *label_7;
    QLineEdit *telephone_formateur;
    QLabel *label_8;
    QLabel *label_9;
    QDateEdit *embauche_formateur;
    QComboBox *specialite_formateur;
    QTableView *tableView_formateur;
    QPushButton *ajouter_formateur;
    QPushButton *modifier_formateur;
    QPushButton *supprimer_formateur;
    QPushButton *tri_formateur;
    QPushButton *recherche_formateur;
    QComboBox *choix_formateur;
    QPushButton *pdf_formateur;
    QPushButton *stat_formateur;
    QComboBox *ordre_formateur;
    QLineEdit *text_chercher_formateur;
    QPushButton *refresh_formateur;
    QWidget *tab_cours;
    QComboBox *niveau_cour;
    QLineEdit *nom_cour;
    QPushButton *pdf_cour;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QPushButton *statistique_cour;
    QLabel *niveau_cour_3;
    QLabel *label_23;
    QPushButton *recherche_cour;
    QPushButton *tri_cour;
    QLineEdit *id_cour;
    QPushButton *supprimer_cour;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *description_cour;
    QLabel *label_26;
    QPushButton *ajouter_cour;
    QTableView *tableView_cour;
    QComboBox *choix_cour;
    QPushButton *modifier_cour;
    QComboBox *id_formateur_cour;
    QLabel *label_29;
    QLineEdit *prix_cour;
    QDateEdit *fin_cour;
    QDateEdit *debut_cour;
    QPushButton *refresh_cour;
    QComboBox *ordre_cour;
    QLineEdit *chercher_text_cour;
    QWidget *tab_calendrier;
    QCalendarWidget *calendarWidget;
    QTableView *tableView_calendrier;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(30, 0, 1920, 1080));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color:#87CEEB;"));
        tab_formateur = new QWidget();
        tab_formateur->setObjectName("tab_formateur");
        label = new QLabel(tab_formateur);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 411, 51));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label_2 = new QLabel(tab_formateur);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 110, 121, 31));
        id_formateur = new QLineEdit(tab_formateur);
        id_formateur->setObjectName("id_formateur");
        id_formateur->setGeometry(QRect(170, 110, 161, 31));
        label_3 = new QLabel(tab_formateur);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 150, 121, 31));
        nom_formateur = new QLineEdit(tab_formateur);
        nom_formateur->setObjectName("nom_formateur");
        nom_formateur->setGeometry(QRect(170, 160, 161, 31));
        label_4 = new QLabel(tab_formateur);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 200, 121, 31));
        prenom_formateur = new QLineEdit(tab_formateur);
        prenom_formateur->setObjectName("prenom_formateur");
        prenom_formateur->setGeometry(QRect(170, 210, 161, 31));
        label_5 = new QLabel(tab_formateur);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 250, 121, 31));
        cin_formateur = new QLineEdit(tab_formateur);
        cin_formateur->setObjectName("cin_formateur");
        cin_formateur->setGeometry(QRect(170, 260, 161, 31));
        label_6 = new QLabel(tab_formateur);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 300, 121, 31));
        email_formateur = new QLineEdit(tab_formateur);
        email_formateur->setObjectName("email_formateur");
        email_formateur->setGeometry(QRect(170, 310, 161, 31));
        label_7 = new QLabel(tab_formateur);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 350, 121, 31));
        telephone_formateur = new QLineEdit(tab_formateur);
        telephone_formateur->setObjectName("telephone_formateur");
        telephone_formateur->setGeometry(QRect(170, 360, 161, 31));
        label_8 = new QLabel(tab_formateur);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 410, 121, 31));
        label_9 = new QLabel(tab_formateur);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 460, 121, 31));
        embauche_formateur = new QDateEdit(tab_formateur);
        embauche_formateur->setObjectName("embauche_formateur");
        embauche_formateur->setGeometry(QRect(170, 460, 161, 31));
        specialite_formateur = new QComboBox(tab_formateur);
        specialite_formateur->addItem(QString());
        specialite_formateur->addItem(QString());
        specialite_formateur->addItem(QString());
        specialite_formateur->addItem(QString());
        specialite_formateur->setObjectName("specialite_formateur");
        specialite_formateur->setGeometry(QRect(170, 410, 161, 31));
        tableView_formateur = new QTableView(tab_formateur);
        tableView_formateur->setObjectName("tableView_formateur");
        tableView_formateur->setGeometry(QRect(380, 120, 1331, 361));
        ajouter_formateur = new QPushButton(tab_formateur);
        ajouter_formateur->setObjectName("ajouter_formateur");
        ajouter_formateur->setGeometry(QRect(50, 520, 131, 31));
        modifier_formateur = new QPushButton(tab_formateur);
        modifier_formateur->setObjectName("modifier_formateur");
        modifier_formateur->setGeometry(QRect(210, 520, 131, 31));
        supprimer_formateur = new QPushButton(tab_formateur);
        supprimer_formateur->setObjectName("supprimer_formateur");
        supprimer_formateur->setGeometry(QRect(470, 500, 131, 31));
        tri_formateur = new QPushButton(tab_formateur);
        tri_formateur->setObjectName("tri_formateur");
        tri_formateur->setGeometry(QRect(490, 80, 131, 31));
        recherche_formateur = new QPushButton(tab_formateur);
        recherche_formateur->setObjectName("recherche_formateur");
        recherche_formateur->setGeometry(QRect(1030, 40, 131, 31));
        choix_formateur = new QComboBox(tab_formateur);
        choix_formateur->addItem(QString());
        choix_formateur->addItem(QString());
        choix_formateur->addItem(QString());
        choix_formateur->addItem(QString());
        choix_formateur->addItem(QString());
        choix_formateur->addItem(QString());
        choix_formateur->addItem(QString());
        choix_formateur->addItem(QString());
        choix_formateur->setObjectName("choix_formateur");
        choix_formateur->setGeometry(QRect(840, 80, 161, 31));
        pdf_formateur = new QPushButton(tab_formateur);
        pdf_formateur->setObjectName("pdf_formateur");
        pdf_formateur->setGeometry(QRect(730, 500, 131, 31));
        stat_formateur = new QPushButton(tab_formateur);
        stat_formateur->setObjectName("stat_formateur");
        stat_formateur->setGeometry(QRect(980, 500, 131, 31));
        ordre_formateur = new QComboBox(tab_formateur);
        ordre_formateur->addItem(QString());
        ordre_formateur->addItem(QString());
        ordre_formateur->setObjectName("ordre_formateur");
        ordre_formateur->setGeometry(QRect(650, 80, 161, 31));
        text_chercher_formateur = new QLineEdit(tab_formateur);
        text_chercher_formateur->setObjectName("text_chercher_formateur");
        text_chercher_formateur->setGeometry(QRect(1030, 80, 191, 31));
        refresh_formateur = new QPushButton(tab_formateur);
        refresh_formateur->setObjectName("refresh_formateur");
        refresh_formateur->setGeometry(QRect(490, 30, 131, 31));
        tabWidget->addTab(tab_formateur, QString());
        tab_cours = new QWidget();
        tab_cours->setObjectName("tab_cours");
        niveau_cour = new QComboBox(tab_cours);
        niveau_cour->addItem(QString());
        niveau_cour->addItem(QString());
        niveau_cour->addItem(QString());
        niveau_cour->addItem(QString());
        niveau_cour->setObjectName("niveau_cour");
        niveau_cour->setGeometry(QRect(170, 410, 161, 31));
        nom_cour = new QLineEdit(tab_cours);
        nom_cour->setObjectName("nom_cour");
        nom_cour->setGeometry(QRect(170, 150, 161, 31));
        pdf_cour = new QPushButton(tab_cours);
        pdf_cour->setObjectName("pdf_cour");
        pdf_cour->setGeometry(QRect(730, 490, 131, 31));
        label_19 = new QLabel(tab_cours);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 10, 411, 51));
        label_19->setFont(font);
        label_20 = new QLabel(tab_cours);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(30, 100, 121, 31));
        label_21 = new QLabel(tab_cours);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(30, 360, 121, 31));
        statistique_cour = new QPushButton(tab_cours);
        statistique_cour->setObjectName("statistique_cour");
        statistique_cour->setGeometry(QRect(980, 490, 131, 31));
        niveau_cour_3 = new QLabel(tab_cours);
        niveau_cour_3->setObjectName("niveau_cour_3");
        niveau_cour_3->setGeometry(QRect(30, 410, 121, 31));
        label_23 = new QLabel(tab_cours);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(30, 240, 121, 31));
        recherche_cour = new QPushButton(tab_cours);
        recherche_cour->setObjectName("recherche_cour");
        recherche_cour->setGeometry(QRect(850, 70, 131, 31));
        tri_cour = new QPushButton(tab_cours);
        tri_cour->setObjectName("tri_cour");
        tri_cour->setGeometry(QRect(490, 70, 131, 31));
        id_cour = new QLineEdit(tab_cours);
        id_cour->setObjectName("id_cour");
        id_cour->setGeometry(QRect(170, 100, 161, 31));
        supprimer_cour = new QPushButton(tab_cours);
        supprimer_cour->setObjectName("supprimer_cour");
        supprimer_cour->setGeometry(QRect(470, 490, 131, 31));
        label_24 = new QLabel(tab_cours);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(30, 190, 121, 31));
        label_25 = new QLabel(tab_cours);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(30, 140, 121, 31));
        description_cour = new QLineEdit(tab_cours);
        description_cour->setObjectName("description_cour");
        description_cour->setGeometry(QRect(170, 200, 161, 31));
        label_26 = new QLabel(tab_cours);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(30, 300, 121, 31));
        ajouter_cour = new QPushButton(tab_cours);
        ajouter_cour->setObjectName("ajouter_cour");
        ajouter_cour->setGeometry(QRect(20, 570, 131, 31));
        tableView_cour = new QTableView(tab_cours);
        tableView_cour->setObjectName("tableView_cour");
        tableView_cour->setGeometry(QRect(380, 110, 1331, 361));
        choix_cour = new QComboBox(tab_cours);
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->setObjectName("choix_cour");
        choix_cour->setGeometry(QRect(650, 70, 161, 31));
        modifier_cour = new QPushButton(tab_cours);
        modifier_cour->setObjectName("modifier_cour");
        modifier_cour->setGeometry(QRect(180, 570, 131, 31));
        id_formateur_cour = new QComboBox(tab_cours);
        id_formateur_cour->setObjectName("id_formateur_cour");
        id_formateur_cour->setGeometry(QRect(170, 460, 161, 31));
        label_29 = new QLabel(tab_cours);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(20, 460, 121, 31));
        prix_cour = new QLineEdit(tab_cours);
        prix_cour->setObjectName("prix_cour");
        prix_cour->setGeometry(QRect(170, 360, 161, 31));
        fin_cour = new QDateEdit(tab_cours);
        fin_cour->setObjectName("fin_cour");
        fin_cour->setGeometry(QRect(170, 310, 171, 31));
        debut_cour = new QDateEdit(tab_cours);
        debut_cour->setObjectName("debut_cour");
        debut_cour->setGeometry(QRect(170, 250, 171, 31));
        refresh_cour = new QPushButton(tab_cours);
        refresh_cour->setObjectName("refresh_cour");
        refresh_cour->setGeometry(QRect(490, 30, 131, 31));
        ordre_cour = new QComboBox(tab_cours);
        ordre_cour->addItem(QString());
        ordre_cour->addItem(QString());
        ordre_cour->setObjectName("ordre_cour");
        ordre_cour->setGeometry(QRect(650, 30, 161, 31));
        chercher_text_cour = new QLineEdit(tab_cours);
        chercher_text_cour->setObjectName("chercher_text_cour");
        chercher_text_cour->setGeometry(QRect(850, 30, 131, 31));
        tabWidget->addTab(tab_cours, QString());
        tab_calendrier = new QWidget();
        tab_calendrier->setObjectName("tab_calendrier");
        calendarWidget = new QCalendarWidget(tab_calendrier);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(190, 90, 601, 161));
        tableView_calendrier = new QTableView(tab_calendrier);
        tableView_calendrier->setObjectName("tableView_calendrier");
        tableView_calendrier->setGeometry(QRect(70, 270, 1061, 271));
        tabWidget->addTab(tab_calendrier, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Gestion formateur", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ID_FORMATEUR", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "NOM", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "PRENOM", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "CIN", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "EMAIL", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TELEPHONE", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "SPECIALITE", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "DATE D'EMBAUCHE", nullptr));
        specialite_formateur->setItemText(0, QCoreApplication::translate("MainWindow", "AI", nullptr));
        specialite_formateur->setItemText(1, QCoreApplication::translate("MainWindow", "DEV", nullptr));
        specialite_formateur->setItemText(2, QCoreApplication::translate("MainWindow", "CLOUD", nullptr));
        specialite_formateur->setItemText(3, QCoreApplication::translate("MainWindow", "SECURITE", nullptr));

        ajouter_formateur->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        modifier_formateur->setText(QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        supprimer_formateur->setText(QCoreApplication::translate("MainWindow", "SUPPRIMER", nullptr));
        tri_formateur->setText(QCoreApplication::translate("MainWindow", "TRI", nullptr));
        recherche_formateur->setText(QCoreApplication::translate("MainWindow", "RECHERCHE", nullptr));
        choix_formateur->setItemText(0, QCoreApplication::translate("MainWindow", "ID_FORMATEUR", nullptr));
        choix_formateur->setItemText(1, QCoreApplication::translate("MainWindow", "NOM", nullptr));
        choix_formateur->setItemText(2, QCoreApplication::translate("MainWindow", "PRENOM", nullptr));
        choix_formateur->setItemText(3, QCoreApplication::translate("MainWindow", "EMAIL", nullptr));
        choix_formateur->setItemText(4, QCoreApplication::translate("MainWindow", "CIN", nullptr));
        choix_formateur->setItemText(5, QCoreApplication::translate("MainWindow", "TELEPHONE", nullptr));
        choix_formateur->setItemText(6, QCoreApplication::translate("MainWindow", "SPECIALITE", nullptr));
        choix_formateur->setItemText(7, QCoreApplication::translate("MainWindow", "DATE_EMBAUCHE", nullptr));

        pdf_formateur->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        stat_formateur->setText(QCoreApplication::translate("MainWindow", "STATISTIQUE", nullptr));
        ordre_formateur->setItemText(0, QCoreApplication::translate("MainWindow", "ASC", nullptr));
        ordre_formateur->setItemText(1, QCoreApplication::translate("MainWindow", "DESC", nullptr));

        refresh_formateur->setText(QCoreApplication::translate("MainWindow", "REFRESH", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_formateur), QCoreApplication::translate("MainWindow", "gestion formateur", nullptr));
        niveau_cour->setItemText(0, QCoreApplication::translate("MainWindow", "Debutant", nullptr));
        niveau_cour->setItemText(1, QCoreApplication::translate("MainWindow", "Intermediaire", nullptr));
        niveau_cour->setItemText(2, QCoreApplication::translate("MainWindow", "Avance", nullptr));
        niveau_cour->setItemText(3, QCoreApplication::translate("MainWindow", "Expert", nullptr));

        pdf_cour->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Gestion Cours", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "ID_COUR", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "PRIX", nullptr));
        statistique_cour->setText(QCoreApplication::translate("MainWindow", "STATISTIQUE", nullptr));
        niveau_cour_3->setText(QCoreApplication::translate("MainWindow", "NIVEAU", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "DATE DE DEBUT", nullptr));
        recherche_cour->setText(QCoreApplication::translate("MainWindow", "RECHERCHE", nullptr));
        tri_cour->setText(QCoreApplication::translate("MainWindow", "TRI", nullptr));
        supprimer_cour->setText(QCoreApplication::translate("MainWindow", "SUPPRIMER", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "DESCRIPTION", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "NOM", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "DATE DE FIN", nullptr));
        ajouter_cour->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        choix_cour->setItemText(0, QCoreApplication::translate("MainWindow", "ID_COUR", nullptr));
        choix_cour->setItemText(1, QCoreApplication::translate("MainWindow", "NOM", nullptr));
        choix_cour->setItemText(2, QCoreApplication::translate("MainWindow", "DESCRIPTION", nullptr));
        choix_cour->setItemText(3, QCoreApplication::translate("MainWindow", "DATE_DEBUT", nullptr));
        choix_cour->setItemText(4, QCoreApplication::translate("MainWindow", "DATE_FIN", nullptr));
        choix_cour->setItemText(5, QCoreApplication::translate("MainWindow", "PRIX", nullptr));
        choix_cour->setItemText(6, QCoreApplication::translate("MainWindow", "NIVEAU", nullptr));
        choix_cour->setItemText(7, QCoreApplication::translate("MainWindow", "ID_FORMATEUR", nullptr));

        modifier_cour->setText(QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "ID FORMATEUR", nullptr));
        refresh_cour->setText(QCoreApplication::translate("MainWindow", "REFRESH", nullptr));
        ordre_cour->setItemText(0, QCoreApplication::translate("MainWindow", "ASC", nullptr));
        ordre_cour->setItemText(1, QCoreApplication::translate("MainWindow", "DESC", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_cours), QCoreApplication::translate("MainWindow", "gestion cour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_calendrier), QCoreApplication::translate("MainWindow", "Calendrier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
