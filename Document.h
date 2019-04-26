#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Document{
    private:
    vector <string> vec;
    int curr;

    public:
        Document();
        void printCurrLine();         //prints the current line
        void printCurrIndex();        //prints the index of the current line -->TAB --> current line
        void printAll();              //prints all of the lines
        void currIndexChange(int i);       //makes line 7 the current line
        void append();  //appends new text after the current line
        void insert();  //inserts new text before current line
        void change();                //changes the current line with the following one
        void deleteLine();            //deletes the current line
        void search(string text);     //searches forward after current line for the specified text. The search wraps to the beginning of the buffer and continues down to the current line, if necessary    
        void replace(string oldText, string newText); //replaces old string with new in current line
        void quit();                  //Quits the editor without saving 
};

#endif