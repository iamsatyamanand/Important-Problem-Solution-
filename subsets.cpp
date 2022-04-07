//************************//
//**** SATYAM  ANAND *****//
//************************//

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void generate(vector<int> &curr, int i, vector<int> &nums){
	if(i == nums.size()){
		ans.push_back(curr);
		return;
	}
	generate(curr, i+1, nums);
	curr.push_back(nums[i]);
	generate(curr, i+1, nums);
	curr.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums){
	vector<int> curr;
	generate(curr, 0, nums);
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
