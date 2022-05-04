#include "chifoumivue.h"
#include "ui_chifoumivue.h"

ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);

    connect(ui->bCiseaux, SIGNAL(clicked()),
            this, SLOT(jouerCiseaux()));

    connect(ui->bFeuille, SIGNAL(clicked()),
            this, SLOT(jouerFeuille()));

    connect(ui->bPierre, SIGNAL(clicked()),
            this, SLOT(jouerPierre()));

    connect(ui->bNouvellePartie, SIGNAL(clicked()),
            this, SLOT(initialiserPartie()));

}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}


void ChifoumiVue::setModele(Chifoumi *m)
{
    _modele = m;
}


void ChifoumiVue::jouerSigne(char c)
{
    QString signe;
    switch (c) {
        case 'c':
            signe = "Ciseaux";
            break;
        case 'f':
            signe = "Feuille";
            break;
        case 'p':
            signe = "Pierre";
            break;
    }
    qDebug() << signe;
}

void ChifoumiVue::jouerCiseaux()
{
    emit(jouerSigne('c'));
}

void ChifoumiVue::jouerFeuille()
{
    emit(jouerSigne('f'));
}

void ChifoumiVue::jouerPierre()
{
    emit(jouerSigne('p'));
}

void ChifoumiVue::initialiserPartie()
{
    qDebug() << "Initialisation de la partie";
}

