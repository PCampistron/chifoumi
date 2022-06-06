#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>
#include <chifoumipresentation.h>

namespace Ui {
class Connexion;
}

class Connexion : public QDialog
{
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = nullptr);
    ~Connexion();
    QString getUsername();
    QString getMdp();
private:
    Ui::Connexion *ui;
};

#endif // CONNEXION_H
