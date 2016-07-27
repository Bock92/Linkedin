#include "utentebusiness.h"
#include<iostream>
using std::cout;
using std::endl;

UtenteBusiness::UtenteBusiness(string u,string n,string c,const list<string>& ep,const list<string>& l,const list<string>& ts,string d,string m,const map<string,Utente*>& contatti):Utente(u,n,c,ep,l,ts,d,m,contatti){}

UtenteBusiness::UtenteBusiness(string u,const Profilo& p,const Rete& r):Utente(u,p,r){}

UtenteBusiness::~UtenteBusiness(){}

map<string,vector<list<string> > > UtenteBusiness::userSearch(const DB& d, string n, string c) const{

    vector<Utente*> ut=d.find(n,c);

    map<string,vector<list<string> > > info_map;
    vector<list<string> > tmp;
    list<string> list_tmp;

    for(unsigned int i=0;i<ut.size();i++){

        (ut[i])->readProfilo(list_tmp);
        tmp.push_back(list_tmp);
        list_tmp.erase(list_tmp.begin(),list_tmp.end());

        (ut[i])->readInfoList(list_tmp,"Esperienze");
        tmp.push_back(list_tmp);
        list_tmp.erase(list_tmp.begin(),list_tmp.end());

        (ut[i])->readInfoList(list_tmp,"Lingue");
        tmp.push_back(list_tmp);
        list_tmp.erase(list_tmp.begin(),list_tmp.end());

        (ut[i])->readInfoList(list_tmp,"Studi");
        tmp.push_back(list_tmp);

        map<string,vector<list<string> > >::value_type v((ut[i])->getUsername(),tmp);
        info_map.insert(v);

        tmp.erase(tmp.begin(),tmp.end()); // azzero tmp
        list_tmp.erase(list_tmp.begin(),list_tmp.end()); //azzero list_tmp
    }

    return info_map;
}

void UtenteBusiness::readProfilo(list<string>& lista)const{

    lista.push_back("Business");
    lista.push_back(this->getUsername());
    this->getProfilo()->readPf(lista);

}
