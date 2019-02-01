/* AC - bitmask and dp */
#include <iostream>
#include <cmath>
using namespace std;
int N, x[20], y[20], maxWord, cases;
double distances[20][20], dp[1<<16];

double solve(int word){
	if(word == maxWord) return 0;
	if(dp[word] != -1) return dp[word];

	double d = 1 << 30;
	for(int i=0; i<(2*N)-1; i++){
		if(! (word & (1<<i))){
			for(int j=i+1; j<2*N; j++){
				if( !(word & (1<<j))){
					d = min(d, distances[i][j] + solve((word|(1<<i)|(1<<j) )));
				}
			}
		}
	}
	return dp[word] = d;
}

int main(){
	cases = 0;
	while(cin >> N and N){
		for(int i=0; i<2*N; i++)
			scanf("%*s %d %d", &x[i], &y[i]);
		/* get all possible distances */
		for(int i=0; i<(2*N)-1; i++){
			for(int j=i+1; j<2*N; j++){
				distances[i][j] = distances[j][i] = hypot(x[i]-x[j], y[i]-y[j]);
			}
		}
		maxWord = (1 << (2*N))-1;
		for(int i=0; i<=maxWord; i++) dp[i] = -1;
		printf("Case %d: %.2lf\n", ++cases, solve(0));

	}

	return 0;
}