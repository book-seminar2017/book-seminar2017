#include<iostream>
using namespace std;
#define MAX 2000000

int H, A[MAX+1];

void maxHeapify(int i){


}

int main(){
    cin >> H;
    
    for ( int i = 1; i <= H; i++) cin >> A[i];

    for ( int i = H / 2; i >= 1; i--) maxHeapify(i);

    for (int i  = 1; i <= H; i++){
        cout << " " << A[i];
    }
    cout << endl;

    return 0;
}
