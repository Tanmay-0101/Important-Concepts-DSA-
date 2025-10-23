class UnionFind{
	private: vector<int> par,rank;
	public:
		UnionFind(int n){
			par.assign(n,0);
			rank.assign(n,0);
			iota(par.begin(),par.end(),0) //fills increasing values starting from 0
		}

		int find_set(int x){
			return (par[x]==x ? x : par[x]=find_set(par[x]));
		}

		bool isEqualSet(int a,int b){
			return find_set(a)==find_set(b);
		}

		void unionSet(int u, int v){
			if(!isEqualSet(u,v)){
				int a=find_set(u),b=find_set(v);
				if(rank[a]<rank[b]){
					par[a]=b;
				}else{
					par[b]=a;
					if(rank[a]=rank[b]){
						rank[a]++;
					}
				}
			}
		}
}
