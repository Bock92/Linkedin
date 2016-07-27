#include "utente.h"
#include"rete.h"
#include<iostream>
using std::cout;
using std::endl;

Utente::Utente(string u,string n,string c,const list<string>& ep,const list<string>& l,const list<string>& ts, string d,string m,const map<string,Utente*>& contatti):pf(n,c,ep,l,ts,d,m),net(new Rete(contatti)),usr(u){}

Utente::Utente(string u, const Profilo& p, const Rete& r):pf(p),net(new Rete(r)),usr(u){}

Utente::~Utente(){if(net) delete net;}

string Utente::getUsername()const{
    return usr;
}

const Profilo* Utente::getProfilo()const{
    return &pf;
}

Rete* Utente::getRete()const{
    return net;
}

void Utente::readInfoList(list<string>& lista,string nome_lista)const{

    pf.getInfo()->readList(lista,nome_lista);
}

void Utente::readReteContatti(list<string>& lista)const{
    net->readRete(lista);
}

void Utente::readNickContatti(list<string>& lista)const{
    net->readNick(lista);
}

vector<list<string> > Utente::showUtente()const{

    vector<list<string> > tmp;
    list<string> lista;

    this->readProfilo(lista);
    tmp.push_back(lista);
    lista.erase(lista.begin(),lista.end());

    this->readInfoList(lista,"Esperienze");
    tmp.push_back(lista);
    lista.erase(lista.begin(),lista.end());

    this->readInfoList(lista,"Lingue");
    tmp.push_back(lista);
    lista.erase(lista.begin(),lista.end());

    this->readInfoList(lista,"Studi");
    tmp.push_back(lista);
    lista.erase(lista.begin(),lista.end());

    this->readReteContatti(lista);
    tmp.push_back(lista);

    return tmp;

}
