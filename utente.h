#ifndef UTENTE_H
#define UTENTE_H
#include<string>
#include<map>
#include<list>
#include<vector>
#include"profilo.h"
using std::vector;
using std::list;
using std::string;
using std::map;


class DB;
class Rete;

class Utente{
private:
  Profilo pf;
  Rete* net;
  string usr;


public:
    Utente(string,string,string,const list<string>& =list<string>(),const list<string>& =list<string>(),const list<string>& =list<string>(),string ="\0",string ="\0",const map<string,Utente*>& =map<string,Utente*>());
    Utente(string,const Profilo&,const Rete&);
    virtual ~Utente();
    string getUsername()const;
    const Profilo* getProfilo()const;
    Rete* getRete()const;
    virtual map<string,vector<list<string> > > userSearch(const DB& ,string ,string )const =0;
    virtual void readProfilo(list<string>&)const =0;
    void readInfoList(list<string>&,string)const;
    void readReteContatti(list<string>&)const;
    void readNickContatti(list<string>&)const;
    vector<list<string> > showUtente()const;
};

#endif // UTENTE_H
