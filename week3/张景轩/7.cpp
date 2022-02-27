#include<bits/stdc++.h>
using namespace std;
int Ai[100005];
int main(){
	int N;
	int deep = 1; //深度 
	int sum = 0; //每行的和 
	long long max_sum = -100000000000; //最大的和 
	int max_deep = 1;
	cin>>N;
	for(int i = 1; i <= N; ++i){
		cin>>Ai[i];
		sum += Ai[i];
		if(i == pow(2, deep) - 1){
			if(max_sum < sum){ //注意不要取等号，因为题目要最小的深度 
				max_deep = deep;
				max_sum = sum;
			}
			sum = 0;
			++deep;
		}
	}
	cout<<max_deep<<endl;
	return 0;
}