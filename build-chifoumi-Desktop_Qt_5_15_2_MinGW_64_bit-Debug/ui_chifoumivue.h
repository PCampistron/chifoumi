/********************************************************************************
** Form generated from reading UI file 'chifoumivue.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHIFOUMIVUE_H
#define UI_CHIFOUMIVUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChifoumiVue
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QHBoxLayout *combatHLayout;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *joueurVLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *lNomJoueur;
    QLabel *lScoreJoueur;
    QLabel *lActionJoueur;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lEpees;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *machineVLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *lNomMachine;
    QLabel *lScoreMachine;
    QLabel *lActionMachine;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *actionHLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bPierre;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *bFeuille;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *bCiseaux;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *buttonHLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *bNouvellePartie;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuAide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChifoumiVue)
    {
        if (ChifoumiVue->objectName().isEmpty())
            ChifoumiVue->setObjectName(QString::fromUtf8("ChifoumiVue"));
        ChifoumiVue->resize(978, 780);
        centralwidget = new QWidget(ChifoumiVue);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        combatHLayout = new QHBoxLayout();
        combatHLayout->setObjectName(QString::fromUtf8("combatHLayout"));
        horizontalSpacer_4 = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        combatHLayout->addItem(horizontalSpacer_4);

        joueurVLayout = new QVBoxLayout();
        joueurVLayout->setObjectName(QString::fromUtf8("joueurVLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        joueurVLayout->addItem(verticalSpacer_2);

        lNomJoueur = new QLabel(centralwidget);
        lNomJoueur->setObjectName(QString::fromUtf8("lNomJoueur"));
        lNomJoueur->setAlignment(Qt::AlignCenter);

        joueurVLayout->addWidget(lNomJoueur);

        lScoreJoueur = new QLabel(centralwidget);
        lScoreJoueur->setObjectName(QString::fromUtf8("lScoreJoueur"));
        lScoreJoueur->setAlignment(Qt::AlignCenter);

        joueurVLayout->addWidget(lScoreJoueur);

        lActionJoueur = new QLabel(centralwidget);
        lActionJoueur->setObjectName(QString::fromUtf8("lActionJoueur"));
        lActionJoueur->setPixmap(QPixmap(QString::fromUtf8(":/images/rien.gif")));
        lActionJoueur->setAlignment(Qt::AlignCenter);

        joueurVLayout->addWidget(lActionJoueur);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        joueurVLayout->addItem(verticalSpacer);


        combatHLayout->addLayout(joueurVLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        combatHLayout->addItem(horizontalSpacer_6);

        lEpees = new QLabel(centralwidget);
        lEpees->setObjectName(QString::fromUtf8("lEpees"));
        lEpees->setPixmap(QPixmap(QString::fromUtf8(":/images/versus.gif")));
        lEpees->setAlignment(Qt::AlignCenter);

        combatHLayout->addWidget(lEpees);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        combatHLayout->addItem(horizontalSpacer_7);

        machineVLayout = new QVBoxLayout();
        machineVLayout->setObjectName(QString::fromUtf8("machineVLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        machineVLayout->addItem(verticalSpacer_3);

        lNomMachine = new QLabel(centralwidget);
        lNomMachine->setObjectName(QString::fromUtf8("lNomMachine"));
        lNomMachine->setAlignment(Qt::AlignCenter);

        machineVLayout->addWidget(lNomMachine);

        lScoreMachine = new QLabel(centralwidget);
        lScoreMachine->setObjectName(QString::fromUtf8("lScoreMachine"));
        lScoreMachine->setAlignment(Qt::AlignCenter);

        machineVLayout->addWidget(lScoreMachine);

        lActionMachine = new QLabel(centralwidget);
        lActionMachine->setObjectName(QString::fromUtf8("lActionMachine"));
        lActionMachine->setPixmap(QPixmap(QString::fromUtf8(":/images/rien.gif")));
        lActionMachine->setAlignment(Qt::AlignCenter);

        machineVLayout->addWidget(lActionMachine);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        machineVLayout->addItem(verticalSpacer_4);


        combatHLayout->addLayout(machineVLayout);

        horizontalSpacer_5 = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        combatHLayout->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(combatHLayout, 0, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Ignored);

        gridLayout_2->addItem(verticalSpacer_9, 0, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer_6, 0, 2, 1, 1);

        actionHLayout = new QHBoxLayout();
        actionHLayout->setObjectName(QString::fromUtf8("actionHLayout"));
        actionHLayout->setContentsMargins(0, 0, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        actionHLayout->addItem(horizontalSpacer_2);

        bPierre = new QPushButton(centralwidget);
        bPierre->setObjectName(QString::fromUtf8("bPierre"));
        bPierre->setMinimumSize(QSize(113, 113));
        bPierre->setMaximumSize(QSize(115, 115));
        bPierre->setStyleSheet(QString::fromUtf8("background-image: url(:/images/pierre.gif);"));

        actionHLayout->addWidget(bPierre);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        actionHLayout->addItem(horizontalSpacer_8);

        bFeuille = new QPushButton(centralwidget);
        bFeuille->setObjectName(QString::fromUtf8("bFeuille"));
        bFeuille->setMinimumSize(QSize(113, 113));
        bFeuille->setMaximumSize(QSize(113, 113));
        bFeuille->setStyleSheet(QString::fromUtf8("background-image: url(:/images/papier.gif);"));

        actionHLayout->addWidget(bFeuille);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        actionHLayout->addItem(horizontalSpacer_9);

        bCiseaux = new QPushButton(centralwidget);
        bCiseaux->setObjectName(QString::fromUtf8("bCiseaux"));
        bCiseaux->setMinimumSize(QSize(113, 113));
        bCiseaux->setMaximumSize(QSize(113, 113));
        bCiseaux->setStyleSheet(QString::fromUtf8("background-image: url(:/images/ciseau.gif);"));

        actionHLayout->addWidget(bCiseaux);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        actionHLayout->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(actionHLayout, 1, 0, 1, 3);

        buttonHLayout = new QHBoxLayout();
        buttonHLayout->setObjectName(QString::fromUtf8("buttonHLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHLayout->addItem(horizontalSpacer);

        bNouvellePartie = new QPushButton(centralwidget);
        bNouvellePartie->setObjectName(QString::fromUtf8("bNouvellePartie"));

        buttonHLayout->addWidget(bNouvellePartie);


        gridLayout_2->addLayout(buttonHLayout, 2, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        ChifoumiVue->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChifoumiVue);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 978, 20));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        ChifoumiVue->setMenuBar(menubar);
        statusbar = new QStatusBar(ChifoumiVue);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChifoumiVue->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuAide->menuAction());

        retranslateUi(ChifoumiVue);

        QMetaObject::connectSlotsByName(ChifoumiVue);
    } // setupUi

    void retranslateUi(QMainWindow *ChifoumiVue)
    {
        ChifoumiVue->setWindowTitle(QCoreApplication::translate("ChifoumiVue", "ChifoumiVue", nullptr));
        lNomJoueur->setText(QCoreApplication::translate("ChifoumiVue", "Vous", nullptr));
        lScoreJoueur->setText(QCoreApplication::translate("ChifoumiVue", "0", nullptr));
        lActionJoueur->setText(QString());
        lEpees->setText(QString());
        lNomMachine->setText(QCoreApplication::translate("ChifoumiVue", "Machine", nullptr));
        lScoreMachine->setText(QCoreApplication::translate("ChifoumiVue", "0", nullptr));
        lActionMachine->setText(QString());
        bPierre->setText(QString());
        bFeuille->setText(QString());
        bCiseaux->setText(QString());
        bNouvellePartie->setText(QCoreApplication::translate("ChifoumiVue", "Nouvelle Partie", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("ChifoumiVue", "Fichier", nullptr));
        menuAide->setTitle(QCoreApplication::translate("ChifoumiVue", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChifoumiVue: public Ui_ChifoumiVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIFOUMIVUE_H
