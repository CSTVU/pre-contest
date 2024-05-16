#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int list1[n];
	int i;
	for (i = 0; i < n; i++) {
		list1[i] = 1;
	}
	int count = 0;
	i = 0;
	int j = k;
	while (count < n - 1) {
		if (j == k) {
			cout << i + 1 << " ";
			list1[i] = 0;
			count++;
			j = 0;
		}
		i++;
		i = i % n;
		if (list1[i] == 1) {
			j++;
		}
	}
	return 0;
}

