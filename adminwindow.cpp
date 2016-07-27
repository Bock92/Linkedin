#include "adminwindow.h"
#include<QAbstractButton>
#include<QMessageBox>
#include<QList>
#include<QStringList>
#include<QRegularExpression>
#include<QRegularExpressionMatch>

AdminWindow::AdminWindow(QWidget *parent): QWidget(parent),control(new Controller("admin")),dx(new QFrame(this)),dxRadioButton(new QFrame(this)),pushButton(new QFrame(this)),tree(new QTreeWidget(this)){


    this->setGeometry(100,100,600,400);
    this->setMaximumSize(600,400);

    setQTreeWidget();
    setQFrameDx();

}

AdminWindow::~AdminWindow(){
    if(control){delete control;}
    if(dx){delete dx;}
    if(dxRadioButton){delete dxRadioButton;}
    if(pushButton){delete pushButton;}
    if(tree){delete tree;}
}


void AdminWindow::setQTreeWidget(){
  tree->setGeometry(1,1,165,400);
  QTreeWidgetItem* ut= new QTreeWidgetItem(tree);
  ut->setText(0,"Utente");
  QTreeWidgetItem* add= new QTreeWidgetItem(ut);
  add->setText(0,"Aggiungi");
  QTreeWidgetItem* del= new QTreeWidgetItem(ut);
  del->setText(0,"Cancella");
  ut->setExpanded(true);

  QTreeWidgetItem* search=new QTreeWidgetItem(tree);
  search->setText(0,"Cerca");
  QTreeWidgetItem* nc=new QTreeWidgetItem(search);
  nc->setText(0,"Nome/Cognome");
  QTreeWidgetItem* nick=new QTreeWidgetItem(search);
  nick->setText(0,"Nickname");
  search->setExpanded(true);

  QTreeWidgetItem* acc=new QTreeWidgetItem(tree);
  acc->setText(0,"Account");
  QTreeWidgetItem* up=new QTreeWidgetItem(acc);
  up->setText(0,"Upgrade");
  QTreeWidgetItem* down=new QTreeWidgetItem(acc);
  down->setText(0,"Downgrade");
  acc->setExpanded(true);


  connect(tree,&QTreeWidget::itemClicked,this,&AdminWindow::changeQFrameDx);

}

void AdminWindow::showQFrameDxContent(int x){

    switch(x){
        case 1:
            lb1->setVisible(true);
            lb2->setVisible(false);
            lb3->setVisible(false);
            lb4->setVisible(false);
            text1->setVisible(true);
            text1->setText("");
            text2->setVisible(false);
            text3->setVisible(false);
            op1->setVisible(false);
            op2->setVisible(false);
            op3->setVisible(false);
            view->setVisible(false);
            break;
        case 2:
            lb1->setVisible(true);
            lb2->setVisible(true);
            lb3->setVisible(false);
            lb4->setVisible(false);
            text1->setVisible(true);
            text2->setVisible(true);
            text1->setText("");
            text2->setText("");
            text3->setVisible(false);
            op1->setVisible(false);
            op2->setVisible(false);
            op3->setVisible(false);
            view->setVisible(false);
            break;
        case 3:
            lb1->setVisible(true);
            lb2->setVisible(true);
            lb3->setVisible(true);
            lb4->setVisible(false);
            text1->setVisible(true);
            text2->setVisible(true);
            text3->setVisible(true);
            text1->setText("");
            text2->setText("");
            text3->setText("");
            op1->setVisible(false);
            op2->setVisible(false);
            op3->setVisible(false);
            view->setVisible(false);
            break;
        case 4:
            lb1->setVisible(true);
            lb2->setVisible(true);
            lb3->setVisible(true);
            lb4->setVisible(true);
            text1->setVisible(true);
            text2->setVisible(true);
            text3->setVisible(true);
            text1->setText("");
            text2->setText("");
            text3->setText("");
            op1->setVisible(true);
            op2->setVisible(true);
            op3->setVisible(true);
            op1->setEnabled(true);
            op3->setEnabled(true);
            view->setVisible(false);
            dxRadioButton->setGeometry(355,110,150,100);
            break;
        case 5:
            lb1->setVisible(true);
            lb2->setVisible(true);
            lb3->setVisible(false);
            lb4->setVisible(false);
            text1->setVisible(true);
            text2->setVisible(false);
            text3->setVisible(false);
            op1->setVisible(true);
            op2->setVisible(true);
            op3->setVisible(true);
            op1->setEnabled(true);
            op3->setEnabled(true);
            view->setVisible(false);
            dxRadioButton->setGeometry(355,55,150,100);
            break;
        default:
            lb1->setVisible(false);
            lb2->setVisible(false);
            lb3->setVisible(false);
            lb4->setVisible(false);
            text1->setVisible(false);
            text2->setVisible(false);
            text3->setVisible(false);
            op1->setVisible(false);
            op2->setVisible(false);
            op3->setVisible(false);
            view->setVisible(false);
            break;
    }

}


void AdminWindow::setQFrameDx(){
    dx->setGeometry(155,21,400,380);
    dxRadioButton->setGeometry(355,110,150,100);
    pushButton->setGeometry(375,365,250,35);

    lb1= new QLabel(dx);
    lb2= new QLabel(dx);
    lb3= new QLabel(dx);
    lb4= new QLabel(dx);

    lb1->setGeometry(70,10,90,20);
    lb2->setGeometry(70,35,90,20);
    lb3->setGeometry(70,60,90,20);
    lb4->setGeometry(70,85,90,20);

    text1= new QLineEdit(dx);
    text2= new QLineEdit(dx);
    text3= new QLineEdit(dx);
    text1->setGeometry(200,10,200,20);
    text2->setGeometry(200,35,200,20);
    text3->setGeometry(200,60,200,20);

    view=new QTextEdit(dx);
    view->setGeometry(50,100,350,150);
    view->setReadOnly(true);

    op1= new QRadioButton("Basic",dxRadioButton);
    op2= new QRadioButton("Business",dxRadioButton);
    op3= new QRadioButton("Executive",dxRadioButton);
    op1->setGeometry(0,0,150,20);
    op2->setGeometry(0,20,150,20);
    op3->setGeometry(0,40,150,20);

    exit=new QPushButton("Exit",pushButton);
    exit->setGeometry(0,0,70,30);
    connect(exit,&QAbstractButton::clicked,this,&AdminWindow::restoreAdminWindow);

    save=new QPushButton("Save",pushButton);
    save->setGeometry(75,0,70,30);
    connect(save,&QAbstractButton::clicked,this,&AdminWindow::saveClicked);

    ok=new QPushButton("Ok",pushButton);
    ok->setGeometry(150,0,70,30);
    connect(ok,&QAbstractButton::clicked,this,&AdminWindow::okClicked);

    showQFrameDxContent();
}


void AdminWindow::changeQFrameDx(){
    if(tree->currentItem()->text(0)=="Aggiungi"){
        showQFrameDxContent(4);
        lb1->setText("Nome");
        lb2->setText("Cognome");
        lb3->setText("Nickname");
        lb4->setText("Tipo Account");
    }
    else if(tree->currentItem()->text(0)=="Cancella"){
            showQFrameDxContent(1);
            lb1->setText("Nickname");

    }
    else if(tree->currentItem()->text(0)=="Nome/Cognome"){
            showQFrameDxContent(2);
            lb1->setText("Nome");
            lb2->setText("Cognome");
            view->setText("");
            view->setVisible(true);

    }else if(tree->currentItem()->text(0)=="Nickname"){
            showQFrameDxContent(1);
            lb1->setText("Nickname");
            view->setText("");
            view->setVisible(true);

    }else if(tree->currentItem()->text(0)=="Upgrade"){
            showQFrameDxContent(5);
            lb1->setText("Nick");
            lb2->setText("Tipo Account");
            op1->setDisabled(true);

    }else if(tree->currentItem()->text(0)=="Downgrade"){
            showQFrameDxContent(5);
            lb1->setText("Nick");
            lb2->setText("Tipo Account");
            op3->setDisabled(true);
    }
}

void AdminWindow::chainString(string& testo,list<string>::const_iterator inizio,list<string>::const_iterator fine,string nome_lista){

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


void AdminWindow::setTextView(const map<string,vector<list<string> > >& mappa,QTextEdit* view){

    string testo="";


    for(map<string,vector<list<string> > >::const_iterator inizio=mappa.begin();inizio!=mappa.end();inizio++){

        const vector<list<string> > *p=&(inizio->second);
         list<string>::const_iterator j=(p->operator [](0)).begin();

        testo=testo+"Tipo account: "+ *(j++)  +"\n";
        testo=testo+"Nick: "+ *(j++) +"\n";
        testo=testo+"Nome: "+ *(j++)+"\n";
        testo=testo+"Cognome: "+ *(j++)+ "\n";
        testo=testo+"Mail: "+ *(j++)+ "\n";
        testo=testo+"Data: "+ *(j++)+ "\n\n";

        testo=testo+"Esperienze: \n";
        chainString(testo,(p->operator [](1)).begin(),(p->operator [](1)).end(),"Esperienze");
        testo=testo+"Lingue: \n";
        chainString(testo,(p->operator [](2)).begin(),(p->operator [](2)).end(),"Lingue");
        testo=testo+"Studi: \n";
        chainString(testo,(p->operator [](3)).begin(),(p->operator [](3)).end(),"Studi");
        testo=testo+"Contatti: \n";
        chainString(testo,(p->operator [](4)).begin(),(p->operator [](4)).end(),"Contatti");

    }

    view->setText(QString::fromStdString(testo));


}

void AdminWindow::setTextView(const vector<list<string> >& info,QTextEdit* view){

    string testo="";

    list<string>::const_iterator j=(info[0]).begin();

        testo=testo+"Tipo account: "+ *(j++)  +"\n";
        testo=testo+"Nick: "+ *(j++) +"\n";
        testo=testo+"Nome: "+ *(j++)+"\n";
        testo=testo+"Cognome: "+ *(j++)+ "\n";
        testo=testo+"Mail: "+ *(j++)+ "\n";
        testo=testo+"Data: "+ *(j++)+ "\n\n";

        testo=testo+"Esperienze: \n";
        chainString(testo,(info[1]).begin(),(info[1]).end(),"Esperienze");
        testo=testo+"Lingue: \n";
        chainString(testo,(info[2]).begin(),(info[2]).end(),"Lingue");
        testo=testo+"Studi: \n";
        chainString(testo,(info[3]).begin(),(info[3]).end(),"Studi");
        testo=testo+"Contatti: \n";
        chainString(testo,(info[4]).begin(),(info[4]).end(),"Contatti");


    view->setText(QString::fromStdString(testo));

}

void AdminWindow::okClicked(){

    QRegularExpression esp1= QRegularExpression("^([a-z]+)$");

    if(tree->currentItem()->text(0)=="Aggiungi"){

        if(text1->text()!="\0" && text2->text()!="\0" && text3->text()!="\0" && (op1->isChecked() || op2->isChecked() || op3->isChecked())){
            if(!(esp1.match(text1->text())).hasMatch()){
                //creo QMessageBox temporaneo
                QMessageBox::warning(this,"Errore","Nome non valido, inserire una sequenza di caratteri minuscoli");

            }
            else if(!(esp1.match(text2->text())).hasMatch()){
                  //creo QMessageBox temporaneo
                QMessageBox::warning(this,"Errore","Cognome non valido, inserire una sequenza di caratteri minuscoli");
            }
            else if(!(esp1.match(text3->text())).hasMatch()){
                //creo QMessageBox temporaneo
                QMessageBox::warning(this,"Errore","NickName non valido, inserire una sequenza di caratteri minuscoli");
            }
            else{


              try{
                  if(op1->isChecked()){
                     control->addUsr(text1->text().toStdString(),text2->text().toStdString(),text3->text().toStdString(),op1->text().toStdString());
                  }
                  else if(op2->isChecked()){
                     control->addUsr(text1->text().toStdString(),text2->text().toStdString(),text3->text().toStdString(),op2->text().toStdString());
                  }
                  else if(op3->isChecked()){
                    control->addUsr(text1->text().toStdString(),text2->text().toStdString(),text3->text().toStdString(),op3->text().toStdString());
                  }

                }
            catch(result e){
                 if(e == insert_denied){
                     QMessageBox::warning(this,"Errore","Utente già presente con quel nickname");


                 }
                 else if(e == insert_ok){
                        QMessageBox::information(this,"","Utente inserito");
                 }
             }
           }

        }
        else{
            QMessageBox::warning(this,"Errore","Tutti i campi sono OBBLIGATORI");
        }


    }
    else if(tree->currentItem()->text(0)=="Cancella"){
        if(text1->text()!="\0" && (esp1.match(text1->text())).hasMatch()){
            try{
                control->deleteUsr(text1->text().toStdString());
            }
            catch(result e){
                if(e == remove_ok){
                    QMessageBox* x=new QMessageBox(this);
                    x->setText("Utente rimosso dal DataBase");
                    x->show();
                }
                else if(e == remove_denied){
                    QMessageBox* x=new QMessageBox(this);
                    x->setText("Utente non presente");
                    x->show();
                }

            }

        }
        else{QMessageBox::warning(this,"Errore","Nickname non corretto");}
    }
    else if(tree->currentItem()->text(0)=="Nome/Cognome"){
            if(text1->text()!="\0" && text2->text()!="\0"){

                if((esp1.match(text1->text())).hasMatch() && (esp1.match(text2->text())).hasMatch()){

                    map<string,vector<list<string> > > mappa_info=control->search(text1->text().toStdString(),text2->text().toStdString());
                    if(mappa_info.size()!=0){
                        setTextView(mappa_info,view);
                    }
                    else{QMessageBox::information(this,"Information","Utente non presente");}
                }
                else{QMessageBox::warning(this,"Errore","Nome o Cognome non valido");}

            }
            else{
                QMessageBox::warning(this,"Errore","Tutti i campi sono OBBLIGATORI");
            }


    }
    else if(tree->currentItem()->text(0)=="Nickname"){
        if(text1->text()!="\0" && (esp1.match(text1->text())).hasMatch()){
            vector<list<string> > lista=control->search(text1->text().toStdString());
            if(lista.size()!=0){
                setTextView(lista,view);
            }
            else{QMessageBox::information(this,"Errore","Utente non presente nel DataBase");}

        }
        else{
            QMessageBox::warning(this,"Errore","Nickname non valido");

        }

    }
    else if(tree->currentItem()->text(0)=="Upgrade"){

        if((op2->isChecked() || op3->isChecked() )&& text1->text()!="\0"){
            if((esp1.match(text1->text())).hasMatch()){

                try{
                    if(op2->isChecked()){
                        control->upgradeAccount(text1->text().toStdString(),2);
                    }
                    else if(op3->isChecked()){
                        control->upgradeAccount(text1->text().toStdString(),3);
                    }
                }
                catch(result e){
                    if(e == upgrade_ok){
                        QMessageBox::information(this,"Information","Upgrade effettuato");
                    }
                    else if(e == upgrade_denied){
                        QMessageBox::warning(this,"Errore","Utente non presente nel DataBase");

                    }
                    else if(e == upgrade_level){
                        QMessageBox::information(this,"Information","Utente ha grado uguale a quello selezionato");
                    }
                    else if(e == upgrade_max){
                        QMessageBox::information(this,"Information","L'utente ha già  grado massimo");

                    }
                }
            }
            else{QMessageBox::warning(this,"Errore","Nickname non valido");}
        }
        else{
            QMessageBox::warning(this,"Errore","Tutti i campi sono OBBLIGATORI");
        }
    }
    else if(tree->currentItem()->text(0)=="Downgrade"){
            if((op1->isChecked() || op2->isChecked()) && text1->text()!="\0"){
                try{
                    if(op1->isChecked()){
                        control->downgradeAccount(text1->text().toStdString(),1);
                    }
                    else if(op2->isChecked()){
                        control->downgradeAccount(text1->text().toStdString(),2);
                    }
                }
                catch(result e){
                    if(e == downgrade_ok){
                        QMessageBox::information(this,"Information","Downgrade effettuato");
                    }
                    else if(e == downgrade_denied){
                        QMessageBox::warning(this,"Errore","Utente non presente nel database");
                    }
                    else if(e == downgrade_level){
                        QMessageBox::information(this,"Information","L'utente ha grado uguale a quello selezionato");
                    }
                    else if(e == downgrade_min){
                        QMessageBox::information(this,"Information","L'utente ha già grado minimo");
                    }
                }
            }
            else {
                QMessageBox::warning(this,"Errore","Tutti i campi sono OBBLIGATORI");
            }
    }

}

void AdminWindow::saveClicked(){
    control->save();
    QMessageBox::information(this,"Information","Salvato con successo");

}

void AdminWindow::restoreAdminWindow(){
     this->parentWidget()->show();
     delete this;
}
