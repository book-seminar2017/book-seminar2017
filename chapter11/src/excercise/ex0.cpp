#include <iostream>
#define MAX_N 20
#define MAX_SUM 40000
using namespace std;

int dp[MAX_N+1][MAX_SUM+1];
int a[MAX_N+1];
int n, q, m;

void solve(int n) {
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAX_SUM; j++) {
			/**
			 * ここの部分の実装を行う
			 */
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	solve(n);
	cin >> q;
	while (cin >> m) {
		if (dp[n][m]) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}
