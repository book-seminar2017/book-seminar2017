#include <iostream>
#define MAX_N 44
using namespace std;

int dp[MAX_N+1];

int fibonacci(int n) {
	if (n < 2) {
		return 1;
	} else {
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << fibonacci(n) << endl;
	return 0;
}
