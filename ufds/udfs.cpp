/* 
    Applications:
        - connected components in a graph
        - detect cycle in a undirected graph -> there is a cycle if x and y are in the same set
    


*/
int p[MAX], r[MAX], N, M, num_sets;
void init(){
    num_sets = N; /* to get the number of sets in the graph */
    for(int i=1; i<=N; i++){p[i]=i; r[i] = 0;}
}

int find(int i){return (i == p[i]) ? i : (p[i] = find(p[i]));} /* with path compression*/

void unionSet(int i, int j){
    int x = find(i), y = find(j);
    if(x != y){
        num_sets--;
        if(r[x] > r[y]){
            p[y] = x; 
        }else{
            p[x] = y;
            if(r[x] == r[y])r[y]++;
        }
    }
}
