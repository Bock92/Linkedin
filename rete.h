#ifndef RETE_H
#define RETE_H
#include<iostream>
#include"utente.h"
#include<string>
#include<map>
#include<list>
using std::list;
using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::map;



class Rete{

private:
map<string,Utente*> rete_amici;
public:
    Rete(const map<string,Utente*>& =map<string,Utente*>());
    void add_Contatto(Utente*,string );
    void remove_Contatto(string );//string = username
    const map<string,Utente*>* getRete()const;
    void readRete(list<string>&)const;
    void readNick(list<string>&)const;
};


#endif // RETE_H
