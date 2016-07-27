#include "rete.h"

Rete::Rete(const map<string,Utente*>& contatti):rete_amici(contatti){}


void Rete::add_Contatto(Utente* u,string nick){

    map<string,Utente*>::value_type x(nick,u);
    rete_amici.insert(x);

}

void Rete::remove_Contatto(string user){

  map<string,Utente*>::const_iterator j=rete_amici.find(user);

  if(j!=rete_amici.end()){
      rete_amici.erase(user);
  }

}


const map<string,Utente*>* Rete::getRete()const{
    return &rete_amici;
}

void Rete::readRete(list<string>& lista)const{
    for(map<string,Utente*>::const_iterator inizio=rete_amici.begin();inizio!=rete_amici.end();inizio++){
        lista.push_back(inizio->second->getProfilo()->getCognome());
        lista.push_back(inizio->second->getProfilo()->getNome());
    }
}

void Rete::readNick(list<string>& lista)const{
    for(map<string,Utente*>::const_iterator inizio=rete_amici.begin();inizio!=rete_amici.end();inizio++){
        lista.push_back(inizio->first);
    }
}
