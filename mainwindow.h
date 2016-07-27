#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include <QLineEdit>
#include<adminwindow.h>
#include<userwindow.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_click_admin();
    void on_click_user();
    void on_click_login();

signals:

private:
    QPushButton *button_user;
    QPushButton *button_admin;
    QPushButton *login;
    QLineEdit* edit1;
    QWidget* guiAdmin;
    QWidget* guiUser;

    void setButton();




};

#endif // MAINWINDOW_H
