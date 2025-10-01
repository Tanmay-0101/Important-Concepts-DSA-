#include <bits/stdc++.h>
using namespace std;

//to count the number of distinct colors in the subtree of each node
#define ll long long

void dfs(ll curr,ll par,vector<vector<ll>>& edges,vector<ll>& ans,vector<set<ll>>& s){
	for(ll neigh:edges[curr]){
		if(neigh!=par){
			dfs(neigh,curr,edges,ans,s);
			if(s[neigh].size()>s[curr].size()) swap(s[neigh],s[curr]);
			for(auto &e:s[neigh]){
				s[curr].insert(e);
			}
		}
	}
	ans[curr]=s[curr].size();
}

int main(){
	ll n;
	cin >> n;
	vector<ll> c(n+1);
	for(ll i=1;i<=n;i++){
		cin >> c[i];
	}
	vector<vector<ll>> edges(n+1);
	for(ll i=2;i<=n;i++){
		ll u,v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<ll> ans(n+1);
	vector<set<ll>> s(n+1);
	for(ll i=1;i<=n;i++){
		s[i].insert(c[i]);
	}
	dfs(1,0,edges,ans,s);
	for(ll i=1;i<=n;i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}
