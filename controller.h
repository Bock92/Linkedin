#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "linkedinadmin.h"
#include "linkedinclient.h"
#include "eccezioni.h"
#include<QList>
#include<QStringList>
#include <list>
#include <string>
#include <map>
#include<vector>
using std::vector;
using std::list;
using std::string;
using std::map;

class Utente;

class Controller{

private:

    LinkedinAdmin* admin;
    LinkedinClient* user;



public:

    Controller(string,string ="\0");
    ~Controller();
    map<string,vector<list<string> > > search(string ,string )const;
    vector<list<string> > search(string)const;
    map<string,vector<list<string> > > searchUser(string,string)const;
    void changeProfilo(string ="\n",string ="\n",string ="\n",string ="\n");
    void insertLanguage(string);
    void removeLanguage(string);
    void insertStudi(string);
    void removeStudi(string);
    void replaceEsperienza(int,string);
    void addEsperienza(string);
    void removeEsperienza(string);
    void addContatto(string);
    void removeContatto(string);
    void addUsr(string,string,string,string);
    void deleteUsr(string);
    void upgradeAccount(string,int);
    void downgradeAccount(string,int);
    void save();
    void readProfiloUtente(list<string>&)const;
    void readListInfo(list<string>&,string)const;
    void readContatti(list<string>&)const;
    void readNickContatti(list<string>&)const;




};

#endif // CONTROLLER_H
