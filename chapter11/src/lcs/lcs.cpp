#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define SIZE 1000

int c[SIZE+1][SIZE+1];

void lcs(string str_x, string str_y) {
	for (int i = 1; i <= str_x.length(); i++) {
		for (int j = 1; j <= str_y.length(); j++) {
			if (str_x[i-1] == str_y[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
			} else {
				c[i][j] = max(c[i][j-1], c[i-1][j]);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	string str_x, str_y;
	while (cin >> str_x >> str_y) {
		lcs(str_x, str_y);
		cout << c[str_x.length()][str_y.length()] << endl;
		memset(c, 0, sizeof(c));
	}
	return 0;
}
