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
        getline(reader, line);

    }

    reader.close();

}