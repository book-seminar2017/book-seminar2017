#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){
    string input_file = argv[1];
    string str;
    ifstream ifs(input_file);

    if(ifs.fail()){
        cerr << "failed to open file" << endl;
        return -1;
    }

    int n;
    getline(ifs, str);
    n = stoi(str);
    int rems[7] = {};

    int count = 0;

    for (int i = 0; i < n; ++i){
        getline(ifs, str);
        int input = stoi(str);
        int rem = input % 7;
        rems[rem] += 1;
    }

    for (int i = 0; i < 5; ++i){
        for (int j = i + 1; j < 6; ++j){
            for (int k = j + 1; k < 7; ++k){
                if((i + j + k) % 7 == 0){
                    count += rems[i] * rems[j] * rems[k];
                }
            }
        }
    }

    for (int i = 0; i < 7; ++i){
        if(rems[i] >= 2){
            for (int j = 0; j < 7; ++j){
                if (((i + i + j) % 7 ==0) && (i != j)){
                    count += rems[i] * (rems[i] - 1) / 2 * rems[j];
                }
            }
        }
    }

    for (int i = 0; i < 7; ++i){
        if (rems[i] >= 3){
            if(i * 3 % 7 == 0){
                count += rems[i] * (rems[i] - 1) * (rems[i] - 2) / 6;
            }
        }
    }

    cout << count << endl;

    return 0;
}
