#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
static const int PLAYERS = 1025;
static const int ROUND = 11;

double ratings[PLAYERS];
double p[PLAYERS][ROUND];
int n;

double win(int p1, int p2) {
	return 1.0 / (1.0 + pow(10, (ratings[p2] - ratings[p1])/400.0));
}

double wp(int i, int k) {
	if (p[i][k] > 0) return p[i][k];
	if (k == 0) return p[i][k] = 1.0;
	/**
	 * ここに，メモ化再帰でこの問題を解くときのコードを書く
	 */
	return p[i][k];
}

void solve_by_loop() {
	for (int i = 0; i < (int)pow(2.0, n); i++) {
		p[i][0] = 1.0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i < (int)pow(2.0, n); i++) {
			int index = i / (int)pow(2.0, k-1);
			int player;
			if (index % 2 == 0) {
				player = (index+1)*pow(2,k-1);
			} else {
				player = (index-1)*pow(2,k-1);
			}
			for (int j = 0; j < pow(2, k-1); j++) {
				p[i][k] += p[i][k-1]*win(i, player+j)*p[player+j][k-1];
			}
		}
	}
	for (int i = 0; i < pow(2, n); i++) {
		printf("%.10lf\n", p[i][n]);
	}
}
void solve() {
	for (int i = 0; i < (int)pow(2.0, n); i++) {
		printf("%.10lf\n", wp(i, n));
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < (int)pow(2.0, n); i++) {
		cin >> ratings[i];
	}
	//solve();
	solve_by_loop();
	return 0;
}
