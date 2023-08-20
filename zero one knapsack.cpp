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
	int i=0;
	while(i<items){
		int value,weight;
		cout<<"Enter value for item "<<i+1<<": ";
		cin>>value;
		cout<<endl<<"enter weight for item "<<i+1<<": ";
		cin>>weight;
		entity* newentity = new entity(value,weight);
		list.push_back(*(newentity));
		i++;
	}
	sortVector(list);
	float totalWeight=0.00f,maximumProfit=0.00f,counter=0.00f;
	cout<<"maximum weight: ";
	for(int k=list.size();k>=0;k--){
		if(maximumCapacity>=list[k].weight){
		totalWeight += list[k].weight;
		maximumCapacity-=list[k].weight;
		maximumProfit+= list[k].value;
		counter++;
		}
        
	}
	cout<<totalWeight<<endl;
	
	cout<<"maximum profit: ";

	cout<<maximumProfit<<endl;
	
	return 0;
}
