#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
 
#define mp make_pair
#define pb push_back
#define in insert
#define ers erase
#define S second
#define F first

const int N = 20;
int n, m, q;
bool noWall[N][N][4];
bool vis[N][N];

void read_input() {
   cin >> n >> m >> q;
}

void dfs(int r, int c) {
   vis[r][c] = 1;
   
   if (noWall[r][c][0] && !vis[r - 1][c])
      dfs(r - 1, c);
   
   if (noWall[r][c][1] && !vis[r][c + 1])
      dfs(r, c + 1);
      
   if (noWall[r][c][2] && !vis[r + 1][c])
      dfs(r + 1, c);
      
   if (noWall[r][c][3] && !vis[r][c - 1])
      dfs(r, c - 1);

}

void make_walls() {
    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < m - 1; j++) {
             // up
             noWall[i][j][0] = 1;
             noWall[i - 1][j][2] = 1;
             
             // right
             noWall[i][j][1] = 1;
             noWall[i][j + 1][3] = 1;
             
             // down
             noWall[i][j][2] = 1;
             noWall[i + 1][j][0] = 1;
             
             // left 
             noWall[i][j][3] = 1;
             noWall[i][j - 1][1] = 1;
        }
        
    for (int j = 0; j < m - 1; j++) {
        noWall[0][j][1] = 1;
        noWall[0][j + 1][3] = 1;
        
        noWall[n - 1][j][1] = 1;
        noWall[n - 1][j + 1][3] = 1;
    }
    
    for (int i = 0; i < n - 1; i++) {
        noWall[i][0][2] = 1;
        noWall[i + 1][0][0] = 1;
        
        noWall[i][m - 1][2] = 1;
        noWall[i + 1][m - 1][0] = 1;
    }
}

void write_output() {
    make_walls();
 
   while(q--) {
      string s;
      int r, c;
      cin >> s >> r >> c;
      r--, c--;
      
      if (s[0] == 'u') {
         noWall[r][c][0] = 0;
         noWall[r - 1][c][2] = 0;
      }
      
      else if (s[0] == 'r') {
         noWall[r][c][1] = 0;
         noWall[r][c + 1][3] = 0;
      }
      
      else if (s[0] == 'd') {
         noWall[r][c][2] = 0;
         noWall[r + 1][c][0] = 0;
      }
      
      else {
         noWall[r][c][3] = 0;
         noWall[r][c - 1][1] = 0;
      }
      
      for (int i = 0; i < n; i++)
         for (int j = 0; j < m; j++)
            vis[i][j] = 0;
            
      int ans = 0;
      
      for (int i = 0; i < n; i++)
         for (int j = 0; j < m; j++)
            if (!vis[i][j]) {
               dfs(i, j);
               ans++;
            }
            
      cout << ans << '\n';
   }
}

int main() {
   read_input();
   write_output();
}
