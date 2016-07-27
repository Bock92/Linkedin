#ifndef LINQEDINCLIENT_H
#define LINQEDINCLIENT_H
#include"utente.h"
#include"rete.h"
#include"db.h"
#include"eccezioni.h"
#include<string>
#include<list>
using std::string;

class LinkedinClient{
private:
    Utente* user;
    DB* pdb;
public:
    LinkedinClient(string );
    ~LinkedinClient();
    void changeProfilo(string ="\n",string ="\n",string ="\n",string ="\n");
    void insertLanguage(string);
    void removeLanguage(string);
    void insertEsp(string);
    void changeEsp(int,string);
    void removeEsp(string);
    void insertStudy(string);
    void removeStudy(string);
    void insertContatto(string);
    void removeContatto(string );
    map<string,vector<list<string> > > search(string ,string )const;
    void save()const;
    Utente* getUser()const;
};

#endif // LINQEDINCLIENT_H
