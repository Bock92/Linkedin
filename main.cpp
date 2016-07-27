#include"utente.h"
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"
#include"db.h"
#include"linkedinadmin.h"
#include"linkedinclient.h"
#include<iostream>
#include<string>
#include<list>
#include<QApplication>
#include"mainwindow.h"
using std::list;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc,char* argv[]){

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();



}//main
