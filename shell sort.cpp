//shell sort imlementation
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> shell(vector<int> arr){
	int gap= int(arr.size()/2);
	for(;gap>=1;gap/=2){
	for(int j=gap;j< arr.size();j++){
		for(int i=j-gap;i>=0;i-=gap){
			if(arr[i+gap]>arr[i]) break;
			swap(arr[i+gap],arr[i]);
		
		}
		
	}
	
}	
	return arr;
}

int main(){
	vector<int>arr;
	int x;
	cout<<"\nEnter the elments: "<<endl;
	while(true){
		cin>>x;
		if(x==0) break;
		else arr.push_back(x);
	}

	
	vector<int>sorted=shell(arr);
	vector<int>::iterator itr;
	
	for(itr = sorted.begin();itr != sorted.end();itr++){
		cout<<*itr<<"  ";
	}
	
	return 0;
}
