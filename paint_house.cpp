#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << "-> " << x << "\n";

const int M = 1e9+7;

int dp[10010][3];

int minCost(int house, int color, int n, vector<vector<int>> &cost){
	if(house == n)	return 0;
	if(dp[house][color] != -1)	return dp[house][color];
	int ans = 1e9;
	for(int i=0; i<3; i++){
		if(i != color){
			ans = min(ans, cost[house][color] + minCost(house+1, i, n, cost));
		}
	}
	return dp[house][color] = ans;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vector<int>> cost(n, vector<int>(3));
		for(int i=0; i<n; i++){
			for(int j=0; j<3; j++){
				cin >> cost[i][j];
			}
		}
		int ans = 1e9;
		memset(dp, -1, sizeof(dp));
		for(int i=0; i<3; i++){
			ans = min(ans, minCost(0, i, n, cost));
		}
		cout << ans << "\n";
	}
	return 0;
}
