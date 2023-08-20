#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

class entity{
	public:
	int value;
	int weight;
	float ratio;
	entity(int value,int weight){
		this->value=value;
		this->weight=weight;
		ratio =value/weight;
	}
};

void sortVector(vector<entity>list){
	int size=list.size();
	float arr[size-1];
	for(int i=0;i<size;i++){
		arr[i]=list[i].ratio;
	}
	sort(arr,arr+size);
	vector <entity> svec;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
		if(arr[j]==list[i].ratio){
		svec.push_back(list[j]);
		break;
			}	
		}
	}
	list=svec;
}

int main(){
	vector<entity>list;
	int items,maximumCapacity;
	cout<<"enter total number of element : ";
	cin>>items;
	cout<<"enter maximum capacity: ";
	cin>>maximumCapacity;
	int k=0;
	while(k<items){
		int value,weight;
		cout<<"Enter value for item "<<k+1<<": ";
		cin>>value;
		cout<<endl<<"enter weight for item "<<k+1<<": ";
		cin>>weight;
		entity* newentity = new entity(value,weight);
		list.push_back(*(newentity));
		k++;
	}
	sortVector(list);
	float profit=0.00f;
	int i = list.size();
	for(;i>=1;i--){
		if(maximumCapacity>0 && list[i].weight<=maximumCapacity){
			maximumCapacity-=list[i].weight;
			profit+=list[i].value;
		}
		else break;
			
	}
	if(maximumCapacity>0)
		profit+=(float)list[i].value*((float)maximumCapacity/list[i].weight);
	
	cout<<"maximum profit is: "<<profit;
	
	return 0;
}
