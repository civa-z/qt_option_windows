#include<cstdlib>
#include<ctime>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    optionalImage1 = ui->label;
    optionalImage2 = ui->label_3;
    choiceDesp = ui->label_2;
    choseButton1 = ui->choseButton1;
    choseButton2 = ui->choseButton2;

    init_window_animation();

    optionalImage1->setStyleSheet("border-image:url(:/scene1.jpg);");
    optionalImage2->setStyleSheet("border-image:url(:/scene2.jpg);");
    choseButton1->setStyleSheet("QPushButton{border-image:url(:/face1.png);} QPushButton:pressed{border-image:url(:/face-select1.png);}");
    choseButton2->setStyleSheet("QPushButton{border-image:url(:/face2.png);} QPushButton:pressed{border-image:url(:/face-select2.png);}");

    connect(choseButton1, SIGNAL(clicked()), this, SLOT(option_selected()));
    connect(choseButton2, SIGNAL(clicked()), this, SLOT(option_selected()));
}

void MainWindow::init_window_animation(){
    pAnimation = new QPropertyAnimation(this, "geometry");

    pDesktopWidget = QApplication::desktop();
    int x = (pDesktopWidget->availableGeometry().width() - width()) * 3 / 4;
    int y = (pDesktopWidget->availableGeometry().height() - height()) * 3 / 4;

    pAnimation->setDuration(2000);
    pAnimation->setStartValue(QRect(x, 0, width(), height()));
    pAnimation->setEndValue(QRect(x, y, width(), height()));
    pAnimation->setEasingCurve(QEasingCurve::OutElastic);
    //pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    pAnimation->start(QAbstractAnimation::KeepWhenStopped);
}

void MainWindow::button_animation(){
    /*button->setMinimumSize(40,40);

    QPropertyAnimation* pAnimation_b = new QPropertyAnimation(button, "geometry");

    int x = width()/ 2;
    int y =  height() / 2;

    pAnimation_b->setDuration(2000);
    pAnimation_b->setStartValue(QRect(0,0, 40,40));
    pAnimation_b->setEndValue(QRect(x, y, 80,80));
    //pAnimation_b->setEasingCurve(QEasingCurve::OutElastic);
    //pAnimation_b->setEasingCurve(QEasingCurve::InOutElastic);
    //pAnimation_b->setEasingCurve(QEasingCurve::OutInElastic);
    //pAnimation_b->setEasingCurve(QEasingCurve::InElastic);
    //pAnimation->setKeyValueAt(0, 1);
    //pAnimation->setKeyValueAt(0.5, 0);
    //pAnimation->setKeyValueAt(1, 1);
    //pAnimation_b->setEasingCurve(QEasingCurve::InCirc);
    pAnimation_b->start(QAbstractAnimation::DeleteWhenStopped);*/
}

void MainWindow::option_selected(){
    static const std::vector<std::string> imageList = {
        "material1.jpg",
        "material2.jpg",
        "material3.jpg",
        "scene1.jpg",
        "scene2.jpg",
        "scene3.jpg",
        "scene4.jpg"
    };
    srand((unsigned)time(NULL));
    static int imageid = rand() % imageList.size();
    int nextImageID ;
    do {
        nextImageID = rand() % imageList.size();
    } while(nextImageID == imageid);
    imageid = nextImageID;

    std::string scene1 = "border-image:url(:/" + imageList[imageid] + ");";
    std::string scene2 = "border-image:url(:/" + imageList[(imageid + 1) % imageList.size()] + ");";

    optionalImage1->setStyleSheet(scene1.c_str());
    optionalImage2->setStyleSheet(scene2.c_str());
}

MainWindow::~MainWindow()
{
    delete ui;
}
