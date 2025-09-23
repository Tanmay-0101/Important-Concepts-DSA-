#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N=2e5+1,M=20;//M=logN
ll P[N][M];

void dfs(vector<vector<ll>>& edges,vector<ll>& depth,ll curr,ll par){
	depth[curr]=depth[par]+1;
	P[curr][0]=par;
	for(ll i=1;i<M;i++){
		P[curr][i]=P[P[curr][i-1]][i-1];
	}
	for(ll neigh:edges[curr]){
		if(neigh!=par){
			dfs(edges,depth,neigh,curr);
		}
	}
}

ll LCA(ll a,ll b,vector<ll>& depth){
	if(a==b) return a;
	if(depth[a]<depth[b]) swap(a,b);

	ll diff=depth[a]-depth[b];
	//shift b diff times upwards
	for(ll i=0;i<M;i++){
		if((1<<i)&diff) a=P[a][i];
	}

	for(ll i=M-1;i>=0;i--){
		if(P[a][i]!=P[b][i]){
			a=P[a][i];
			b=P[b][i];
		}
	}

	return (a!=b ? P[a][0] : a);//edge case handling: when after lifting both nodes become same
}
