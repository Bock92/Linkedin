#include "userwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDate>
#include<iostream>

UserWindow::UserWindow(QWidget *parent,string nick):QWidget(parent){
    try{
        control=new Controller("user",nick);

    }
    catch(result){ this->parentWidget()->show(); throw;}

    this->setGeometry(100,80,750,680);
    this->setMaximumSize(750,680);

    frame_window=new QFrame(this);
    frame_window->setGeometry(0,0,725,1300);
    scroll_window=new QScrollArea(this);
    scroll_window->setGeometry(0,0,750,680);
    scroll_window->setWidget(frame_window);
    scroll_window->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    exit=new QPushButton("Exit",frame_window);
    exit->setGeometry(650,0,75,25);
    connect(exit,&QAbstractButton::clicked,this,&UserWindow::restoreUserWindow);

    setViewProfilo();
    setViewLingue();
    setViewStudi();
    setViewEsperienze();
    setViewContatti();
    setViewSearch();


}

UserWindow::~UserWindow(){

    if(scroll_window){delete scroll_window;}
    if(control) delete control;

}

void UserWindow::setViewProfilo(){

    ettichetta1=new QLabel("Profilo",frame_window);
    ettichetta1->setGeometry(0,0,80,30);
    ettichetta1->setStyleSheet("font-size:25px;");

    pf_mod=new QPushButton("Modifica",frame_window);
    pf_mod->setGeometry(85,5,75,25);

    connect(pf_mod,&QAbstractButton::clicked,this,&UserWindow::pf_modClicked);

    pf_ok=new QPushButton("Conferma",frame_window);
    pf_ok->setGeometry(250,5,75,25);
    pf_ok->setVisible(false);

    connect(pf_ok,&QAbstractButton::clicked,this,&UserWindow::pf_okClicked);

    acc=new QLabel("Account",frame_window);
    name=new QLabel("Nome",frame_window);
    nick=new QLabel("Nickname",frame_window);
    surname=new QLabel("Cognome",frame_window);
    date=new QLabel("Data di nascita",frame_window);
    mail=new QLabel("Mail",frame_window);

    acc->setGeometry(10,40,100,20);
    name->setGeometry(10,65,100,20);
    nick->setGeometry(375,40,100,20);
    surname->setGeometry(375,65,100,20);
    date->setGeometry(10,90,100,20);
    mail->setGeometry(375,90,100,20);

    a=new QLineEdit(frame_window);
    ni=new QLineEdit(frame_window);
    n=new QLineEdit(frame_window);
    c=new QLineEdit(frame_window);
    m=new QLineEdit(frame_window);
    d=new QLineEdit(frame_window);

    a->setGeometry(115,40,160,25);
    n->setGeometry(115,65,160,25);
    ni->setGeometry(475,40,160,25);
    c->setGeometry(475,65,160,25);
    d->setGeometry(475,90,160,25); //475,90,160,25
    m->setGeometry(115,90,160,25);

    //inizializzare i vari QLineEdit
    list<string> lista;
    control->readProfiloUtente(lista);


    setInfoProfilo(lista);

    a->setReadOnly(true);
    ni->setReadOnly(true);
    n->setReadOnly(true);
    c->setReadOnly(true);
    d->setReadOnly(true);
    m->setReadOnly(true);
}


void UserWindow::setInfoProfilo(const list<string>& lista){
    //account/username/nome/cognome/mail/data
   if(lista.size()>0){
       list<string>::const_iterator i=lista.begin();
        a->setText(QString::fromStdString(*(i++)));
        ni->setText(QString::fromStdString(*(i++)));
        n->setText(QString::fromStdString(*(i++)));
        c->setText(QString::fromStdString(*(i++)));
        d->setText(QString::fromStdString(*(i++)));
        m->setText(QString::fromStdString(*(i++)));
   }
}

void UserWindow::pf_okClicked(){

    string s1="\n",s2="\n",s3="\n",s4="\n";
    bool ok=true;

    QRegularExpression esp1= QRegularExpression("^[a-z]+$");
    QRegularExpression esp2= QRegularExpression("^[a-z0-9]+@[a-z]+.[a-z]+$");
    QDate x(m->text().section('/',2,2).toInt(),m->text().section('/',1,1).toInt(),m->text().section('/',0,0).toInt());



    if(n->isModified()){
        if((esp1.match(n->text())).hasMatch()){
            s1=n->text().toStdString();
        }
        else{QMessageBox::warning(this,"Errore","Nome non valido, digitare una sequenza di caratteri minuscoli"); ok=false;}

    }

    if(c->isModified()){
        if((esp1.match(c->text())).hasMatch()){
            s2=c->text().toStdString();
        }
        else{QMessageBox::warning(this,"Errore","Cognome non valido, digitare una sequenza di caratteri minuscoli");ok=false;}

    }

    if(d->isModified()){
        if((esp2.match(d->text())).hasMatch()){
            s3=d->text().toStdString();
        }
        else{QMessageBox::warning(this,"Errore","Mail non valida");ok=false;}

    }

    if(m->isModified()){
        if(x.isValid()){
            s4=m->text().toStdString();
        }
        else{QMessageBox::warning(this,"Errore","Data non valida (GG/MM/AAAA)");ok=false;}

    }

    if(ok){

        try{
            control->changeProfilo(s1,s2,s3,s4);
        }

        catch(result e){
            if(e == change_profilo_ok){
                control->save();
            }


        }
    }

    n->setReadOnly(true);
    c->setReadOnly(true);
    m->setReadOnly(true);
    d->setReadOnly(true);
    pf_mod->setVisible(true);
    pf_ok->setVisible(false);
}

void UserWindow::pf_modClicked(){

    n->setReadOnly(false);
    c->setReadOnly(false);
    m->setReadOnly(false);
    d->setReadOnly(false);
    pf_mod->setVisible(false);
    pf_ok->setVisible(true);
}

void UserWindow::setViewLingue(){

    ettichetta2= new QLabel("Lingue",frame_window);
    ettichetta2->setGeometry(0,545,750,30);
    ettichetta2->setStyleSheet("font-size:25px;border-top:1px;border-color:black;border-style:solid;");

    l_ins=new QPushButton("Aggiungi",frame_window);
    l_ins->setGeometry(100,550,75,25);
    connect(l_ins,&QAbstractButton::clicked,this,&UserWindow::l_insClicked);

    frame_language=new QFrame(frame_window);
    frame_language->setGeometry(5,0,361,100);

    scroll_language=new QScrollArea(frame_window);
    scroll_language->setGeometry(5,585,380,100);
    scroll_language->setWidget(frame_language);
    scroll_language->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    label_language=new QList<QLabel*>();
    button_language=new QList<QPushButton*>();

    list<string> lista;
    control->readListInfo(lista,"Lingue");
    setStudiLingueContatti(lista,"lingue");


}

void UserWindow::setViewStudi(){
    ettichetta3=new QLabel("Studi",frame_window);
    ettichetta3->setGeometry(0,150,750,30);
    ettichetta3->setStyleSheet("font-size:25px;border-top:1px;border-color:black;border-style:solid;");

    studi_ins=new QPushButton("Aggiungi",frame_window);
    studi_ins->setGeometry(85,155,75,25);
    connect(studi_ins,&QAbstractButton::clicked,this,&UserWindow::studi_insClicked);

    frame_studi=new QFrame(frame_window);
    frame_studi->setGeometry(5,170,360,110);

    scroll_studi=new QScrollArea(frame_window);
    scroll_studi->setGeometry(5,195,380,100);
    scroll_studi->setWidget(frame_studi);
    scroll_studi->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    label_studi=new QList<QLabel*>();
    button_studi= new QList<QPushButton*>();

    list<string> lista;
    control->readListInfo(lista,"Studi");
    setStudiLingueContatti(lista,"studi");



}
void UserWindow::setStudiLingueContatti(const list<string>& lista,string nome_lista){

    int x=5,y=3,z=250,w=20;
    QFrame* frame_tmp=0;

    if(nome_lista == "studi"){
        frame_tmp=frame_studi;
    }
    else if(nome_lista =="lingue"){
        frame_tmp=frame_language;

    }
    else if(nome_lista == "contatti"){
        frame_tmp=frame_contatti;

    }

        for(list<string>::const_iterator inizio=lista.begin();inizio!=lista.end();inizio++){
            QPushButton* b_tmp=new QPushButton("Rimuovi",frame_tmp);
            QLabel* lb_tmp=new QLabel(QString::fromStdString(*inizio),frame_tmp);


            lb_tmp->setGeometry(x,y,z,w);
            b_tmp->setGeometry(z+x,y+2,70,20);

            y=y+w+5;
            if(frame_tmp == frame_studi){
                connect(b_tmp,&QAbstractButton::clicked,this,&UserWindow::studi_removeClicked);
                label_studi->append(lb_tmp);
                button_studi->append(b_tmp);

                if(frame_studi->height()<y+w){
                    frame_studi->setGeometry(frame_studi->x(),frame_studi->y(),frame_studi->width(),frame_studi->height()+100);
                }
            }
            else if(frame_tmp == frame_language){
                connect(b_tmp,&QAbstractButton::clicked,this,&UserWindow::l_removeClicked);
                label_language->append(lb_tmp);
                button_language->append(b_tmp);

            }
            else if(frame_tmp == frame_contatti){
                connect(b_tmp,&QAbstractButton::clicked,this,&UserWindow::contatti_remove);
                label_contatti->append(lb_tmp);
                button_contatti->append(b_tmp);

            }

            if(frame_tmp->height()<y+w){
                frame_tmp->setGeometry(frame_tmp->x(),frame_tmp->y(),frame_tmp->width(),frame_tmp->height()+100);
            }

        }
}



void UserWindow::setViewEsperienze(){
    ettichetta4=new QLabel("Esperienze",frame_window);
    ettichetta4->setGeometry(0,325,750,30);
    ettichetta4->setStyleSheet("font-size:25px;border-top:1px;border-color:black;border-style:solid;");

    esp_ins=new QPushButton("Aggiungi",frame_window);
    esp_ins->setGeometry(135,330,75,25);
    connect(esp_ins,&QAbstractButton::clicked,this,&UserWindow::esp_insClicked);

    esp_mod=new QPushButton("Modifica",frame_window);
    esp_mod->setGeometry(225,330,75,25);
    connect(esp_mod,&QAbstractButton::clicked,this,&UserWindow::esp_modClicked);

    add_esp= new QTextEdit("Inserire descrizione di un'esperienza lavorativa",frame_window);
    add_esp->setGeometry(390,365,310,70);
    add_esp->setVisible(false);

    ok_esp_ins=new QPushButton("Conferma",frame_window);
    ok_esp_ins->setGeometry(600,440,75,25);
    ok_esp_ins->setVisible(false);
    connect(ok_esp_ins,&QAbstractButton::clicked,this,&UserWindow::esp_add);

    frame_esp=new QFrame(frame_window);
    frame_esp->setGeometry(5,170,360,160);

    scroll_esp=new QScrollArea(frame_window);
    scroll_esp->setGeometry(5,365,380,150);
    scroll_esp->setWidget(frame_esp);
    scroll_esp->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    label_esp=new QList<QLabel*>();
    button_esp= new QList<QPushButton*>();
    text_esp=new QList<QTextEdit*>();

    list<string> lista;
    control->readListInfo(lista,"Esperienze");
    setEsperienze(lista);
}

void UserWindow::setEsperienze(const list<string>& lista){
    int x=5,y=3,z=10,w=20;
    int i=1;
        for(list<string>::const_iterator inizio=lista.begin();inizio!=lista.end();inizio++){
            QPushButton* b_tmp=new QPushButton("Rimuovi",frame_esp);
            QLabel* lb_tmp=new QLabel(QString::number(i++),frame_esp);
            QTextEdit* text_tmp=new QTextEdit(QString::fromStdString(*inizio),frame_esp);

            text_tmp->setReadOnly(true);
            text_tmp->installEventFilter(this);

            lb_tmp->setGeometry(x,y,z,w);
            text_tmp->setGeometry(z+x+20,y,160,70);
            b_tmp->setGeometry(z+x+200,y,65,25);
            y=y+w+75;
            connect(b_tmp,&QAbstractButton::clicked,this,&UserWindow::esp_remove);
            label_esp->append(lb_tmp);
            button_esp->append(b_tmp);
            text_esp->append(text_tmp);

            if(frame_esp->height()<text_tmp->y()+text_tmp->height()){
                frame_esp->setGeometry(frame_esp->x(),frame_esp->y(),frame_esp->width(),frame_esp->height()+100);
            }



        }
}

void UserWindow::esp_insClicked(){

    add_esp->setVisible(true);
    ok_esp_ins->setVisible(true);
    esp_ins->setVisible(false);
    esp_mod->setVisible(false);
    add_esp->setText("Inserire descrizione di un'esperienza lavorativa");

}

void UserWindow::esp_add(){
    if(add_esp->toPlainText() == "\0" || add_esp->toPlainText() == "Inserire descrizione di un'esperienza lavorativa"){
        QMessageBox::warning(this,"Errore","Descrizione non valida");

    }
    else{

        QLabel* lb_tmp=new QLabel("1",frame_esp);
        QTextEdit* text_tmp=new QTextEdit(add_esp->toPlainText(),frame_esp);
        text_tmp->installEventFilter(this);
        QPushButton* b_tmp=new QPushButton("Rimuovi",frame_esp);
        connect(b_tmp,&QAbstractButton::clicked,this,&UserWindow::esp_remove);

        if(!label_esp->isEmpty()){

            lb_tmp->setText(QString::number(label_esp->count()+1));

            QLabel* last=label_esp->last();
            QTextEdit* last_text=text_esp->last();
            QPushButton* last_button=button_esp->last();

            lb_tmp->setGeometry(last->x(),last->y()+last_text->height()+20,last->width(),last->height());
            text_tmp->setGeometry(last_text->x(),lb_tmp->y(),last_text->width(),last_text->height());
            b_tmp->setGeometry(last_button->x(),lb_tmp->y(),last_button->width(),last_button->height());

        }
        else{
            lb_tmp->setGeometry(5,3,10,20);
            text_tmp->setGeometry(35,3,160,70);
            b_tmp->setGeometry(215,3,65,25);

        }

        lb_tmp->show();
        text_tmp->show();
        b_tmp->show();

        label_esp->append(lb_tmp);
        text_esp->append(text_tmp);
        button_esp->append(b_tmp);

        if(frame_esp->height()<text_tmp->y()+text_tmp->height()){
            frame_esp->setGeometry(frame_esp->x(),frame_esp->y(),frame_esp->width(),frame_esp->height()+100);
        }

        control->addEsperienza(add_esp->toPlainText().toStdString());
        control->save();


    }

    add_esp->setVisible(false);
    ok_esp_ins->setVisible(false);
    esp_ins->setVisible(true);
    esp_mod->setVisible(true);


}

void UserWindow::esp_remove(){
    int pos=-1; //indice del tasto cliccato (nessun click = -1)
    QObject* button_sender=sender();

    for(int i=0;i<button_esp->size() && (pos == -1);i++){
        if(button_esp->operator [](i) == button_sender){
            pos=i;
        }
    }

    QString desc=(text_esp->operator [](pos))->toPlainText();

    if(button_esp->size()>1){
        for(int j=pos;j<text_esp->size()-1;j++){
            (text_esp->operator [](j))->setText((text_esp->operator [](j+1))->toPlainText());
        }

    }

    QLabel* x=label_esp->last();
    QTextEdit* y=text_esp->last();
    QPushButton* z=button_esp->last();

    //delego il controller per cancellare da memoria l'esp
    control->removeEsperienza(desc.toStdString());
    control->save();

    label_esp->erase(label_esp->begin()+label_esp->size()-1);
    text_esp->erase(text_esp->begin()+text_esp->size()-1);
    button_esp->erase(button_esp->begin()+button_esp->size()-1);

    delete x;
    delete y;
    delete z;

}

void UserWindow::studi_insClicked(){
    bool ok;
    QString l=QInputDialog::getText(this,"Studi","Inserire titolo di studio",QLineEdit::Normal,"\0",&ok);

    if(ok && !l.isEmpty()){
        control->insertStudi(l.toStdString());

        QLabel* lb=new QLabel(l,frame_studi);
        QPushButton* pb= new QPushButton("Rimuovi",frame_studi);
        connect(pb,&QAbstractButton::clicked,this,&UserWindow::studi_removeClicked);
        lb->show();
        pb->show();



        if(label_studi->size()>0){
            QLabel* tmp1=label_studi->operator [](label_studi->size()-1);
           lb->setGeometry(tmp1->x(),tmp1->y()+5+tmp1->height(),250,20);
           pb->setGeometry(tmp1->x()+200+50,lb->y()+2,70,20);
        }
        else {

            lb->setGeometry(5,3,250,20); //quando il Frame delle lingue è vuoto la prima lingua inserita ha questa posizione di default
            pb->setGeometry(255,5,70,20);
        }
        label_studi->append(lb);
        button_studi->append(pb);

        if(frame_studi->height()<lb->y()+lb->height()){
            frame_studi->setGeometry(frame_studi->x(),frame_studi->y(),frame_studi->width(),frame_studi->height()+100);
        }

        control->save();
    }


}

void UserWindow::studi_removeClicked(){

    int pos=-1; //indice del tasto cliccato (nessun click = -1)
    QObject* button_sender=sender();

    for(int i=0;i<button_studi->size() && (pos == -1) ;i++){
        if(button_studi->operator [](i) == button_sender){
            pos=i;
        }
    }

    QString language=(label_studi->operator [](pos))->text();
    //chiamare il controller e salvare
    control->removeStudi(language.toStdString());
    control->save();

    for(int i=pos;i<label_studi->size()-1;i++){
        (label_studi->operator [](i))->setText((label_studi->operator [](i+1))->text());
    }

    button_sender=button_studi->last();
    button_studi->erase(button_studi->begin()+button_studi->size()-1);
    delete button_sender;

    QLabel* label=label_studi->last();
    label_studi->erase(label_studi->begin()+label_studi->size()-1);
    delete label;

}

void UserWindow::l_removeClicked(){

    int pos=-1; //indice del tasto cliccato (nessun click = -1)
    QObject* button_sender=sender();

    for(int i=0;i<button_language->size() && (pos == -1);i++){
        if(button_language->operator [](i) == button_sender){
            pos=i;
        }
    }

    QString language=(label_language->operator [](pos))->text();
    //chiamare il controller e salvare
    control->removeLanguage(language.toStdString());
    control->save();

    for(int i=pos;i<label_language->size()-1;i++){
        (label_language->operator [](i))->setText((label_language->operator [](i+1))->text());
    }

    button_sender=button_language->last();
    button_language->erase(button_language->begin()+button_language->size()-1);
    delete button_sender;

    QLabel* label=label_language->last();
    label_language->erase(label_language->begin()+label_language->size()-1);
    delete label;



}

void UserWindow::l_insClicked(){

    bool ok;
    QString l=QInputDialog::getText(this,"Lingue","Inserire una lingua",QLineEdit::Normal,"\0",&ok);

    if(ok && !l.isEmpty()){
        control->insertLanguage(l.toStdString());

        QLabel* lb=new QLabel(l,frame_language);
        QPushButton* pb= new QPushButton("Rimuovi",frame_language);
        connect(pb,&QAbstractButton::clicked,this,&UserWindow::l_removeClicked);
        lb->show();
        pb->show();


        if(label_language->size()>0){
            QLabel* tmp1=label_language->operator [](label_language->size()-1);
           lb->setGeometry(tmp1->x(),tmp1->y()+5+20,115,20);
           pb->setGeometry(tmp1->x()+115+135,lb->y(),70,20);
        }
        else {

            lb->setGeometry(5,3,115,20); //quando il Frame delle lingue è vuoto la prima lingua inserita ha questa posizione di default
            pb->setGeometry(255,5,70,20);
        }
        label_language->append(lb);
        button_language->append(pb);

        if(frame_language->height()<lb->y()+lb->height()){
            frame_language->setGeometry(frame_language->x(),frame_language->y(),frame_language->width(),frame_language->height()+100);
        }

        control->save();
    }

}

void UserWindow::esp_modClicked(){

    if(label_esp->size()>0){
        esp_mod->setVisible(false);
        esp_ins->setVisible(false);


        for(int i=0;i<text_esp->size();i++){
            (text_esp->operator [](i))->setReadOnly(false);
        }
    }
    else{
        QMessageBox::warning(this,"Error","Prima devi inserire una descrizione");
    }
}


bool UserWindow::eventFilter(QObject* obj,QEvent* event){

    //GLI EVENTI IN GENERE DAL SISTEMA E SONO DIRETTI A OGGETTI
    //SPECIFICI, MENTRE UN SEGNALE VIENE DA UN OGGETTO E VIENE INDIRIZZATO
    //A QUELLI INTERESSATI, MA LUI NON SA CHI SONO
    if(event->type()== QEvent::FocusOut && (dynamic_cast<QTextEdit*>(obj))->isReadOnly() != true){
        int i=0;
        bool trovato=false;
        while(i< text_esp->size() && !trovato){
            if(text_esp->operator [](i) == obj){
                trovato=true;
            }
            else {i++;}

        }

        QString text=(dynamic_cast<QTextEdit*>(obj))->toPlainText();
        if(text != "\0"){

            control->replaceEsperienza(i,text.toStdString());
            control->save();

            for(int j=0;j<text_esp->size();j++){
                (text_esp->operator [](j))->setReadOnly(true);
            }
            esp_mod->setVisible(true);
            esp_ins->setVisible(true);

            return true;
        }
        else{
            QMessageBox::warning(this,"Errore","Non puoi lasciare una descrizione vuota");

            for(int j=0;j<text_esp->size();j++){
                if((text_esp->operator [](j)) != obj){
                    (text_esp->operator [](j))->setReadOnly(true);
                }
            }

            return false;
        }



    }
    else{ return false; }

}


void UserWindow::setViewContatti(){
    ettichetta5=new QLabel("Contatti",frame_window);
    ettichetta5->setGeometry(0,715,750,30);
    ettichetta5->setStyleSheet("font-size:25px;border-top:1px;border-color:black;border-style:solid;");

    frame_contatti=new QFrame(frame_window);
    frame_contatti->setGeometry(5,520,360,120);

    scroll_contatti=new QScrollArea(frame_window);
    scroll_contatti->setGeometry(5,755,380,120);
    scroll_contatti->setWidget(frame_contatti);
    scroll_contatti->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    label_contatti=new QList<QLabel*>();
    button_contatti=new QList<QPushButton*>();

    list<string> lista;
    control->readContatti(lista);
    lista=chainContatti(lista);
    setStudiLingueContatti(lista,"contatti");

    lista.erase(lista.begin(),lista.end());
    control->readNickContatti(lista);
    nick_contatti=new QStringList();
    setNickContatti(lista); //aggiungo i nickname al QStringList nick_contatti;

}

void UserWindow::setNickContatti(const list<string>& lista){

    for(list<string>::const_iterator inizio=lista.begin();inizio!=lista.end();inizio++){
        nick_contatti->push_back(QString::fromStdString(*inizio));
    }
}

list<string> UserWindow::chainContatti(const list<string>& lista)const{
    list<string>tmp;

    for(list<string>::const_iterator inizio=lista.begin();inizio!=lista.end();inizio++){
        tmp.push_back(*(inizio)+" "+(*(inizio++)));

    }
    return tmp;
}

void UserWindow::contatti_add(){

    QObject* button_sender=sender();
    int pos= -1;

    for(int i=0;i<button_search->size() && (pos == -1);i++){
        if(button_sender == button_search->operator [](i)){
            pos=i;
        }
    }

    if(!nick_contatti->contains(nick_search_contatti->operator [](pos*2))){
        control->addContatto((nick_search_contatti->operator [](pos*2)).toStdString());

        QLabel* lb=new QLabel(nick_search_contatti->operator [](pos*2+1),frame_contatti);
        QPushButton* pb= new QPushButton("Rimuovi",frame_contatti);
        nick_contatti->push_back(nick_search_contatti->operator [](pos*2));
        connect(pb,&QAbstractButton::clicked,this,&UserWindow::contatti_remove);

        lb->show();
        pb->show();

        if(label_contatti->size()>0){
            QLabel* tmp1=label_contatti->operator [](label_contatti->size()-1);
            lb->setGeometry(tmp1->x(),tmp1->y()+5+20,120,20);
            pb->setGeometry(tmp1->x()+120+130,lb->y(),70,20);
         }
         else {

             lb->setGeometry(5,3,120,20);
             pb->setGeometry(255,5,70,20);
         }
         label_contatti->append(lb);
         button_contatti->append(pb);

         if(frame_contatti->height()<lb->y()+lb->height()){
             frame_contatti->setGeometry(frame_contatti->x(),frame_contatti->y(),frame_contatti->width(),frame_contatti->height()+100);
         }

         control->save();
    }
    else{ QMessageBox::warning(this,"Errore","Utente già presente nei contatti");}




}

void UserWindow::contatti_remove(){

    int pos=-1; //indice del tasto cliccato (nessun click = -1)
    QObject* button_sender=sender();

    for(int i=0;i<button_contatti->size() && (pos == -1);i++){
        if(button_contatti->operator [](i) == button_sender){
            pos=i;
        }
    }

    string nick=(nick_contatti->operator [](pos)).toStdString();

    //chiamare il controller e salvare
    control->removeContatto(nick);
    control->save();

   //devo fare l'erase sulla lista nick_contatti
    nick_contatti->erase(nick_contatti->begin()+pos);

    for(int i=pos;i<label_contatti->size()-1;i++){
        (label_contatti->operator [](i))->setText((label_contatti->operator [](i+1))->text());
    }

    button_sender=button_contatti->last();
    button_contatti->erase(button_contatti->begin()+button_contatti->size()-1);
    delete button_sender;

    QLabel* label=label_contatti->last();
    label_contatti->erase(label_contatti->begin()+label_contatti->size()-1);
    delete label;

}

void UserWindow::setViewSearch(){

    ettichetta6=new QLabel("Search",frame_window);
    ettichetta6->setGeometry(0,900,750,30);
    ettichetta6->setStyleSheet("font-size:25px;border-top:1px;border-color:black;border-style:solid;");

    ok_search=new QPushButton("Avvia",frame_window);
    ok_search->setGeometry(110,905,75,25);
    connect(ok_search,&QAbstractButton::clicked,this,&UserWindow::ok_searchClicked);

    frame_search=new QFrame(frame_window);
    frame_search->setGeometry(0,0,355,320);

    scroll_search=new QScrollArea(frame_window);
    scroll_search->setGeometry(5,950,365,320);
    scroll_search->setWidget(frame_search);
    scroll_search->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    nick_search_contatti= new QStringList();
    text_search=new QList<QTextEdit*>();
    button_search=new QList<QPushButton*>();
}

void UserWindow::ok_searchClicked(){

    if(nick_search_contatti->size() > 0){

        nick_search_contatti->erase(nick_search_contatti->begin(),nick_search_contatti->end());

        while(text_search->size()>0){
            QTextEdit* x=text_search->first();
            text_search->removeFirst();
            delete x;
        }

        while(button_search->size() > 0){
            QPushButton* x=button_search->first();
            button_search->removeFirst();
            delete x;
        }

    }

    bool ok1,ok2;

    QString nome=QInputDialog::getText(this,"Dati utente","Inserire nome utente",QLineEdit::Normal,"\0",&ok1);
    QString cognome=QInputDialog::getText(this,"Dati utente","Inserire cognome utente",QLineEdit::Normal,"\0",&ok2);

    if(ok1 && ok2 && !nome.isEmpty() && !cognome.isEmpty()){

       map<string,vector<list<string> > > utenti=control->searchUser(nome.toStdString(),cognome.toStdString());

       if(utenti.size()>0){
         int x=5,y=3,z=250,w=150;

         for(map<string,vector<list<string> > >::const_iterator inizio=utenti.begin();inizio!=utenti.end();inizio++){
            nick_search_contatti->push_back(QString::fromStdString(inizio->first));

            QTextEdit* text_tmp=new QTextEdit("",frame_search);
            text_tmp->setGeometry(x,y,z,w);
            text_tmp->show();

            QPushButton* b_tmp=new QPushButton("Aggiungi",frame_search);
            b_tmp->setGeometry(z+x+10,y,65,25);
            b_tmp->show();
            connect(b_tmp,&QAbstractButton::clicked,this,&UserWindow::contatti_add);

            //inserire descrizione
            setTextSearch(inizio->second,text_tmp);

            text_search->push_back(text_tmp);
            button_search->push_back(b_tmp);
            y=y+w+75;

            if(frame_search->height()<text_tmp->y()+text_tmp->height()){
               frame_search->setGeometry(frame_search->x(),frame_search->y(),frame_search->width(),frame_search->height()+300);
            }


          }

        }
       else{ QMessageBox::information(this,"Information search","Utente non presente nel DataBase"); }
     }

}

void UserWindow::chainString(string& testo,list<string>::const_iterator inizio,list<string>::const_iterator fine,string nome_lista){

   if(nome_lista!="Contatti"){
        for(;inizio!=fine;inizio++){
            testo=testo+ *inizio +"\n\n";
        }
    }
    else{
       for(;inizio!=fine;inizio=inizio++){
            testo=testo+"Cognome: "+*(inizio++)+"\n";
            testo=testo+"Nome: "+ *(inizio++)+"\n\n";
       }
   }
}


void UserWindow::setTextSearch(const vector<list<string> >& info,QTextEdit* view){

    string testo="";

    if(info.size()>0){


        list<string>::const_iterator j=(info[0]).begin();

        testo=testo+"Tipo account: "+ *(j++)  +"\n";
        testo=testo+"Nick: "+ *(j++) +"\n";
        testo=testo+"Nome: "+ *(j)+"\n";

        //nick_search_contatti->push_back(QString::fromStdString(*++j+ " "+*j));
        nick_search_contatti->push_back(QString::fromStdString(*--j + " "+ *++j));

        testo=testo+"Cognome: "+ *(++j)+ "\n";
        testo=testo+"Mail: "+ *(++j)+ "\n";
        testo=testo+"Data: "+ *(++j)+ "\n\n";
        if(info.size() >1 && info.size()<=5){

            testo=testo+"Esperienze: \n";
            chainString(testo,(info[1]).begin(),(info[1]).end(),"Esperienze");
            testo=testo+"Lingue: \n";
            chainString(testo,(info[2]).begin(),(info[2]).end(),"Lingue");
            testo=testo+"Studi: \n";
            chainString(testo,(info[3]).begin(),(info[3]).end(),"Studi");

        }
        if(info.size() == 5){
            testo=testo+"Contatti: \n";
            chainString(testo,(info[4]).begin(),(info[4]).end(),"Contatti");
        }

    }

    view->setText(QString::fromStdString(testo));

}

void UserWindow::restoreUserWindow(){
     this->parentWidget()->show();
     delete this;
}
