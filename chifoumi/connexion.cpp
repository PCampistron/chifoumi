#include "connexion.h"
#include "ui_connexion.h"
#include "QDebug"

Connexion::Connexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connexion)
{
    ui->setupUi(this);
}

Connexion::~Connexion()
{
    delete ui;
}

QString Connexion::getUsername()
{
    return(ui->lineUsername->text());
}

QString Connexion::getMdp()
{
    return(ui->lineMdp->text());
}
