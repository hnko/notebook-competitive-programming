/*
	Application: dynamic range queries
	Observations:
		build takes O(k log N) k is the number of adjust
			but it can be done in O(N) with:
			build(){
				for(int i=1; i<=N; i++){
					int j= i + LSB(i);
					if(j <=N) tree[j] += tree[i];
				}
			}
*/

class Fenwick{
private: 
	vector<int> tree;
	int LSB(int i){return i&(-i);}
public:
	Fenwick(int n){ tree.assign(n+1, 0);}
	
	int query(int i){ /* O(log N) */
		if( i == 0) return 0;
		int sum = 0;
		for(; i ; i -= LSB(i)) sum += tree[i];
		return sum;
	}
	int query(int i, int j){ return query(j) - query(i-1);}

	void adjust(int i, int value){
		for(; i<tree.size(); i+=LSB(i)) tree[i] += value;
	}
};