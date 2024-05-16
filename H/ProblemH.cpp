#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
 
long long ans, a[N];
stack<int > st, st2;
int n, p[N], p2[N];
void input() {
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
 
void solve() {
	for (int i = 0; i < n; i++) {
		while (! st2.empty() && a[st2.top()] >= a[n - i - 1])
			st2.pop();
		while (! st.empty() && a[st.top()] >= a[i]) 
			st.pop();
		p2[n - i - 1] = ! st2.empty()? st2.top(): n;
		p[i] = ! st.empty()? st.top(): -1;
		st2.push(n - i - 1);
		st.push(i);
	}
	for (int i = 0; i < n; i++) {
		if ((p2[i] - p[i] - 1) * a[i] > ans)
			ans = (p2[i] - p[i] - 1) * a[i];
	}
}
 
void output() {
	cout << ans << endl;
}
 
void clear() {
	ans = 0; 
	while (! st.empty())
		st.pop();
	while (! st2.empty())
		st2.pop();
}
 
int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	input(), solve(), output(), clear();
	return 0;
}
