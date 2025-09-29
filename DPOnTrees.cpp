#include <bits/stdc++.h>
using namespace std;
//calculates the sum of distances of all the children from all the nodes as root
#define ll long long

void dfs(int curr,int par,vector<vector<ll>>& edges,vector<ll>& subSize,vector<ll>& depth){
	subSize[curr]=1;
	if(curr!=1) depth[curr]=depth[par]+1;
	for(ll neigh:edges[curr]){
		if(neigh!=par){
			dfs(neigh,curr,edges,subSize,depth);
			subSize[curr]+=subSize[neigh];
		}
	}
}

void dfs1(int curr,int par,vector<ll>& ans,vector<vector<ll>>& edges,vector<ll>& subSize){
	if(curr!=1){
		ans[curr]=ans[par]+(ans.size()-1)-2*subSize[curr];
	}
	for(ll neigh:edges[curr]){
		if(neigh!=par) dfs1(neigh,curr,ans,edges,subSize);
	}
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
	vector<ll> subSize(n+1);
	vector<ll> depth(n+1);
	dfs(1,0,edges,subSize,depth);
	vector<ll> ans(n+1);
	ll ansOne=0;
	for(int i=1;i<=n;i++){
		ansOne+=depth[i];
	}
	ans[1]=ansOne;
	dfs1(1,0,ans,edges,subSize);
	for(ll i=1;i<=n;i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
