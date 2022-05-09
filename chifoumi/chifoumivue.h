#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include <chifoumi.h>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();
    void setModele(Chifoumi *m);
    void majInterface();

public slots:
    void jouerSigne(char c);
    void jouerCiseaux();
    void jouerFeuille();
    void jouerPierre();
    void initialiserPartie();

private:
    Ui::ChifoumiVue *ui;
    Chifoumi *_modele;
};
#endif // CHIFOUMIVUE_H
