#include "utenteexecutive.h"
#include<iostream>
using std::cout;
using std::endl;

UtenteExecutive::UtenteExecutive(string u,string n,string c,const list<string>& ep,const list<string>& l,const list<string>& ts,string d,string m,const map<string,Utente*>& contatti):UtenteBusiness(u,n,c,ep,l,ts,d,m,contatti){}

UtenteExecutive::UtenteExecutive(string u,const Profilo& p,const Rete& r):UtenteBusiness(u,p,r){}

UtenteExecutive::~UtenteExecutive(){}

map<string,vector<list<string> > > UtenteExecutive::userSearch(const DB& d, string n, string c) const{

    vector<Utente*> ut=d.find(n,c);

    map<string,vector<list<string> > > info_map;

    for(unsigned int i=0;i<ut.size();i++){

        map<string,vector<list<string> > >::value_type v((ut[i])->getUsername(),(ut[i])->showUtente());
        info_map.insert(v);

    }

    return info_map;

}

void UtenteExecutive::readProfilo(list<string>& lista)const{

    lista.push_back("Executive");
    lista.push_back(this->getUsername());
    this->getProfilo()->readPf(lista);
}
