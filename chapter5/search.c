#include<stdio.h>
#define MAX 10000

int serch_liner(const int* a, const int length, const int key){
  int i;
  for(i = 0; i < length; i++){
    if(a[i] == key) return 1;
  }
  return 0;
}

int search(int* a, const int length, const int key){
  //番兵の配置は引数に破壊的操作を行う
  int i = 0;
  a[length] = key; //番兵の設置
  while(a[i] != key) i++;
  return (i != length);
}

int binary_search(const int* a, const int length, const int key){
  int left = 0;
  int right = length - 1;
  int mid;
  while(right >= left){
    mid = (left + right) / 2;
    if(a[mid] == key) return 1;
    if(key > a[mid]){
      left = mid + 1;
    }else{
      right = mid - 1;
    }
  }
  return 0;
}

int binary_search_rev(const int* a, const int left, const int right, const int key){
  if(left == right) return (a[left] == key);
  int mid = (left + right) / 2;
  if(a[mid] == key) return 1;
  if(key > a[mid]){
    return binary_search_rev(a, mid+1, right, key);
  }else{
    return binary_search_rev(a, left, mid-1, key);
  }
}

int main(){
  int i, length, a[MAX + 1], q, key, sum = 0;

  scanf("%d", &length); //lengthの値のセット
  //配列aの値のセット
  //int* p = a;
  for(i = 0; i < length; i++){
    scanf("%d", &a[i]);
    //scanf("%d", p++); こんな書き方もあるよ
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &key);
    //各keyに対しての探索
    if(search(a, length, key)) sum++;
  }
  printf("%d\n", sum);
  return 0;
}
