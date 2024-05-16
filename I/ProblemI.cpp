#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
#define mp make_pair
const int MAXN = 3e3 + 2;
bool dp[MAXN][MAXN];
int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length();
    for(int i = n - 1 ; i >= 0; i--)
        for(int l = 1; i + l - 1 < n; l++) {
            int j = i + l - 1;
            if(l == 1)
                dp[i][l] = true;
            else if(l == 2)
                dp[i][l] = (s[i] == s[j]);
            else
                dp[i][l] = ((s[i]==s[j]) & dp[i+1][l-2]);
        }
    int m;
    cin >> m;
    bool ans[m];
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
		y--;
        if(dp[x][y - x + 1]) ans[i] = true;
        else ans[i] = false;
    }
    for (int i = 0; i < m; i++) {
    	if (ans[i]) cout << "Yes\n";
    	else cout << "No\n";
	}
    return 0;
}
