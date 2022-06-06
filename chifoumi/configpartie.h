#ifndef CONFIGPARTIE_H
#define CONFIGPARTIE_H

#include <QDialog>

namespace Ui {
class ConfigPartie;
}

class ConfigPartie : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigPartie(QWidget *parent = nullptr);
    ~ConfigPartie();
    QString getNomJoueur();
    unsigned int getScoreMax();
    unsigned int getTempsMax();

private:
    QString nomJoueur;
    unsigned int scoreMax;
    unsigned int tempsMax;
    Ui::ConfigPartie *ui;
};

#endif // CONFIGPARTIE_H
