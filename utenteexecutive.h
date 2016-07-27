#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H
#include"utentebusiness.h"
#include"rete.h"



class UtenteExecutive: public UtenteBusiness{
public:

    virtual ~UtenteExecutive();
    UtenteExecutive(string ,string ,string,const list<string>& =list<string>(),const list<string>& =list<string>(),const list<string>& =list<string>(),string ="\0",string ="\0",const map<string,Utente*>& =map<string,Utente*>());
    UtenteExecutive(string,const Profilo&,const Rete&);
    virtual map<string,vector<list<string> > > userSearch(const DB& ,string ,string )const;
    virtual void readProfilo(list<string>&)const;
};

#endif // UTENTEEXECUTIVE_H
