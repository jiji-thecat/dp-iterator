#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <vector>
#include "clickable-label.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum struct E_BUTTON
{
    MAKIMONO,
    LIST,
    EKAKI
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVBoxLayout *rootLayout;
    QHBoxLayout *buttonFieldLayout;
    QVBoxLayout *dataFieldLayout;
    ClickableLabel *label;
    void removeDataFieldLayout();
    void setLabel(const char *imagePath, E_BUTTON button);
    bool isShown = false;
    void clearLayout(QLayout* layout);

private slots:
    void makimonoLabelClicked();
    void listLabelClicked();
    void ekakiLabelClicked();

};
#endif // MAINWINDOW_H
