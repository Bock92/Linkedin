#ifndef LINQEDINADMIN_H
#define LINQEDINADMIN_H
#include"db.h"
#include "eccezioni.h"
#include<string>
#include<vector>
#include<list>
using std::vector;
using std::list;
using std::string;

class LinkedinAdmin{
private:
    DB* database;
public:
    LinkedinAdmin();
    ~LinkedinAdmin();
    void addUser(string,string,string,string);
    DB* getDatabase()const;
    void removeUser(string );
    void save()const;
    map<string,vector<list<string> > > search(string,string)const;
    vector<list<string> > search(string)const;
    void upgrade(string,int); //nick e tipo (1=basic,2=business,3=executive)
    void downgrade(string,int);
};

#endif // LINQEDINADMIN_H
