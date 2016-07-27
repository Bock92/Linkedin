#include "linqedinclient.h"
#include<iostream>
using std::cout;
using std::endl;

LinQedInClient::LinQedInClient(string u):pdb(new DB()){
    pdb->load();
    user=pdb->find(u);

    if(user==0){
        delete pdb;
        throw access_denied;
    }
}

LinQedInClient::~LinQedInClient(){
    if(pdb) delete pdb;
    if(user) delete user;
}

void LinQedInClient::changeProfilo(string n,string c,string d,string m){
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


void LinQedInClient::insertContatto(string nick){

    Utente* j=pdb->find(nick);

    if(j!=0){
       (user->getRete())->add_Contatto(j,nick);
    }
    else{cout<<"L'utente che vuoi aggiungere agli amici non è presente nel database"<<endl;}


}

void LinQedInClient::removeContatto(string us){
    (user->getRete())->remove_Contatto(us);
}

map<string,vector<list<string> > > LinQedInClient::search(string nome,string cognome)const{
    return user->userSearch(*pdb,nome,cognome);
}

void LinQedInClient::save()const{
    pdb->save();
}

Utente* LinQedInClient::getUser()const{
    return user;
}

void LinQedInClient::insertLanguage(string l){
    user->getProfilo()->getInfo()->addLingue(l);
}

void LinQedInClient::removeLanguage(string lingua){
    user->getProfilo()->getInfo()->eraseLingue(lingua);
}

void LinQedInClient::insertStudy(string titolo_studio){
    user->getProfilo()->getInfo()->addStudi(titolo_studio);
}

void LinQedInClient::removeStudy(string titolo_studio){
    user->getProfilo()->getInfo()->eraseStudi(titolo_studio);
}

void LinQedInClient::changeEsp(int pos,string text){
    user->getProfilo()->getInfo()->replaceEsp(pos,text);
}

void LinQedInClient::insertEsp(string desc){
    user->getProfilo()->getInfo()->addEsp(desc);
}

void LinQedInClient::removeEsp(string desc){
    user->getProfilo()->getInfo()->eraseEsp(desc);
}
