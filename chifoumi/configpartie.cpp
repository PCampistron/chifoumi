#include "configpartie.h"
#include "ui_configpartie.h"

ConfigPartie::ConfigPartie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigPartie)
{
    ui->setupUi(this);
}

ConfigPartie::~ConfigPartie()
{
    delete ui;
}

QString ConfigPartie::getNomJoueur()
{
    return ui->lineNom->text();
}

unsigned int ConfigPartie::getScoreMax()
{
    return ui->lineMaxPoints->text().toInt();
}

unsigned int ConfigPartie::getTempsMax()
{
    return ui->lineMaxTemps->text().toInt();
}
