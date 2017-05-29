#include <iostream>
#include <string.h>
using namespace std;

static const int CARD_MAX = 1001;

int dp[CARD_MAX][CARD_MAX];
int deck_a[CARD_MAX], deck_b[CARD_MAX];
int a, b;

int game(int i, int j) {
	if (i + j == 0) {
		return 0;
	}
	if (~dp[i][j]) {
		return dp[i][j];
	}

	if (1 - ((a + b) - (i + j)) % 2) {
		if (i > 0 && j > 0) {
			return dp[i][j] = max(game(i-1, j) + deck_a[i],
								  game(i, j-1) + deck_b[j]);
		} else if (i > 0){
			return dp[i][j] = game(i-1, j) + deck_a[i];
		} else {
			return dp[i][j] = game(i, j-1) + deck_b[j];
		}
	} else {
		if (i > 0 && j > 0) {
			return dp[i][j] = min(game(i-1, j), game(i, j-1));
		} else if (i > 0){
			return dp[i][j] = game(i-1, j);
		} else {
			return dp[i][j] = game(i, j-1);
		}
	}
}

int main() {
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> deck_a[a - i];
	}
	for (int i = 0; i < b; i++) {
		cin >> deck_b[b - i];
	}
	memset(dp, -1, sizeof(dp));
	cout << game(a, b) << endl;
	return 0;
}
