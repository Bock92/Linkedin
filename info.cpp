#include "info.h"

Info::Info(const list<string>& ep,const list<string>& l,const list<string>& ts):esperienze(ep),lingue(l),studi(ts){}


const list<string>* Info::getEsp() const{
    return &esperienze;
}

const list<string>* Info::getLingue() const{
    return &lingue;
}
const list<string>* Info::getStudi() const{
    return &studi;
}


void Info::addEsp(string x){
    esperienze.push_back(x);
}

void Info::replaceEsp(int pos,string text){
    list<string>::iterator x=esperienze.begin();
    for(int i=0;i<pos;i++){
        x++;
    }

    *x=text;
}

void Info::eraseEsp(string x){
    esperienze.remove(x);
}

void Info::addLingue(string x){
    lingue.push_back(x);
}

void Info::eraseLingue(string lingua){
 lingue.remove(lingua);
}

void Info::addStudi(string x){
    studi.push_back(x);
}

void Info::eraseStudi(string titolo_studio){
    studi.remove(titolo_studio);
}


void Info::readList(list<string>& lista,string nome_lista)const{
    if(nome_lista == "Esperienze"){
        lista=esperienze;
    }
    else if(nome_lista == "Lingue"){
        lista=lingue;
    }
    else if(nome_lista == "Studi"){
        lista=studi;
    }
}

