#ifndef DB_H
#define DB_H
#include "eccezioni.h"
#include<map>
#include<fstream>
#include<string>
#include<list>
#include<vector>
using std::vector;
using std::list;
using std::string;
using std::ifstream;
using std::ofstream;
using std::map;

class Utente;
class Profilo;

class DB{
private:
  map<string,Utente*> db;
 static void writeList(const list<string>&,ofstream&);

public:
    DB();
    void load();
    void save()const;
    Utente* find(string )const;
    vector<Utente*> find(string,string)const;
    const map<string,Utente*>* getDB()const;
    void addUtente(string,string,string,string);
    void removeUtente(string );


};



#endif // DB_H
