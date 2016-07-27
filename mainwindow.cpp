#include "mainwindow.h"
#include<QStyleOptionButton>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),button_user(new QPushButton(this)),button_admin(new QPushButton(this)),login(new QPushButton(this)),edit1(new QLineEdit(this))
{

    this->setGeometry(100,100,400,300);
    this->setMaximumSize(400,300);

    setButton();
}

MainWindow::~MainWindow(){
    delete button_user;
    delete button_admin;
    delete login;
    delete edit1;
}



void MainWindow::setButton(){
    button_user->setGeometry(100,100,200,30);
    button_user->setText("User");
    connect(button_admin,&QAbstractButton::clicked,this,&MainWindow::on_click_admin);

    login->setText("Login");
    login->setGeometry(100,150,200,30);
    login->setVisible(false);
    edit1->setVisible(false);

    connect(login,&QAbstractButton::clicked,this,&MainWindow::on_click_login);

    button_admin->setGeometry(100,150,200,30);
    button_admin->setText("Admin");
    connect(button_user,&QAbstractButton::clicked,this,&MainWindow::on_click_user);
}


void MainWindow::on_click_admin(){

    guiAdmin= new AdminWindow(this);
    guiAdmin->setWindowFlags(Qt::Window);
    guiAdmin->show();
    this->hide();
}

void MainWindow::on_click_user(){

    button_admin->setVisible(false);
    button_user->setVisible(false);
    edit1->setVisible(true);
    edit1->setGeometry(100,100,200,30);
    edit1->setText("Inserire nickname");
    login->setVisible(true);


}

void MainWindow::on_click_login(){

    if(edit1->text()=="\0"){
        edit1->setText("Nickname non valido");
    }
    else{
        try{
            guiUser=new UserWindow(this,edit1->text().toStdString());
            guiUser->setWindowFlags(Qt::Window);
            guiUser->show();
            button_admin->setVisible(true);
            button_user->setVisible(true);
            edit1->setVisible(false);
            login->setVisible(false);
            this->hide();
        }
        catch(result e){
            if(e == access_denied){
                edit1->setText("Utente non presente");
            }

        }
    }

}
