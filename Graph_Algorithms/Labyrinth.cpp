#include <bits/stdc++.h>
using namespace std;
#define int long long

char grid[1000][1000];
bool vis[1000][1000];
int last[1000][1000];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
string step="URDL";
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	pair<int,int>a,b;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
			if(grid[i][j]=='A'){
				a={i,j};
			}
            else if(grid[i][j]=='B'){
				b={i,j};
			}
		}
	}
    queue<pair<int,int>>q;
	q.push(a);
	vis[a.first][a.second] = true;
    while(!q.empty()){
		pair<int,int>u=q.front();q.pop();
		for (int i=0;i<4;i++){
			pair<int,int>v={u.first+dx[i],u.second+dy[i]};
			if(v.first<0 or v.first>=n or v.second<0 or v.second>=m or grid[v.first][v.second]=='#' or vis[v.first][v.second]){
                continue;
            }
			vis[v.first][v.second]=1;
			last[v.first][v.second]=i;
			q.push(v);
		}
	}
	if(vis[b.first][b.second]){
		cout<<"YES\n";
		vector<int>steps;
		while(b!=a){
			int p=last[b.first][b.second];
			steps.push_back(p);
			b={b.first-dx[p],b.second-dy[p]};
		}
		reverse(steps.begin(), steps.end());
		cout<<steps.size()<<"\n";
		for(char c :steps) {
			cout<<step[c];
		}
	} 
    else{
		cout<<"NO\n";
	}
}