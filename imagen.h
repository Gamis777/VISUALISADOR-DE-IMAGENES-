#ifndef IMAGEN_H
#define IMAGEN_H
#include<iostream>
#include<vector>
using namespace std;

class imagen{
private:
    string name;
    string file;
    //vector <string> tags;
public:
    imagen(){
        name="";
        file="";
    }
    imagen(const char* name_, const char* file_){
        name=name_;
        file=file_;
    }

    /*imagen(const imagen & p){
        name=p.name;
        file=p.file;

    }*/
    /*void operator = (const imagen &p){
        name=p.name;
        file=p.file;
        //tags=p.tags;
    }*/
    void add_name(string st){
           name=st;
    }
    void add_file(string st){
           file=st;
     }
    string show_name(){
        return name;
    }
    string show_file(){
        return file;
    }

    string show_all(){
        string text= "File: " + file + "<p>Name: " + name + "</p>" + "Tags: ";

        return text;
    }
};
#endif // IMAGEN_H
