#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include <QDebug>

chifoumiPresentation::chifoumiPresentation(Chifoumi *m, QObject *parent)
    : QObject(parent),
      timer(new QTimer),
      _modele(m),
      etat(etatInitial)
{

}

chifoumiPresentation::~chifoumiPresentation() {

}

Chifoumi *chifoumiPresentation::getModele()
{
    return _modele;
}

ChifoumiVue *chifoumiPresentation::getVue()
{
    return _vue;
}

void chifoumiPresentation::setModele(Chifoumi *m)
{
    _modele = m;
}

void chifoumiPresentation::setVue(ChifoumiVue *v)
{
    _vue = v;
}

void chifoumiPresentation::jouerSigne(char c)
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

    _modele->majScores(_modele->determinerGagnant());

    _vue->majInterface(_modele->getCoupJoueur(), _modele->getCoupMachine(), _modele->getNomJoueur(), _modele->getScoreJoueur(), _modele->getScoreMachine(), _modele->getScoreMax(), _modele->getTempsRestant(), getEtat());

    testGagnant();
}

chifoumiPresentation::etatJeu chifoumiPresentation::getEtat()
{
    return etat;
}

void chifoumiPresentation::setEtat(chifoumiPresentation::etatJeu etatVoulu)
{
    etat = etatVoulu;
}

void chifoumiPresentation::testGagnant()
{
    if(_modele->getScoreJoueur() >= _modele->getScoreMax())
    {
        timer->stop();
        QMessageBox *msgBox = new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setText("Bravo Vous ! Vous gagnez avec 5 points.");
        msgBox->setWindowTitle("Fin de partie");
        msgBox->exec();


        setEtat(etatInitial);
        _vue->majInterface(_modele->getCoupJoueur(), _modele->getCoupMachine(), _modele->getNomJoueur(), _modele->getScoreJoueur(), _modele->getScoreMachine(), _modele->getScoreMax(), _modele->getTempsRestant(), getEtat());
    }
    if(_modele->getScoreMachine() >= _modele->getScoreMax())
    {
        timer->stop();
        QMessageBox *msgBox = new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setText("Bravo La Machine ! Vous gagnez avec 5 points.");
        msgBox->setWindowTitle("Fin de partie");
        msgBox->exec();


        setEtat(etatInitial);
        _vue->majInterface(_modele->getCoupJoueur(), _modele->getCoupMachine(), _modele->getNomJoueur(), _modele->getScoreJoueur(), _modele->getScoreMachine(), _modele->getScoreMax(), _modele->getTempsRestant(), getEtat());
    }

    if(_modele->getTempsRestant() <= 0)
    {
        timer->stop();
        if(_modele->getScoreJoueur() > _modele->getScoreMachine())
        {
            QMessageBox *msgBox = new QMessageBox;
            msgBox->setIcon(QMessageBox::Information);
            msgBox->setStandardButtons(QMessageBox::Ok);
            QString *message = new QString("Hélas chers joueurs, temps de jeu fini ! Vous terminez toutefois mieux, avec ");
            message->append(QString::number(_modele->getScoreJoueur()));
            message->append(" points.");
            msgBox->setText(*message);
            msgBox->setWindowTitle("Fin de partie");
            msgBox->exec();
        }

        if(_modele->getScoreJoueur() < _modele->getScoreMachine())
        {
            QMessageBox *msgBox = new QMessageBox;
            msgBox->setIcon(QMessageBox::Information);
            msgBox->setStandardButtons(QMessageBox::Ok);
            QString *message = new QString("Hélas chers joueurs, temps de jeu fini ! La machine termine toutefois mieux, avec ");
            message->append(QString::number(_modele->getScoreMachine()));
            message->append(" points.");
            msgBox->setText(*message);
            msgBox->setWindowTitle("Fin de partie");
            msgBox->exec();
        }

        if(_modele->getScoreJoueur() == _modele->getScoreMachine())
        {
            QMessageBox *msgBox = new QMessageBox;
            msgBox->setIcon(QMessageBox::Information);
            msgBox->setStandardButtons(QMessageBox::Ok);
            msgBox->setText("Hélas chers joueurs, temps de jeu fini ! Vous êtes à égalité.");
            msgBox->setWindowTitle("Fin de partie");
            msgBox->exec();
        }


        setEtat(etatInitial);
        _vue->majInterface(_modele->getCoupJoueur(), _modele->getCoupMachine(), _modele->getNomJoueur(), _modele->getScoreJoueur(), _modele->getScoreMachine(), _modele->getScoreMax(), _modele->getTempsRestant(), getEtat());
    }
}

void chifoumiPresentation::configurerPartie()
{
    ConfigPartie *config = new ConfigPartie(nullptr);

    int accept = config->exec();

    if(accept == QDialog::Accepted)
    {
        _modele->setNomJoueur(config->getNomJoueur().toStdString());
        _modele->setScoreMax(config->getScoreMax());
        _modele->setDureePartie(config->getTempsMax());
        _vue->majInterface(_modele->getCoupJoueur(), _modele->getCoupMachine(), _modele->getNomJoueur(), _modele->getScoreJoueur(), _modele->getScoreMachine(), _modele->getScoreMax(), _modele->getTempsRestant(), getEtat());
    }
}

void chifoumiPresentation::actionPause()
{
    if(etat == pause)
    {
        timer->start();
        setEtat(partieEnCours);
    }
    else
    {
        timer->stop();
        setEtat(pause);
    }
    _vue->majInterface(_modele->getCoupJoueur(), _modele->getCoupMachine(), _modele->getNomJoueur(), _modele->getScoreJoueur(), _modele->getScoreMachine(), _modele->getScoreMax(), _modele->getTempsRestant(), getEtat());
}

void chifoumiPresentation::jouerCiseaux()
{
    emit(jouerSigne('c'));
}

void chifoumiPresentation::jouerFeuille()
{
    emit(jouerSigne('f'));
}

void chifoumiPresentation::jouerPierre()
{
    emit(jouerSigne('p'));
}

void chifoumiPresentation::aProposDe()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setText("Version 5 \nProgramme modèle de Campistron - Doyhenard - Sokhna");
    msgBox->setWindowTitle("A propos de cette application");
    msgBox->exec();
}

void chifoumiPresentation::tic()
{
    _modele->decTemps();
    _vue->majInterface(_modele->getCoupJoueur(), _modele->getCoupMachine(), _modele->getNomJoueur(), _modele->getScoreJoueur(), _modele->getScoreMachine(), _modele->getScoreMax(), _modele->getTempsRestant(), getEtat());
    testGagnant();
}

void chifoumiPresentation::initialiserPartie()
{
    _modele->initCoups();
    _modele->initScores();

    setEtat(partieEnCours);

    connect(timer, SIGNAL(timeout()),
            this, SLOT(tic()));

    _modele->initTemps();

    timer->setInterval(intervalleTimer);
    timer->start();

    _vue->majInterface(_modele->getCoupJoueur(), _modele->getCoupMachine(), _modele->getNomJoueur(), _modele->getScoreJoueur(), _modele->getScoreMachine(), _modele->getScoreMax(), _modele->getTempsRestant(), getEtat());
}

void chifoumiPresentation::demanderPremiereMajInterface()
{
    _vue->majInterface(_modele->getCoupJoueur(), _modele->getCoupMachine(), _modele->getNomJoueur(), _modele->getScoreJoueur(), _modele->getScoreMachine(), _modele->getScoreMax(), _modele->getTempsRestant(), getEtat());
}

