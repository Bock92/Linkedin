#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H
#include"utente.h"
#include"db.h"

class Rete;

class UtenteBusiness: public Utente{
public:
    //il distruttore ~UtenteBusiness è virtuale
    virtual ~UtenteBusiness();
    UtenteBusiness(string ,string ,string,const list<string>& =list<string>(),const list<string>& =list<string>(),const list<string>& =list<string>(),string ="\0",string ="\0",const map<string,Utente*>& =map<string,Utente*>());
    UtenteBusiness(string,const Profilo&,const Rete&);
    virtual map<string,vector<list<string> > > userSearch(const DB&, string, string) const;
    virtual void readProfilo(list<string>&)const;

};

#endif // UTENTEBUSINESS_H
