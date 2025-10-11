#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> bfs(ll n, vector<vector<ll>>& edges){
	queue<ll> q;
	vector<bool> vis(n+1);
	vector<ll> ans;
	ans.push_back(0);
	vis[1]=true;
	q.push(1);
	while(!q.empty()){
		ll curr=q.front();
		q.pop();
		ans.push_back(curr);
		for(ll neigh:edges[curr]){
			if(!vis[neigh]){
				q.push(neigh);
				vis[neigh]=true;
			}
		}
	}
	return ans;
}

int main(){
	ll n;
	cin >> n;
	vector<vector<ll>> edges(n+1);
	for(ll i=2;i<=n;i++){
		ll u,v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<ll> order(n+1);
	for(ll i=1;i<=n;i++){
		cin >> order[i];
	}
	vector<ll> idx(n+1);
	for(ll i=1;i<=n;i++){
		idx[order[i]]=i;
	}

	for(int i=1;i<=n;i++){
		if(edges[i].size()==0) continue;
		sort(edges[i].begin(),edges[i].end(),[&](ll a, ll b)
			{ return idx[a]<idx[b]; } );
	}

	if(bfs(n,edges)==order){
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}
}
