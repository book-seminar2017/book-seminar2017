#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    string input_file = argv[1];
    string str;
    ifstream ifs(input_file);
    if(ifs.fail()){
        cerr << "failed to open file" << endl;
        return -1;
    }
    while(getline(ifs, str)) {
        cout << str << endl;
    }
    return 0;
}
