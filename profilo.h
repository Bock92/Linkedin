#ifndef PROFILO_H
#define PROFILO_H
#include"info.h"
#include<string>
#include<list>
using std::string;
using std::list;


class Profilo{
private:

Info* info_profilo;
string nome,cognome,data_nascita,mail;

public:

    Profilo(string ,string ,const list<string>& ep=list<string>(),const list<string>& l=list<string>(),const list<string>& ts=list<string>(),string ="\0",string ="\0");
    Info* getInfo()const;
    Profilo(const Profilo& ); //costruttore di copia ridefinito
    ~Profilo();
    string getNome()const;
    string getCognome()const;
    string getData()const;
    string getMail()const;
    void setNome(string);
    void setCognome(string);
    void setData(string);
    void setMail(string);
    void readPf(list<string>&)const;


};
#endif // PROFILO_H
