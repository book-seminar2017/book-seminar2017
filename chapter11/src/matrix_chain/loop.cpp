#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

static const int N = 100;
int mcm[N+1][N+1], p[N+1];

void calc_mcm(int n) {
	for (int i = 1; i <= n; i++) {
		mcm[i][i] = 0;
	}
	for (int num_matrix = 2; num_matrix <= n; num_matrix++) {
		for (int i = 1; i <= n - num_matrix + 1; i++) {
			int j = i + num_matrix - 1;
			mcm[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				mcm[i][j] = min(mcm[i][j], mcm[i][k] + mcm[k+1][j] + p[i-1] * p[k] * p[j]);
			}
		}
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
	calc_mcm(n);
	cout << mcm[1][n] << endl;
}


int main() {
	solve();
	return 0;
}
