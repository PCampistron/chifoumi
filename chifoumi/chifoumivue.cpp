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

    this->setFixedSize(this->sizeHint());

    ui->bNouvellePartie->setFocus();
}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}


void ChifoumiVue::setModele(Chifoumi *m)
{
    _modele = m;
}

void ChifoumiVue::majInterface()
{
    _modele->majScores(_modele->determinerGagnant());

    Chifoumi::UnCoup coupJoueur, coupMachine;

    coupJoueur = _modele->getCoupJoueur();
    coupMachine = _modele->getCoupMachine();

    if (coupJoueur == _modele->ciseau)
    {
        ui->lActionJoueur->setPixmap(QPixmap(":/images/ciseau_115.png"));
    }

    if (coupJoueur == _modele->papier)
    {
        ui->lActionJoueur->setPixmap(QPixmap(":/images/papier_115.png"));
    }

    if (coupJoueur == _modele->pierre)
    {
        ui->lActionJoueur->setPixmap(QPixmap(":/images/pierre_115.png"));
    }

    if (coupJoueur == _modele->rien)
    {
        ui->lActionJoueur->setPixmap(QPixmap(":/images/rien_115.png"));
    }

    if (coupMachine == _modele->ciseau)
    {
        ui->lActionMachine->setPixmap(QPixmap(":/images/ciseau_115.png"));
    }

    if (coupMachine == _modele->papier)
    {
        ui->lActionMachine->setPixmap(QPixmap(":/images/papier_115.png"));
    }

    if (coupMachine == _modele->pierre)
    {
        ui->lActionMachine->setPixmap(QPixmap(":/images/pierre_115.png"));
    }

    if (coupMachine == _modele->rien)
    {
        ui->lActionMachine->setPixmap(QPixmap(":/images/rien_115.png"));
    }

    ui->lScoreJoueur->setText(QString::number(_modele->getScoreJoueur()));

    ui->lScoreMachine->setText(QString::number(_modele->getScoreMachine()));
}


void ChifoumiVue::jouerSigne(char c)
{
    switch (c) {
        case 'c':
            _modele->setCoupJoueur(_modele->ciseau);
            break;
        case 'f':
            _modele->setCoupJoueur(_modele->papier);
            break;
        case 'p':
            _modele->setCoupJoueur(_modele->pierre);
            break;
    }
    _modele->majCoupMachine();

    majInterface();
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

    _modele->initCoups();
    _modele->initScores();

    ui->bCiseaux->setEnabled(true);
    ui->bFeuille->setEnabled(true);
    ui->bPierre->setEnabled(true);

    majInterface();
}

