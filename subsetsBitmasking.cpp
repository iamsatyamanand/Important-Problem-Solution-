//************************//
//**** SATYAM  ANAND *****//
//************************//

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums){
	int n = nums.size();
	int range = 1 << n;
	vector<vector<int>> ans(range);
	for(int i=0; i<range; i++){
		for(int j=0; j<n; j++){
			if(i&(1<<j))	ans[i].push_back(nums[n-1-j]);
		}
	}
	return ans;
}

int main(){
  vector<int> nums = {1, 2, 3, 4};
	vector<vector<int>> res = subsets(nums);
  for(auto &x : res){
    for(auto &y : x){
      cout << y << " ";
    }
    cout << "\n";
  }
	return 0;
}
