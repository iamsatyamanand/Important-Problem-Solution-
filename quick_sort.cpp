//************************//
//**** SATYAM  ANAND *****//
//************************//

#include<bits/stdc++.h>
using namespace std;

int quick(vector<int> &num, int low, int high){
	int pivot = num[high];
	int i = low;
	for(int j=low; j<high; j++){
		if(num[j] < pivot){
			swap(num[j], num[i++]);
		}
	}
	swap(num[i], num[high]);
	return i;
}

void quick_sort(vector<int> &num, int low, int high){
	if(low >= high)	return;
	int p = quick(num, low, high);
	quick_sort(num, low, p-1);
	quick_sort(num, p+1, high);
}

int main(){
	int n;
	cin >> n;
	vector<int> num(n);
	for(auto &x : num){
		cin >> x;
	}
	quick_sort(num, 0, n-1);
	for(auto &x : num){
		cout << x << " ";
	}
	return 0;
}
