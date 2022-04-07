//************************//
//**** SATYAM  ANAND *****//
//************************//

#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void generate(string &curr, int ct_open, int ct_close, int n){
	if(ct_open == n and ct_close == n){
		ans.push_back(curr);
		return;
	}
	if(ct_open < n){
		curr.push_back('(');
		generate(curr, ct_open+1, ct_close, n);
		curr.pop_back();
	}
	if(ct_close < n and ct_close < ct_open){
		curr.push_back(')');
		generate(curr, ct_open, ct_close+1, n);
		curr.pop_back();
	}
}

vector<string> generateParenthesis(int n){
	string curr = "";
	generate(curr, 0, 0, n);
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<string> res = generateParenthesis(n);
		for(auto &x : res){
			cout << x << "\n";
		}
	return 0;
}
