#include <iostream>
#include <fstream>
#include <algorithm>

static const int MAX = 200000;

using namespace std;

int main(int argc, char *argv[]){
    string input_file = argv[1];
    string str;
    ifstream ifs(input_file);

    int n;
    getline(ifs, str);
    n = stoi(str);
    int maxv = -1000000000;
    getline(ifs, str);
    int minv = stoi(str);
    int r;


    if(ifs.fail()){
        cerr << "failed to open file" << endl;
        return -1;
    }



    for (int i = 0; i < n - 1; i++){
        getline(ifs, str);
        r = stoi(str);
        maxv = max(maxv, r - minv);
        minv = min(minv, r);
    }

    cout << maxv << endl;

    return 0;
}
