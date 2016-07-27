#include "controller.h"
#include "utente.h"
#include "utentebasic.h"
#include "utentebusiness.h"
#include "utenteexecutive.h"
#include<typeinfo>
#include <iostream>

Controller::Controller(string log_user,string nick){
    if(log_user=="admin"){
        admin=new LinkedinAdmin();
        user=0;
    }
    else if(log_user=="user"){

       try{
            user=new LinkedinClient(nick);
            admin=0;
        }
        catch(result){ throw;   }
    }
}

Controller::~Controller(){
    if (admin) delete admin;
    if (user) delete user;
}


void Controller::addUsr(string nome,string cognome,string nick,string tipo){

    try{
        admin->addUser(nome,cognome,nick,tipo);
    }
    catch(result ){ throw;} //rilancio l'eccezione al chiamante

}

void Controller::save(){
    if(admin){
        admin->save();
    }
    else if(user){
        user->save();
    }
}



void Controller::deleteUsr(string nick){
    try{
        admin->removeUser(nick);
    }
    catch(result ){ throw;}
}

void Controller::upgradeAccount(string nick,int up){
    try{
        admin->upgrade(nick,up);
    }
    catch(result){throw;}
}

void Controller::downgradeAccount(string nick,int down){
    try{
        admin->downgrade(nick,down);
    }
    catch(result){throw;}
}


vector<list<string> > Controller::search(string nick)const{

    return admin->search(nick);
}

map<string,vector<list<string> > > Controller::search(string n,string c)const{

    return admin->search(n,c);
}

void Controller::changeProfilo(string n,string c,string d,string m){
    try{
        user->changeProfilo(n,c,d,m);
    }

    catch(result ){throw;}
}

void Controller::replaceEsperienza(int pos,string text){
    user->changeEsp(pos,text);
}

void Controller::addEsperienza(string desc){
    user->insertEsp(desc);
}

void Controller::removeEsperienza(string desc){
    user->removeEsp(desc);
}

void Controller::insertLanguage(string l){
    user->insertLanguage(l);
}

void Controller::removeLanguage(string lingua){

    user->removeLanguage(lingua);
}

void Controller::insertStudi(string titolo_studio){
    user->insertStudy(titolo_studio);
}

void Controller::removeStudi(string titolo_studio){
    user->removeStudy(titolo_studio);
}

void Controller::readProfiloUtente(list<string>& tmp)const{

     user->getUser()->readProfilo(tmp);

}

void Controller::readListInfo(list<string>&tmp,string name_list)const{

    user->getUser()->readInfoList(tmp,name_list);
}

void Controller::readContatti(list<string>& tmp)const{

    user->getUser()->readReteContatti(tmp);
}

void Controller::addContatto(string nick){
     user->insertContatto(nick);
}

void Controller::removeContatto(string nick){
    user->removeContatto(nick);
}

void Controller::readNickContatti(list<string>& lista)const{
    user->getUser()->readNickContatti(lista);
}

map<string,vector<list<string> > > Controller::searchUser(string n,string c) const{
    return user->search(n,c);
}
