#ifndef INFO_H
#define INFO_H
#include<string>
#include<list>
#include<iostream>
using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::list;

class Info{

private:
    list<string> esperienze;
    list<string> lingue;
    list<string> studi;
public:
    Info(const list<string>& ep=list<string>(),const list<string>& l=list<string>() ,const list<string>& ts=list<string>());
    const list<string>* getEsp() const;
    const list<string>* getLingue() const;
    const list<string>* getStudi() const;
    void addEsp(string );
    void replaceEsp(int,string);
    void eraseEsp(string);
    void addLingue(string );
    void eraseLingue(string );
    void addStudi(string );
    void eraseStudi(string);
    void readList(list<string>&,string)const;

};

#endif // INFO_H
