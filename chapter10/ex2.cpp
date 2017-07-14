#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 2000000
#define INFTY (1<<30)

int H, A[MAX+1];

void maxHeapfi(int i){
  // ex1と同じ
}

int extract(){
    // ひとつ最大の要素を取り出す
    return 0;
}

void insert(int key){
    // 要素keyを追加

}

int main(){
    int key;
    char com[10];

    while(1){
        scanf("%s", com);
        if ( com[0] == 'e' && com[1] == 'n' ) break;
        if ( com[0] == 'i' ){
            scanf("%d", &key);
            insert(key);
        } else {
            printf("%d\n", extract());
        }
    }

    return 0;
}
