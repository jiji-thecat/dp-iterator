#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "creature.h"
#include "creature-vector.h"
#include "creature-list.h"
#include "creature-char.h"

#include <QDir>

#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    rootLayout = new QVBoxLayout;
    dataFieldLayout = new QVBoxLayout;
    buttonFieldLayout = new QHBoxLayout;

    setLabel(":/images/assets/makimono.png", E_BUTTON::MAKIMONO);
    setLabel(":/images/assets/list.png", E_BUTTON::LIST);
    setLabel(":/images/assets/ekaki.png", E_BUTTON::EKAKI);

    buttonFieldLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    dataFieldLayout->setAlignment(Qt::AlignBottom | Qt::AlignCenter);
    rootLayout->addLayout(buttonFieldLayout);
    rootLayout->addLayout(dataFieldLayout);
    setFixedSize(800, 500);

    ui->setupUi(this);
    ui->centralwidget->setLayout(rootLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabel(const char* imagePath, E_BUTTON button){
    ClickableLabel *label = new ClickableLabel();
    QPixmap *image = new QPixmap(imagePath);

    label->setPixmap(*image);
    label->setFixedSize(80, 80);
    label->setScaledContents(true);

    switch (button){
        case E_BUTTON::MAKIMONO:
            connect(label, SIGNAL(clicked()), this, SLOT(makimonoLabelClicked()));
        break;
        case E_BUTTON::LIST:
            connect(label, SIGNAL(clicked()), this, SLOT(listLabelClicked()));
        break;
        case E_BUTTON::EKAKI:
            connect(label, SIGNAL(clicked()), this, SLOT(ekakiLabelClicked()));
        break;
    }

    buttonFieldLayout->addWidget(label);
}

void MainWindow::clearLayout(QLayout* layout)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout()) {
            clearLayout(childLayout);
        }

        delete item;
    }
}

void MainWindow::removeDataFieldLayout(){
    clearLayout(dataFieldLayout);
}

template<typename TYPE> void MainWindow::generateCreatures(TYPE container, E_BUTTON button){
    const char *containerName = {}; // constの後ろにある*はアドレス変更可、オブジェクト変更不可

    switch (button){
        case E_BUTTON::MAKIMONO:
            containerName = "MAKIMONO";
        break;
        case E_BUTTON::LIST:
            containerName = "LIST";
        break;
        case E_BUTTON::EKAKI:
            containerName = "EKAKI";
        break;
    }

    QHBoxLayout *childLayout = new QHBoxLayout;
    QLabel *label1 = new QLabel(containerName);
    label1->setStyleSheet("font-weight: bold; color: red");
    childLayout->addWidget(label1);
    label1->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    dataFieldLayout->addLayout(childLayout);

    Creature rabbit1;
    rabbit1.setName("うさぎ");
    rabbit1.setSound("むしゃむしゃ");
    rabbit1.setFood("にんじん");
    container.add(rabbit1);

    Creature alien;
    alien.setName("エイリアン");
    alien.setSound("ワレワレハ");
    alien.setFood("牛");
    container.add(alien);

    Creature snake;
    snake.setName("へび");
    snake.setSound("th th th");
    snake.setFood("ネズミ");
    container.add(snake);

    IteratorInterface *it = container.iterator();

    while (it->isLast()) {
      QHBoxLayout *childLayout = new QHBoxLayout;
      Creature creature = it->next();

      QString name = QString("Name: %1").arg(creature.getName().c_str());
      QString sound = QString("Sound: %1").arg(creature.getSound().c_str());
      QString food = QString("Food: %1").arg(creature.getFood().c_str());

      QLabel *label1 = new QLabel(name);
      QLabel *label2 = new QLabel(sound);
      QLabel *label3 = new QLabel(food);

      childLayout->addWidget(label1);
      childLayout->addWidget(label2);
      childLayout->addWidget(label3);
      dataFieldLayout->addLayout(childLayout);
    }

    isShown = true;
}

void MainWindow::makimonoLabelClicked(){
    if (isShown){
        removeDataFieldLayout();
    }

    CreatureVector cv(3);
    generateCreatures(cv, E_BUTTON::MAKIMONO);
}

void MainWindow::listLabelClicked(){
    if (isShown){
        removeDataFieldLayout();
    }

    CreatureList cl(3);
    generateCreatures(cl, E_BUTTON::LIST);
}

void MainWindow::ekakiLabelClicked(){
    if (isShown){
        removeDataFieldLayout();
    }

    CreatureChar cc(3);
    generateCreatures(cc, E_BUTTON::EKAKI);
}
