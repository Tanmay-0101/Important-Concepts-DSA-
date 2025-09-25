#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N=2e5+1,M=20;
pair<ll,ll> P[N][M];

void dfs(vector<vector<ll>>& edges,vector<ll>& depth,ll curr,ll par,vector<ll>& arr){
	depth[curr]=depth[par]+1;
	P[curr][0]={par,min(arr[curr],arr[par])};
	for(ll i=1;i<M;i++){
		P[curr][i]={P[P[curr][i-1].first][i-1].first,
					min(P[curr][i-1].second,P[P[curr][i-1].first][i-1].second)};
	}
	for(ll neigh:edges[curr]){
		if(neigh!=par){
			dfs(edges,depth,neigh,curr,arr);
		}
	}
}

ll minVal(ll a,ll b,vector<ll>& depth,vector<ll>& arr){
	if(a==b) return a;
	if(depth[a]<depth[b]) swap(a,b);

	ll diff=depth[a]-depth[b];
	ll Mn=min(arr[a],arr[b]);
	//shift b diff times upwards
	for(ll i=0;i<M;i++){
		if((1<<i)&diff){
			a=P[a][i].first;
			Mn=min(Mn,P[a][i].second);
		}
	}

	for(ll i=M-1;i>=0;i--){
		if(P[a][i].first!=P[b][i].first){
			Mn=min({Mn,P[a][i].second,P[b][i].second});
			a=P[a][i].first;
			b=P[b][i].first;
		}
	}

	return (a!=b ? min(Mn,P[a][0].second) : Mn);//edge case handling: when after lifting both nodes become same
}

int main(){
	ll n,q;
	cin >> n >> q;
	vector<ll> arr(n+1);
	for(ll i=1;i<=n;i++){
		cin >> arr[i];
	}
	vector<vector<ll>> edges(n+1);
	for(ll i=2;i<=n;i++){
		ll p;
		cin >> p;
		edges[p].push_back(i);
	}
	for(ll i=0;i<M;i++){
		P[0][i]={0,INT_MAX};
	}
	vector<ll> depth(n+1);
	dfs(edges,depth,1,1,arr);
	for(ll i=0;i<q;i++){
		ll a,b;
		cin >> a >> b;
		ll mini=minVal(a,b,depth,arr);
		cout << mini << endl;
	}
	return 0;
}
