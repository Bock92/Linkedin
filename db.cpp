#include "db.h"
#include"utentebasic.h"
#include"utenteexecutive.h"
#include<iostream>
#include<typeinfo>
using std::cout;
using std::endl;

DB::DB():db(){}

void DB::load(){

ifstream INP;
ifstream Contatti;
INP.open("LINKEDINDB",ifstream::in);

while('~'!=INP.peek()){
   string tipo="\0",user="\0",nome="\0",cognome="\0",data="\0",mail="\0",tmp="\0";
   list<string> pers;
   list<string> l;
   list<string> studi;


   getline(INP,tipo,'$');
   getline(INP,user,'$');
   getline(INP,nome,'$');
   getline(INP,cognome,'$');
   getline(INP,data,'$');
   getline(INP,mail,'$');
   getline(INP,tmp,'$');

   while(tmp!="\0"){
       pers.push_back(tmp);
       getline(INP,tmp,'$');

   }

   getline(INP,tmp,'$');

   while(tmp!="\0"){
       l.push_back(tmp);
       getline(INP,tmp,'$');

   }


   getline(INP,tmp,'$');

   while(tmp!="\0"){
       studi.push_back(tmp);
       getline(INP,tmp,'$');
   }

   //ho letto tutti i dati che mi servono per creare un utente

   if(tipo=="Basic"){
      UtenteBasic* u=new UtenteBasic(user,nome,cognome,pers,l,studi,data,mail);
      map<string,Utente*>::value_type v(user,u);
      db.insert(v);

   }
   else if(tipo=="Business"){
      UtenteBusiness* u=new UtenteBusiness(user,nome,cognome,pers,l,studi,data,mail);
      map<string,Utente*>::value_type v(user,u);
      db.insert(v);

   }
   else if(tipo=="Executive"){
       UtenteExecutive* u=new UtenteExecutive(user,nome,cognome,pers,l,studi,data,mail);
       map<string,Utente*>::value_type v(user,u);
       db.insert(v);

   }

}

INP.close();

Contatti.open("LINKEDINRETE",ifstream::in);

string key,user_tmp;

while('~'!=Contatti.peek()){

 //suppongo che in questo file, ci sono Utenti che hanno almeno un Utente nella propria rete contatti
 //se l'Utente non ha almeno un contatto allora non compare nel file LinQeinRete perchè di default la rete è già stata creata vuota nella fase precedente

 getline(Contatti,key,'$');

 Utente* j=db[key];
 Rete* x=const_cast<Rete*>(j->getRete());

 getline(Contatti,user_tmp,'$');

 while(user_tmp!="\0"){
    Utente* z=db[user_tmp];
    x->add_Contatto(z,user_tmp);
    getline(Contatti,user_tmp,'$');
 }


}

Contatti.close();

}

void DB::writeList(const list<string>& l,ofstream& OUT){

    for(list<string>::const_iterator inizio=l.begin();inizio!=l.end();inizio++){
        OUT<<*inizio+"$";

    }

}

void DB::save()const{

    ofstream DataBase;
    DataBase.open("LINKEDINDB",ofstream::out);
    ofstream Net;
    Net.open("LINKEDINRETE",ofstream::out);

    list<string>tmp;



  for(map<string,Utente*>::const_iterator u=db.begin();u!=db.end();u++){

     u->second->readProfilo(tmp);
     writeList(tmp,DataBase);
     tmp.erase(tmp.begin(),tmp.end());

     u->second->readInfoList(tmp,"Esperienze");
     writeList(tmp,DataBase);
     tmp.erase(tmp.begin(),tmp.end());
     DataBase<<"$";

     u->second->readInfoList(tmp,"Lingue");
     writeList(tmp,DataBase);
     tmp.erase(tmp.begin(),tmp.end());
     DataBase<<"$";

     u->second->readInfoList(tmp,"Studi");
     writeList(tmp,DataBase);
     tmp.erase(tmp.begin(),tmp.end());
     DataBase<<"$";

     u->second->readNickContatti(tmp);
     if(tmp.size()>0){
         Net<<u->first<<"$";
         writeList(tmp,Net);
         Net<<"$";
         tmp.erase(tmp.begin(),tmp.end());
     }

  }

  DataBase<<"~";
  DataBase.close();
  Net<<"~";
  Net.close();


}

Utente* DB::find(string u)const{


  map<string,Utente*>::const_iterator j;
  j=db.find(u);

  if(j!=db.end()){
      return j->second;
  }
  else{return 0;} //utente non presente

}

vector<Utente*> DB::find(string n, string c) const{


    vector<Utente*>ut;

    for(map<string,Utente*>::const_iterator inizio=db.begin();inizio!=db.end();inizio++){
        if((inizio->second->getProfilo()->getNome() == n) && (inizio->second->getProfilo()->getCognome() == c)){
            ut.push_back(inizio->second);
        }
    }

    return ut;

}

const map<string,Utente*>* DB::getDB()const{
    return &db;
}

void DB::addUtente(string n, string c, string user, string t){

    if(db.find(user)!=db.end()){ //controllo che non ci sia già l'utente nel db
        throw insert_denied;
    }

    if(t=="Basic"){
       UtenteBasic* u=new UtenteBasic(user,n,c);
       map<string,Utente*>::value_type v(user,u);
       db.insert(v);
       throw insert_ok;

    }
    else if(t=="Business"){
       UtenteBusiness* u=new UtenteBusiness(user,n,c);
       map<string,Utente*>::value_type v(user,u);
       db.insert(v);
       throw insert_ok;

    }
    else if(t=="Executive"){
        UtenteExecutive* u=new UtenteExecutive(user,n,c);
        map<string,Utente*>::value_type v(user,u);
        db.insert(v);
        throw insert_ok;

    }


}

void DB::removeUtente(string nick){ //Funziona

      map<string,Utente*>::const_iterator j;
      j=db.find(nick);

      if(j!=db.end()){
          db.erase(nick); //rimuovo l'utente dal DB

          for(map<string,Utente*>::iterator k=db.begin();k!=db.end();k++){
             if(!(k->second->getRete()->getRete()->empty())){
                 k->second->getRete()->remove_Contatto(nick);
                }
            }
          throw remove_ok;
      }
      else{throw remove_denied;}

}
