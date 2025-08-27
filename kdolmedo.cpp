//The goal is to simply literally insert the contents of the included files
//in the c/c++ source file, replacing the preprocessor directives in the 
//correct order. When a header file is included more than once, insert the 
//first include and disregard the succeeding ones.
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

void readInclude(string);

int main(){
    string fileName;

    cin>>fileName;

    readInclude(fileName);

}

void readInclude(string file){
    static set<string> visit;   // remembers which files were already included

    if (visit.count(file)) return; // skip if already read
    visit.insert(file);

    ifstream reader(file);

    if(reader.is_open()){
        string line;

        while (getline(reader, line)) {
            stringstream ss(line);  
            string first, second;
            ss >> first >> second;

            if (first == "#include" && !second.empty()) {
                // remove include header thingy
                string newFile = second.substr(1, second.length()-2);
                readInclude(newFile);  // recursive call
            } else if (!line.empty()) {
                cout << line << endl;
            }
        }
    }

    reader.close();
}