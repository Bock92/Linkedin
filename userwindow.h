#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QScrollArea>
#include <QList>
#include <QStringList>
#include<QEvent>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QTextEdit>
#include<typeinfo>
#include <string>
#include <list>
#include "controller.h"
using std::string;
using std::list;

class UserWindow :public QWidget{

    Q_OBJECT
public:
    explicit UserWindow(QWidget *parent =0,string nick ="\0");
    ~UserWindow();

signals:

public slots:

private slots:
    void pf_modClicked();
    void pf_okClicked();
    void l_insClicked();
    void l_removeClicked();
    void studi_insClicked();
    void studi_removeClicked();
    void esp_insClicked();
    void esp_modClicked();
    void esp_add();
    void esp_remove();
    void contatti_add();
    void contatti_remove();
    void ok_searchClicked();
    void restoreUserWindow();


protected:
    bool eventFilter(QObject*,QEvent*);

private:

    void setViewProfilo();
    void setInfoProfilo(const list<string>&);
    void setViewLingue();
    void setViewStudi();
    void setStudiLingueContatti(const list<string>&,string);
    void setViewEsperienze();
    void setEsperienze(const list<string>&);
    void setViewContatti();
    void setNickContatti(const list<string>&);
    list<string> chainContatti(const list<string>&)const;
    void setViewSearch();
    void setTextSearch(const vector<list<string> >&,QTextEdit*);
    static void chainString(string&,list<string>::const_iterator,list<string>::const_iterator,string);


    Controller* control;
    QFrame* frame_window;
    QScrollArea* scroll_window;
    QPushButton* exit;
    QLabel* ettichetta1;
    QLabel* ettichetta2;
    QLabel* ettichetta3;
    QLabel* ettichetta4;
    QLabel* ettichetta5;
    QLabel* ettichetta6; //
    QLabel* acc;
    QLabel* name;
    QLabel* nick;
    QLabel* surname;
    QLabel* date;
    QLabel* mail;
    QLineEdit* a;
    QLineEdit* ni;
    QLineEdit* n;
    QLineEdit* c;
    QLineEdit* m;
    QLineEdit* d;
    QPushButton* pf_ok;
    QPushButton* pf_mod;
    QScrollArea* scroll_language;
    QFrame* frame_language;
    QPushButton* l_ins;
    QList<QLabel*>* label_language;
    QList<QPushButton*>* button_language;
    QFrame* frame_studi;
    QScrollArea* scroll_studi;
    QPushButton* studi_ins;
    QList<QLabel*>* label_studi;
    QList<QPushButton*>* button_studi;
    QScrollArea* scroll_esp;
    QFrame* frame_esp;
    QPushButton* esp_ins;
    QPushButton* esp_mod;
    QPushButton* ok_esp_ins;
    QList<QLabel*>* label_esp;
    QList<QTextEdit*>* text_esp;
    QList<QPushButton*>* button_esp;
    QTextEdit* add_esp;
    QScrollArea* scroll_contatti;
    QFrame* frame_contatti;
    QList<QLabel*>* label_contatti;
    QList<QPushButton*>* button_contatti;
    QStringList* nick_contatti;
    QStringList* nick_search_contatti;
    QFrame* frame_search;
    QScrollArea* scroll_search;
    QPushButton* ok_search;
    QList<QTextEdit*>* text_search;
    QList<QPushButton*>* button_search;

};

#endif // USERWINDOW_H
