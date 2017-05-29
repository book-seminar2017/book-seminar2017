#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

static const int N = 100;
int mcm[N+1][N+1], p[N+1];

int calc_mcm(int i, int j) {
	if(mcm[i][j] >= 0) {
		return mcm[i][j];
	}
	if(i == j) {
		return mcm[i][j] = 0;
	}else {
		int ans = INT_MAX;
		for (int k = i; k < j; k++) {
			ans = min(ans, calc_mcm(i, k) + calc_mcm(k+1, j) + p[i-1] * p[k] * p[j]);
		}
		return mcm[i][j] = ans;
	}
}

void solve() {
	int n, row, col, i;
	cin >> n;
	i = 0;
	while (++i <= n) {
		cin >> row >> col;
		p[i-1] = row;
		p[i] = col;
	}
	memset(mcm, -1, sizeof(mcm));
	cout << calc_mcm(1, n) << endl;
}


int main() {
	solve();
	return 0;
}
