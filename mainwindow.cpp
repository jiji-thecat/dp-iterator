#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "creature.h"
#include "creature-vector.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    rootLayout = new QVBoxLayout;
    dataFieldLayout = new QVBoxLayout;
    buttonFieldLayout = new QHBoxLayout;

    setLabel("/Users/jiji/workspace/qt/iterator/iterator/assets/makimono.png", E_BUTTON::MAKIMONO);
    setLabel("/Users/jiji/workspace/qt/iterator/iterator/assets/list.png", E_BUTTON::LIST);
    setLabel("/Users/jiji/workspace/qt/iterator/iterator/assets/ekaki.png", E_BUTTON::EKAKI);

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

void MainWindow::setLabel(const char *imagePath, E_BUTTON button){
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

void MainWindow::makimonoLabelClicked(){
    if (isShown){
        removeDataFieldLayout();
    }

    CreatureVector cv(3);

    Creature rabbit1;
    rabbit1.setName("rabbit makimono");
    rabbit1.setSound("bubu");
    rabbit1.setFood("carrot");
    cv.add(rabbit1);

    Creature alien;
    alien.setName("alien");
    alien.setSound("mohemohe");
    alien.setFood("snail");
    cv.add(alien);

    Creature snake;
    snake.setName("snake");
    snake.setSound("thhh");
    snake.setFood("egg");
    cv.add(snake);


    IteratorInterface *it = cv.iterator();

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

void MainWindow::listLabelClicked(){
    if (isShown){
        removeDataFieldLayout();
    }

    CreatureVector cv(3);

    Creature rabbit1;
    rabbit1.setName("rabbit list");
    rabbit1.setSound("bubu");
    rabbit1.setFood("carrot");
    cv.add(rabbit1);

    Creature alien;
    alien.setName("alien");
    alien.setSound("mohemohe");
    alien.setFood("snail");
    cv.add(alien);

    Creature snake;
    snake.setName("snake");
    snake.setSound("thhh");
    snake.setFood("egg");
    cv.add(snake);


    IteratorInterface *it = cv.iterator();

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

void MainWindow::ekakiLabelClicked(){
    if (isShown){
        removeDataFieldLayout();
    }

    CreatureVector cv(3);

    Creature rabbit1;
    rabbit1.setName("rabbit ekaki");
    rabbit1.setSound("bubu");
    rabbit1.setFood("carrot");
    cv.add(rabbit1);

    /*Creature alien;
    alien.setName("alien");
    alien.setSound("mohemohe");
    alien.setFood("snail");
    cv.add(alien);

    Creature snake;
    snake.setName("snake");
    snake.setSound("thhh");
    snake.setFood("egg");
    cv.add(snake);
    */

    IteratorInterface *it = cv.iterator();

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
