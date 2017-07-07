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
		/**
		 * ここにすぬけ君の手番のときの処理を書く
		 */
	} else {
		/**
		 * ここにすめけ君の手番のときの処理を書く
		 */
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
