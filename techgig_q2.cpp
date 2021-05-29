/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int prime(int l, int r){
	bool pr[r+1] = {0};
	
	for(int i = 2; i<=r; i++){
		if(!pr[i]){
			for(int j = i*i; j<=r; j+=i)
				pr[j] = 1;
		}
	}

	bool f = 0;
	int mx = INT_MIN, mn = INT_MAX;
	for(int i = l; i<=r; i++){
		if(!pr[i]){
			mx = max(i,mx);
			mn = min(i, mn);
			f = 1;
		}
	}

	if(!f)
		return -1;
	else if(mx == mn)
		return 0;
	else
		return mx - mn;
}
int main()
{
	//Write code here
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;

		int res = prime(l, r);
		cout<<res<<endl;
	}
	return 0;
}
