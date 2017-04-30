#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 13
#define OP_LEN 7
#define INIT ""
#define NIL (-1)
#define HASH_SIZE 1046527

typedef char* string;

typedef struct {
  string dict[HASH_SIZE];
} hash_map;

long get_key(const string target);
int h1(long key);
int h2(long key);
int find(const string target, const hash_map* map);
int insert(const string target, hash_map* map);

long get_key(const string target){
  int i;
  long result = 0;
  int length = (int)strlen(target);
  if(length > MAX_LEN) return -1;
  for(i = 0; i < length; i++){
    char c = target[i];
    result = result << 3;
    if(c == 'A'){
      result += 1;
    }else if(c == 'C'){
      result += 2;
    }else if(c == 'G'){
      result += 3;
    }else if(c == 'T'){
      result += 4;
    }
  }
  return result;
}

int h1(long key){
  return key % HASH_SIZE;
}

int h2(long key){
  return 1 + (key % (HASH_SIZE -1));
}

int insert(const string target, hash_map* map){
  long key = get_key(target);
  if(key == -1) return 0;
  int point, i = 0;
  while(1){
    point = ((h1(key) + i * h2(key))) % HASH_SIZE;
    string tmp = map -> dict[point]; 
    if(!strcmp(tmp, target)) return 0; //already exist
    if(!strcmp(tmp, INIT)){
      //insert target
      strcpy((map -> dict[point]), target);
      return 1;
    }
    if((++i) > HASH_SIZE) return 0; //hash map is full
  }
}

int find(const string target, const hash_map* map){
  long key = get_key(target);
  if(key == -1) return 0;
  int point, i = 0;
  while(1){
    point = ((h1(key) + i * h2(key))) % HASH_SIZE;
    string tmp = map -> dict[point]; 
    if(!strcmp(tmp, target)) return 1;
    if((!strcmp(tmp, INIT)) || ((++i) > HASH_SIZE)) return 0;
  }
}

int main(){
  int op_num, i;
  char op[OP_LEN];
  char str[MAX_LEN];
  hash_map map;
  //mapの初期化
  for(i = 0; i < HASH_SIZE; i++){
    map.dict[i] = (string) malloc(sizeof(char) * MAX_LEN);
    strcpy(map.dict[i], INIT);
  }

  scanf("%d", &op_num);

  for(i = 0; i < op_num; i++){
    scanf("%s %s", op, str);
    if(op[0] == 'i'){
      insert(str, &map);
      //if(!insert(str, &map)) printf("fail insert %s \n", str);
    }else{
      if(find(str, &map)){
	printf("yes\n");
      }else{
	printf("no\n");
      }
    }
  }
  
  return 0;
}
