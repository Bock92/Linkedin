#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H
#include"utente.h"
#include"db.h"

class Rete;

class UtenteBasic:public Utente{
public:

    virtual ~UtenteBasic();
    UtenteBasic(string ,string , string,const list<string>& =list<string>(),const list<string>& =list<string>(),const list<string>& =list<string>(),string ="\0",string ="\0",const map<string,Utente*>& =map<string,Utente*>());
    UtenteBasic(string,const Profilo&,const Rete&);
    virtual map<string,vector<list<string> > > userSearch(const DB&, string, string) const;
    virtual void readProfilo(list<string>&)const;
};

#endif // UTENTEBASIC_H
