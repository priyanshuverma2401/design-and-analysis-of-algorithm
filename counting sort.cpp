//counting sort
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> countSort(vector<int> arr){
	int max=*max_element(arr.begin(),arr.end());
	int cnt[max+1]={0};
	vector<int> Sarr(arr.size());
	for(int i=0;i<=(arr.size()-1);i++){
		++cnt[arr[i]];
	}
	for(int i=1;i<=max;i++){
		cnt[i]=cnt[i]+cnt[i-1];
	}
	for(int i=(arr.size()-1);i>=0;i--){
		Sarr[--cnt[arr[i]]] = arr[i];
	}
	arr=Sarr;
	return arr;
}

int main(){
	vector<int>arr;
	int x;
	vector<int>::iterator itr;
	cout<<"\nEnter elements press 0 to end the list:"<<endl;
	while(true){
		cin>>x;
		if(x==0) break;
		arr.push_back(x);
	}
	cout<<"\nprinting unsorted arr: ";
	for(itr=arr.begin(); itr != arr.end(); itr++){
		cout<<*itr<<" ";
	}
	
	vector<int>sorted=countSort(arr);
	cout<<endl<<endl<<"Sorted array is: ";
	
	for(itr=sorted.begin(); itr != sorted.end(); itr++){
		cout<<*itr<<" ";
	}
	return 0;
}
