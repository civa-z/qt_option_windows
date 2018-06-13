#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void init_window_animation();
    ~MainWindow();

public slots:
    void button_animation();
    void option_selected();


private:
    Ui::MainWindow *ui;

    QPropertyAnimation *pAnimation;
    QDesktopWidget *pDesktopWidget;
    QLabel* optionalImage1;
    QLabel* optionalImage2;
    QLabel* choiceDesp;
    QPushButton* choseButton1;
    QPushButton* choseButton2;
};

#endif // MAINWINDOW_H
