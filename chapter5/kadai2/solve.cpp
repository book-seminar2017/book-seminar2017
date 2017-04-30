#include<iostream>
using namespace std;
#define MAX 100000
typedef long long ll;
int weight_num, track_num;
ll weight[MAX];

int check(ll p){
  int i = 0;
  for (int j = 0; j < track_num; j++){
    ll s = 0;
    while(s + weight[i] <= p){
      s += weight[i++];
      if(i == weight_num) return weight_num;
    }
  }
  return i;
}

int solve(){
  ll left = 0;
  ll right = (ll) MAX * (ll) MAX;
  ll mid;
  while(right - left > 1){
    mid = (right + left) / 2;
    int v = check(mid);
    if(v >= weight_num) right = mid;
    else left = mid;
  }
  return right;
}

int main(){
  cin >> weight_num >> track_num;
  for(int i = 0; i < weight_num; i++) cin >> weight[i];
  ll ans = solve();
  cout << ans << endl;
}
