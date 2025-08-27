    ifstream reader(file);

    if(reader.is_open()){
        string line,str;

        while (getline(reader, line)) {
            stringstream ss(line);  
            string first, second;
            ss >> first >> second;

            if (first == "#include" && !second.empty()) {
                // remove include header file
                string newFile = second.substr(1, second.length()-2);
                readInclude(newFile);  // recursive call
            } else if (!line.empty()) {
                // only print if it's not an include line or blank
                cout << line << endl;
            }
        }
    }

    reader.close();
}