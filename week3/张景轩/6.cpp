#include<bits/stdc++.h>
using namespace std;
int check(int n){
	while(n){
		int t = n % 10;
		n = n / 10;
		if(t == 2 || t == 0 || t == 1 || t == 9)
			return 1;
	}
	return 0;
}
int main(){
	int n;
	int sum = 0;
	cin>>n;
	for(int i = 1; i <= n; i++){
		if(check(i)){
			sum += i;
		}
	}
	cout<<sum<<endl;
	return 0;
}