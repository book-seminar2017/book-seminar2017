#include <iostream>
#include <string.h>
using namespace std;
static const int N = 101;
static const int MAX_SUM = 10001;

int dp[N][MAX_SUM];
int p[N];
int n;

void solve() {
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAX_SUM; j++) {
			dp[i+1][j] |= dp[i][j];
			dp[i+1][j+p[i]] |= dp[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < MAX_SUM; i++) {
		ans += dp[n][i];
	}
	cout << ans << endl;
}

int is_correct(int n, int m) {
	/**
	 * ここに実装
	 */
}

void solve_recursive() {
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for (int i = 0; i < MAX_SUM; i++) {
		if (is_correct(n, i) > 0) {
			ans++;
		}
	}
	cout << ans << endl;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	// solve()
	solve_recursive();
	return 0;
}
