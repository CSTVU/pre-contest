#include<bits/stdc++.h>
using namespace std;
 
const int N = 5e5 + 10;
 
int n, a[N];
long long ans, sum[N];
 
int main() {
    ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum[i] += a[i] + sum[max(0, i - 1)];
	if (sum[n - 1] % 3)
		return cout << 0, 0;
	for (int i = 0, cnt = 0; i < n - 1; i++) {
		if (sum[i] == 2 * sum[n - 1] / 3)
			ans += cnt;
		if (sum[i] == sum[n - 1] / 3)
			cnt++;
	}
	cout << ans;
}
