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

        stringstream ss(line);

        ss>>str;

        cout<<"first: "<<str<<endl;

        ss>>str;

        cout<<"second: "<<str<<endl;

    }

    reader.close();

}