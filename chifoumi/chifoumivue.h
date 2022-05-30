#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include <chifoumi.h>
#include "chifoumipresentation.h"
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();
    void nvlleConnexion(QObject *c);
    void supprConnexion(QObject *c);
    void majInterface(Chifoumi::UnCoup, Chifoumi::UnCoup, int, int, chifoumiPresentation::etatJeu);

private:
    Ui::ChifoumiVue *ui;
    Chifoumi *_modele;

private slots:
    void aProposDe();
};
#endif // CHIFOUMIVUE_H
