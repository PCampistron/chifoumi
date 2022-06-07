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

    connect(ui->bPause, SIGNAL(clicked()),
            c, SLOT(actionPause()));

    connect(ui->actionA_propos_de, SIGNAL(triggered()),
            c, SLOT(aProposDe()));

    connect(ui->actionParametrer, SIGNAL(triggered()),
            c, SLOT(configurerPartie()));

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

    disconnect(ui->bPause, SIGNAL(clicked()),
            c, SLOT(actionPause()));

    disconnect(this, SIGNAL(premiereMajInterface()),
            c, SLOT(demanderPremiereMajInterface()));

    disconnect(ui->actionA_propos_de, SIGNAL(triggered()),
               c, SLOT(aProposDe()));
}

void ChifoumiVue::changerCouleurNom(ChifoumiVue::Joueur joueur)
{
    switch(joueur)
    {
    case ChifoumiVue::humain:
        ui->lScoreJoueur->setStyleSheet("color: blue");
        ui->lNomJoueur->setStyleSheet("color: blue");
        ui->lScoreMachine->setStyleSheet("color: black");
        ui->lNomMachine->setStyleSheet("color: black");
        break;
    case ChifoumiVue::machine:
        ui->lScoreMachine->setStyleSheet("color: blue");
        ui->lNomMachine->setStyleSheet("color: blue");
        ui->lScoreJoueur->setStyleSheet("color: black");
        ui->lNomJoueur->setStyleSheet("color: black");
    }
}

void ChifoumiVue::majInterface(Chifoumi::UnCoup coupJoueur, Chifoumi::UnCoup coupMachine, string nomJoueur, int scoreJoueur, int scoreMachine, int scoreMax, int tempsRestant, chifoumiPresentation::etatJeu etatJeu)
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

    ui->lNomJoueur->setText(QString::fromStdString(nomJoueur));

    ui->lScoreJoueur->setText(QString::number(scoreJoueur));

    ui->lScoreMachine->setText(QString::number(scoreMachine));

    ui->lScoreMax->setText(QString::number(scoreMax));

    QString *temps = new QString("Tps restant (s) : ");

    temps->append(QString::number(tempsRestant));

    ui->lTempsRestant->setText(*temps);

    switch(etatJeu)
    {
    case chifoumiPresentation::etatInitial:
        ui->bPause->setEnabled(false);
        ui->bCiseaux->setEnabled(false);
        ui->bFeuille->setEnabled(false);
        ui->bPierre->setEnabled(false);
        break;
    case chifoumiPresentation::partieEnCours:
        ui->bPause->setEnabled(true);
        ui->bCiseaux->setEnabled(true);
        ui->bFeuille->setEnabled(true);
        ui->bPierre->setEnabled(true);
        break;
    case chifoumiPresentation::pause:
        ui->bPause->setEnabled(true);
        ui->bCiseaux->setEnabled(false);
        ui->bFeuille->setEnabled(false);
        ui->bPierre->setEnabled(false);
        break;
    }
}



