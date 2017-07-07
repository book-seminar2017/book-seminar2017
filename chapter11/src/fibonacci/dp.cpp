#include <iostream>
#define MAX_N 44
using namespace std;

int dp[MAX_N+1];
int fibonacci(int n) {
	if (dp[n] > 0) return dp[n];

	if (n < 2) {
		return dp[n] = 1;
	} else {
		return dp[n] = fibonacci(n-1) + fibonacci(n-2);
	}
}

int main() {
	int n;
	cin >> n;
	cout << fibonacci(n) << endl;
	return 0;
}
