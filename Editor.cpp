#include"Editor.h"

using namespace std;

Editor::Editor(){
    loop();
}

void Editor::loop(){
    string input;
while(1){
    getline(cin, input);

        if(input=="p"){
            doc.printCurrLine();
            break;
        }
        else if(input=="n"){
            doc.printCurrIndex();
            break;
        }
        else if(input=="%p"){
            doc.printAll(); 
            break;
        }   
        else if(input=="a"){
            doc.append();
            break;
        }
        else if(input=="i"){
            doc.insert();
            break;
        }
        else if(input=="c"){
            doc.change();
            break;
        }
        else if(input=="d"){
            doc.deleteLine();
            break;
        }
        else if(input=="Q"){
            doc.quit();
            return;
    }
    else{
        if(input.size() > 0) {
            if (input.at(0) == '/')
            {
                doc.search(input.substr(1));
            }
            else  if(input.at(0) == 's'&& input.size()>2){
                size_t slash = input.find("/", 2);
                    if(slash != string::npos) {
                        string oldString;

                        for(int i = 2; i < slash; i++) {
                            oldString += input[i];
                            }
                        if(input[input.size()-1] != '/'){
                            cerr << "typing error" << endl;
                            return;
                        }
                            
                        string newString = input.substr(slash+1, input.size()-1);
                        doc.replace(oldString, newString);
                    }
                }
            }
        }
    }
}