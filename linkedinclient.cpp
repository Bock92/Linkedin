#include "linkedinclient.h"
#include<iostream>
using std::cout;
using std::endl;

LinkedinClient::LinkedinClient(string u):pdb(new DB()){
    pdb->load();
    user=pdb->find(u);

    if(user==0){
        delete pdb;
        throw access_denied;
    }
}

LinkedinClient::~LinkedinClient(){
    if(pdb) delete pdb;
    if(user) delete user;
}

void LinkedinClient::changeProfilo(string n,string c,string d,string m){
    Profilo* pf=const_cast<Profilo*>(user->getProfilo());

    bool modifica=false;

    if( n !="\n"){
        modifica=true;
        pf->setNome(n);
    }

    if(c !="\n"){
        modifica=true;
        pf->setCognome(c);
    }

    if(d !="\n"){
        modifica=true;
        pf->setData(d);
    }

    if(m !="\n"){
        modifica=true;
        pf->setMail(m);
    }

    if(modifica){
        throw change_profilo_ok;
    }

}


void LinkedinClient::insertContatto(string nick){

    Utente* j=pdb->find(nick);

    if(j!=0){
       (user->getRete())->add_Contatto(j,nick);
    }

}

void LinkedinClient::removeContatto(string us){
    (user->getRete())->remove_Contatto(us);
}

map<string,vector<list<string> > > LinkedinClient::search(string nome,string cognome)const{
    return user->userSearch(*pdb,nome,cognome);
}

void LinkedinClient::save()const{
    pdb->save();
}

Utente* LinkedinClient::getUser()const{
    return user;
}

void LinkedinClient::insertLanguage(string l){
    user->getProfilo()->getInfo()->addLingue(l);
}

void LinkedinClient::removeLanguage(string lingua){
    user->getProfilo()->getInfo()->eraseLingue(lingua);
}

void LinkedinClient::insertStudy(string titolo_studio){
    user->getProfilo()->getInfo()->addStudi(titolo_studio);
}

void LinkedinClient::removeStudy(string titolo_studio){
    user->getProfilo()->getInfo()->eraseStudi(titolo_studio);
}

void LinkedinClient::changeEsp(int pos,string text){
    user->getProfilo()->getInfo()->replaceEsp(pos,text);
}

void LinkedinClient::insertEsp(string desc){
    user->getProfilo()->getInfo()->addEsp(desc);
}

void LinkedinClient::removeEsp(string desc){
    user->getProfilo()->getInfo()->eraseEsp(desc);
}
