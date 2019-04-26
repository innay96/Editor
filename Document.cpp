#include "Document.h"
#include <vector>
#include <iostream>
 
// C'tor
Document::Document() : curr{0}
{
    vector <string> other_doc_line(0);
    vec = other_doc_line;
}

// p
void Document::printCurrLine()
{
    if(curr <= 0) 
    {
        cerr << "The Document is empty" << endl;
        return;
    }
    else
    {
        cout << vec.at(curr-1) << endl;
    }
}

// n
void Document::printCurrIndex()  
{
    if(curr <= 0){
        cerr << "The Document is empty" << endl;
        return;
    }
    else{
        cout << (curr-1) << "   ";
        printCurrLine();
    }
}

// %p
void Document::printAll()      
{
    if(curr <= 0){
        cerr << "The Document is empty" << endl;
        return;
    }
    else{
        for(int i = 0; i < vec.size(); i++){
            cout << (i);
            printCurrLine();
        }
    }
}

// 7
void Document::currIndexChange(int i)            
{
         if(i> vec.size()) 
        {
                cerr << "There is no such line" << endl;
                return;
                }
        else
        {
                curr= i;
                
        } 
}

// a
void Document::append() 
{
    string newText;
    while(getline(cin,newText) && newText != ".")
    {
        if(curr >= vec.size())
        {
            vec.push_back(newText);
        }
        else
        {
            vector <string>::iterator start;
            start = vec.begin();
            vec.insert(start + curr , newText);
        }
        curr++;   
    }
}

// i
void Document::insert()  
{
        string newText;
        curr--;
    while(getline(cin,newText) && newText != ".")
    {
        if(curr >= vec.size())
        {
            vec.push_back(newText);
        }
        else
        {
            vector <string>::iterator start;
            start = vec.begin();
            vec.insert(start + curr , newText);
        }
        curr++;   
    }
    curr++;

}

// c
void Document::change()              
{
    if(vec.at(curr).empty()){
        cerr << "There is no next line" << endl;
        return;
    }
    else{
        vec.at(curr-1) = vec.at(curr);
    }
}

// d
void Document::deleteLine()          
{
    vec.at(curr-1).erase();
}

// /text
void Document::search(string text){
    for(int i = curr-1; i < vec.size(); i++){
        if(vec.at(i).find(text) != string::npos){
            curr = i+1;
            return;
        }
    }
     for(int i = 0; i < curr; i++){
        if(vec.at(i).find(text) != string::npos){
            curr = i+1;
            return;
        }
    }
}

// s/old/new/
void Document::replace(string oldText, string newText){
    if(curr <= 0)
    {
       cerr << "The old word does'nt exist" << endl;
       return;
    }
    if(vec.at(curr-1).find(oldText) != string::npos){
        int ind = vec.at(curr-1).find(oldText);
        vec.at(curr-1).replace(ind , oldText.size() , newText);
    }
    else
    {
      cerr << "The old word does'nt exist" << endl;
    } 
}

// Q
void Document::quit(){
    exit(0);
}


int main(){
    Document doc;
    doc.append();
}

