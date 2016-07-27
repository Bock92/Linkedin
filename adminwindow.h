#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QRadioButton>
#include <QTextEdit>
#include <vector>
#include <list>
#include <string>
#include <map>
#include "controller.h"
#include "eccezioni.h"
using std::list;
using std::string;
using std::vector;
using std::map;

class AdminWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

signals:

public slots:

private slots:
    void changeQFrameDx();
    void okClicked();
    void saveClicked();
    void restoreAdminWindow();

private:
    static void chainString(string&,list<string>::const_iterator,list<string>::const_iterator,string);
    static void setTextView(const map<string,vector<list<string> > >&,QTextEdit*);
    static void setTextView(const vector<list<string> >&,QTextEdit*);
    void showQFrameDxContent(int x=0);
    void setQFrameDx();
    void setQTreeWidget();


    Controller* control;
    QFrame* dx;
    QFrame* dxRadioButton;
    QFrame* pushButton;
    QTreeWidget* tree;
    QLabel* lb1;
    QLabel* lb2;
    QLabel* lb3;
    QLabel* lb4;
    QLabel* lb5;
    QLineEdit* text1;
    QLineEdit* text2;
    QLineEdit* text3;
    QRadioButton* op1;
    QRadioButton* op2;
    QRadioButton* op3;
    QPushButton* ok;
    QPushButton* save;
    QPushButton* exit;
    QTextEdit* view;





};

#endif // ADMINWINDOW_H
