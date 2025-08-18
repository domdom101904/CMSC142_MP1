//The goal is to simply literally insert the contents of the included files
//in the c/c++ source file, replacing the preprocessor directives in the 
//correct order. When a header file is included more than once, insert the 
//first include and disregard the succeeding ones.

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void readInclude(string);

int main(){
    string fileName;

    cin>>fileName;

    readInclude(fileName);

}

void readInclude(string file){
    ifstream reader(file);

    if(reader.is_open()){
        string line,str;
        //#include "sample.h"

        getline(reader, line);
            //sir wants us to read multiple files
            //this line returns 0 when it reaches the end of the file

        stringstream ss(line);

        ss>>str;

        //cout<<"first: "<<str<<endl;

        if(str.compare("#include")==0){
            ss>>str;
            cout<<"included file: "<<str<<endl;
            string newFile = str.substr(1,str.length()-2);
            cout<<"new file: "<<newFile<<endl;
            //readInclude();
        }

        //cout<<"second: "<<str<<endl;

    }

    reader.close();

}