#include "profilo.h"



Profilo::Profilo(string n,string c,const list<string>& ep,const list<string>& l,const list<string>& ts,string d,string m):info_profilo(new Info(ep,l,ts)),nome(n),cognome(c),data_nascita(d),mail(m){}

Profilo::~Profilo(){
    if(info_profilo) delete info_profilo;
}

Info* Profilo::getInfo()const{
   return info_profilo;
}

Profilo::Profilo(const Profilo& p):info_profilo(new Info(*(p.getInfo()))),nome(p.nome),cognome(p.cognome),data_nascita(p.data_nascita),mail(p.mail){}

string Profilo::getNome()const{
    return nome;
}

string Profilo::getCognome()const{
    return cognome;
}

string Profilo::getData()const{
    return data_nascita;
}

string Profilo::getMail()const{
    return mail;
}

void Profilo::setNome(string n){
    nome=n;
}

void Profilo::setCognome(string c){
    cognome=c;
}

void Profilo::setData(string d){
    data_nascita=d;
}

void Profilo::setMail(string m){
    mail=m;
}

void Profilo::readPf(list<string>& lista)const{
    lista.push_back(nome);
    lista.push_back(cognome);
    lista.push_back(data_nascita);
    lista.push_back(mail);
}
