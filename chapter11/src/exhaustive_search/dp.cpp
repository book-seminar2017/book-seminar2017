#include <iostream>
#include <string.h>
#define MAX_N 20
#define MAX_SUM 40000

using namespace std;

bool dp[MAX_N+1][MAX_SUM+1];
bool checked[MAX_N+1][MAX_SUM+1];
int a[MAX_N];

bool solve(int n, int m) {
  if (checked[n][m]) {
    return dp[n][m];
  }

  if (m == 0) {
    return true;
  } else {
    if (n == 0) {
      return false;
    }
  }
  checked[n][m] = true;
  return dp[n][m] = solve(n-1, m) || solve(n-1, m - a[n-1]);
}

int main() {
  int n, q, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> q;
  memset(dp, 0, sizeof(dp));
  memset(checked, 0, sizeof(checked));
  int input;
  for (int i = 0; i < q; i++) {
    cin >> input;
    if (solve(n, input)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
