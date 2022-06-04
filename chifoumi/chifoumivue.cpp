#include "chifoumivue.h"
#include "ui_chifoumivue.h"

ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);

    this->setFixedSize(this->sizeHint());

    ui->bNouvellePartie->setFocus();
}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

void ChifoumiVue::nvlleConnexion(QObject *c)
{
    connect(ui->bCiseaux, SIGNAL(clicked()),
            c, SLOT(jouerCiseaux()));

    connect(ui->bFeuille, SIGNAL(clicked()),
            c, SLOT(jouerFeuille()));

    connect(ui->bPierre, SIGNAL(clicked()),
            c, SLOT(jouerPierre()));

    connect(ui->bNouvellePartie, SIGNAL(clicked()),
            c, SLOT(initialiserPartie()));

    connect(ui->actionA_propos_de, SIGNAL(triggered()),
            c, SLOT(aProposDe()));

    connect(this, SIGNAL(premiereMajInterface()),
            c, SLOT(demanderPremiereMajInterface()));

    emit(premiereMajInterface());
}

void ChifoumiVue::supprConnexion(QObject *c)
{
    disconnect(ui->bCiseaux, SIGNAL(clicked()),
               c, SLOT(jouerCiseaux()));

    disconnect(ui->bFeuille, SIGNAL(clicked()),
               c, SLOT(jouerFeuille()));

    disconnect(ui->bPierre, SIGNAL(clicked()),
               c, SLOT(jouerPierre()));

    disconnect(ui->bNouvellePartie, SIGNAL(clicked()),
               c, SLOT(initialiserPartie()));

    disconnect(ui->actionA_propos_de, SIGNAL(triggered()),
               c, SLOT(aProposDe()));
}

void ChifoumiVue::majInterface(Chifoumi::UnCoup coupJoueur, Chifoumi::UnCoup coupMachine, int scoreJoueur, int scoreMachine, int scoreMax, chifoumiPresentation::etatJeu etatJeu)
{
    if (coupJoueur == Chifoumi::ciseau)
    {
        ui->lActionJoueur->setPixmap(QPixmap(":/images/ciseau_115.png"));
    }

    if (coupJoueur == Chifoumi::papier)
    {
        ui->lActionJoueur->setPixmap(QPixmap(":/images/papier_115.png"));
    }

    if (coupJoueur == Chifoumi::pierre)
    {
        ui->lActionJoueur->setPixmap(QPixmap(":/images/pierre_115.png"));
    }

    if (coupJoueur == Chifoumi::rien)
    {
        ui->lActionJoueur->setPixmap(QPixmap(":/images/rien_115.png"));
    }

    if (coupMachine == Chifoumi::ciseau)
    {
        ui->lActionMachine->setPixmap(QPixmap(":/images/ciseau_115.png"));
    }

    if (coupMachine == Chifoumi::papier)
    {
        ui->lActionMachine->setPixmap(QPixmap(":/images/papier_115.png"));
    }

    if (coupMachine == Chifoumi::pierre)
    {
        ui->lActionMachine->setPixmap(QPixmap(":/images/pierre_115.png"));
    }

    if (coupMachine == Chifoumi::rien)
    {
        ui->lActionMachine->setPixmap(QPixmap(":/images/rien_115.png"));
    }

    ui->lScoreJoueur->setText(QString::number(scoreJoueur));

    ui->lScoreMachine->setText(QString::number(scoreMachine));

    ui->lScoreMax->setText(QString::number(scoreMax));

    switch(etatJeu)
    {
    case chifoumiPresentation::etatInitial:
        ui->bCiseaux->setEnabled(false);
        ui->bFeuille->setEnabled(false);
        ui->bPierre->setEnabled(false);
        break;
    case chifoumiPresentation::partieEnCours:
        ui->bCiseaux->setEnabled(true);
        ui->bFeuille->setEnabled(true);
        ui->bPierre->setEnabled(true);
    }
}



