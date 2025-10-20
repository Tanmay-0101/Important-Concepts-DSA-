int main(){
//a good question for remembering how to retrace the path produced by bfs by using parent array if path exists-> problem "message route" on CSES
	ll n,m;
	cin >> n >> m;
	vector<vector<ll>> graph(n+1);
	for(ll i=1;i<=m;i++){
		ll u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<ll> par(n+1,-1);
	vector<ll> dp(n+1,-1);
	queue<ll> q;
	q.push(1);
	dp[1]=0;
	while(!q.empty()){
		ll size=q.size(); 
		while(size--){
			ll curr=q.front();
			q.pop();
			for(ll neigh:graph[curr]){
				if(dp[neigh]==-1){
					par[neigh]=curr;
					q.push(neigh);
					dp[neigh]=dp[curr]+1;
				}
			}
		}
	}
	if(dp[n]==-1){
		cout << "IMPOSSIBLE" << endl;
	}else{
		vector<ll> path;
		cout << dp[n]+1 << endl;
		for(ll node=n;node!=-1;node=par[node]){
			path.push_back(node);
		}
		for(ll i=path.size()-1;i>=0;i--){
			cout << path[i] << " ";
		}
		cout << endl;
	}
}
