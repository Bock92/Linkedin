#include "linqedinadmin.h"
#include"utente.h"
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"
#include"rete.h"
#include<typeinfo>
#include<iostream>
#include<map>
using std::map;
using std::cout;
using std::endl;


linqedinadmin::linqedinadmin():database(new DB()){
    database->load();
}

linqedinadmin::~linqedinadmin(){
    if(database) delete database;
}

void linqedinadmin::addUser(string n, string c, string u, string t){

    try{
        database->addUtente(n,c,u,t);
    }

    catch(result ){ throw;} //rilancio l'eccezione al chiamante


}

DB* linqedinadmin::getDatabase()const{
    return database;
}

void linqedinadmin::removeUser(string nick){

    try{
        database->removeUtente(nick);
    }
    catch(result ){throw;}
}

void linqedinadmin::save()const{
    database->save();
}

map<string,vector<list<string> > > linqedinadmin::search(string n, string c) const{


    vector<Utente*> ut=database->find(n,c);
    map<string,vector<list<string> > > info_map;

    for(unsigned int i=0;i<ut.size();i++){

        map<string,vector<list<string> > >::value_type v((ut[i])->getUsername(),(ut[i])->showUtente());
        info_map.insert(v);

    }

    return info_map;
}

vector<list<string> > linqedinadmin::search(string nick) const{

    Utente* x=database->find(nick);
    vector<list<string> > info;
    list<string> tmp;

    if(x != 0){
        info=x->showUtente();
    }

    return info;


}

void linqedinadmin::upgrade(string nick,int n){
//ai vari tipi di utente associo a Basic=1, Business=2, Executive=3
    Utente* x=database->find(nick);
    bool change=false;

    if(!x){
        throw upgrade_denied;
    }
    else{
        //controllo il tipo del'utente x

        if(typeid(*x)==typeid(UtenteBasic) && (n==2 || n==3)){
            //posso fare l'upgrade
            change=true;

            if(n==2){
                //sovrascrivo x con il nuovo tipo di utente
                x=new UtenteBusiness(x->getUsername(),*(x->getProfilo()),*(x->getRete()));
                map<string,Utente*> *z=const_cast<map<string,Utente*>*>(database->getDB());

                //rimuovo l'utente nick dal DB
                z->erase(nick); //uso il metodo erase del template <map>
                map<string,Utente*>::value_type v(nick,x);
                z->insert(v);

            }
            else{ //n==3
                  x=new UtenteExecutive(x->getUsername(),*(x->getProfilo()),*(x->getRete()));
                  map<string,Utente*> *z=const_cast<map<string,Utente*>*>(database->getDB());

                  z->erase(nick);
                  map<string,Utente*>::value_type v(nick,x);
                  z->insert(v);
            }
        }
        else if(typeid(*x)==typeid(UtenteBusiness) && n==3){
            //posso fare l'upgrade
            change=true;

               x=new UtenteExecutive(x->getUsername(),*(x->getProfilo()),*(x->getRete()));
               map<string,Utente*> *z=const_cast<map<string,Utente*>*>(database->getDB());

               z->erase(nick);
               map<string,Utente*>::value_type v(nick,x);
               z->insert(v);
        }
        else if(typeid(*x)==typeid(UtenteExecutive)){
                throw upgrade_max;
        }
        else{ throw upgrade_level;}

        //devo aggiornare l'info (Utente* ) di tutti gli oggetti Rete degli utenti che hanno come amico l'utente "nick"
        if(change){
                map<string,Utente*> *j=const_cast<map<string,Utente*>*>(database->getDB());

                for(map<string,Utente*>::iterator inizio=j->begin();inizio!=j->end();inizio++){
                    if(inizio->first!=nick){ //escludo l'utente nick, altrimenti ho che A ha come amico se stesso
                        map<string,Utente*> *r=const_cast<map<string,Utente*>*>(inizio->second->getRete()->getRete());
                        //controllo se l'utente nick è presente nella rete dell'utente. Se si cambio il puntatore altrimenti non faccio niente
                        if(r->find(nick)!=r->end()){
                            //cambio il puntatore
                            (r->operator[](nick))=x;

                        }


                    }
                }
        }
        throw upgrade_ok;

    }

}

void linqedinadmin::downgrade(string nick,int n){

    //ai vari tipi di utente associo a Basic=1, Business=2, Executive=3
        Utente* x=database->find(nick);
        bool change=false;

        if(!x){
            throw downgrade_denied;
        }
        else{
            //controllo il tipo del'utente x

            if(typeid(*x)==typeid(UtenteExecutive) && (n==2 || n==1)){
                //posso fare l'upgrade
                change=true;

                if(n==2){
                    //sovrascrivo x con il nuovo tipo di utente
                    x=new UtenteBusiness(x->getUsername(),*(x->getProfilo()),*(x->getRete()));
                    map<string,Utente*> *z=const_cast<map<string,Utente*>*>(database->getDB());

                    //rimuovo l'utente nick dal DB
                    z->erase(nick); //uso il metodo erase del template <map>
                    map<string,Utente*>::value_type v(nick,x);
                    z->insert(v);

                }
                else{ //n==1
                      x=new UtenteBasic(x->getUsername(),*(x->getProfilo()),*(x->getRete()));
                      map<string,Utente*> *z=const_cast<map<string,Utente*>*>(database->getDB());

                      z->erase(nick);
                      map<string,Utente*>::value_type v(nick,x);
                      z->insert(v);
                }
            }
            else if(typeid(*x)==typeid(UtenteBusiness) && n==1){
                //posso fare l'upgrade
                change=true;

                   x=new UtenteBasic(x->getUsername(),*(x->getProfilo()),*(x->getRete()));
                   map<string,Utente*> *z=const_cast<map<string,Utente*>*>(database->getDB());

                   z->erase(nick);
                   map<string,Utente*>::value_type v(nick,x);
                   z->insert(v);
            }
            else if(typeid(*x)==typeid(UtenteBasic)){
                    throw downgrade_min;
            }
            else{ throw downgrade_level;}

            //devo aggiornare l'info (Utente* ) di tutti gli oggetti Rete degli utenti che hanno come amico l'utente "nick"
            if(change){
                    map<string,Utente*> *j=const_cast<map<string,Utente*>*>(database->getDB());

                    for(map<string,Utente*>::iterator inizio=j->begin();inizio!=j->end();inizio++){
                        if(inizio->first!=nick){ //escludo l'utente nick, altrimenti ho che A ha come amico se stesso
                            map<string,Utente*> *r=const_cast<map<string,Utente*>*>(inizio->second->getRete()->getRete());
                            //controllo se l'utente nick è presente nella rete dell'utente. Se si cambio il puntatore altrimenti non faccio niente
                            if(r->find(nick)!=r->end()){
                                //cambio il puntatore
                                (r->operator[](nick))=x;

                            }


                        }
                    }
            }
           throw downgrade_ok;
        }

}
