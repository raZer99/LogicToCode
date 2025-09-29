// Header Files and namespaces
#include<bits/stdc++.h>
using namespace std;
// Code Shortners
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back #define MP make_pair
#define len(s) (int)s.size()
#define print(x) cout<<x<<'\n'
#define REP(i,a,b) for( int i = a; i <= b; i++)
#define all(a) (a).begin(), (a). end()
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll mod = 1000000007;
void dfs(vector<vector<char>> &map,vector<vector<int>> &vis,int i,int j,int n, int m){
    if(i<0 || j<0 || i>=n || j>=m || map[i][j] == '#' || vis[i][j] == 1){
        return;
    }

    vis[i][j] = 1;

    dfs(map,vis,i,j-1,n,m); //left
    dfs(map,vis,i,j+1,n,m); //right
    dfs(map,vis,i-1,j,n,m); //up
    dfs(map,vis,i+1,j,n,m); //down

    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> map(n, vector<char>(m));
    //storing into the map
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char val;
            cin>>val;
            map[i][j] = val;
        }
    }
    
    vector<vector<int>> vis(n, vector<int>(m, 0)); //boolean visited cnt 0->not vis 1->vis
    
    int res = 0;
    //iterating over the map using dfs
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] == 0 && map[i][j] == '.'){
                dfs(map,vis,i,j,n,m);
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}

  