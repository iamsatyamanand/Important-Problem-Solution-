//************************//
//**** SATYAM  ANAND *****//
//************************//

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &num, int low, int mid, int high){
	int left_size = mid-low+1;
	int right_size = high-mid;
	vector<int> left_num(left_size);
	vector<int> right_num(right_size);
	for(int i=0; i<left_size; i++){
		left_num[i] = num[i+low];
	}
	for(int i=0; i<right_size; i++){
		right_num[i] = num[i+mid+1];
	}
	int left_idx = 0, right_idx = 0;
	left_num.push_back(INT_MAX);
	right_num.push_back(INT_MAX);
	for(int i=low; i<=high; i++){
		if(left_num[left_idx] <= right_num[right_idx]){
			num[i] = left_num[left_idx++];
		}
		else{
			num[i] = right_num[right_idx++];
		}
	}
}

void merge_sort(vector<int> &num, int low, int high){
	if(low >= high)	return;
	int mid = (low+high) >> 1;
	merge_sort(num,low, mid);
	merge_sort(num, mid+1, high);
	merge(num, low, mid, high);
}

int main(){
	int n;
	cin >> n;
	vector<int> num(n);
	for(auto &x : num){
		cin >> x;
	}
	merge_sort(num, 0, n-1);
	for(auto &x : num){
		cout << x << " ";
	}
	return 0;
}
