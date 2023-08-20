//job sequencing problem
#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

class entity{
	public:
	string name;
	int jobid;
	int profit;
	int deadline;
	
	entity(int jobid,int profit,int deadline,string name){
		this->jobid=jobid;
		this->profit=profit;
		this->deadline=deadline;
		this->name =name;
		
	}
};

void sortVector(vector<entity>list){
	int size=list.size();
	float arr[size];
	for(int i=0;i<size;i++){
		arr[i]=list[i].profit;
	}
	sort(arr,arr+(size-1));
	vector <entity> svec;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
		if(arr[j]==list[i].profit){
		svec.push_back(list[j]);
		break;
			}	
		}
	}
	list=svec;
}

int findMax(vector<entity>list){
	int max=list[0].deadline;
	for(int i=1;i<list.size();i++){
		if(max<list[i].deadline)
		 max=list[i].deadline;
	}
	return max;
}

int main(){
	vector<entity>list;
	int jobs;
	cout<<"enter total number of jobs : ";
	cin>>jobs;
	
	int i=0;
	while(i<jobs){
		int profit,deadline;
		string name;
		cout<<"Enter profit for item "<<i+1<<": ";
		cin>>profit;
		cout<<"enter deadline for item "<<i+1<<": ";
		cin>>deadline;
		cout<<"Enter job name: ";
		cin>>name;
		entity* newentity = new entity(i+1,profit,deadline,name);
		list.push_back(*(newentity));
		i++;
		cout<<endl;
	}
	sortVector(list);
	int max = findMax(list);
	int arr[max];
	for(int g=0;g<max;g++){
		arr[g]=-1;				//initialized with -1
	}
	for(int c=(list.size()-1);c>=0;c--){
		if(arr[list[c].deadline]==-1)
		arr[list[c].deadline]=list[c].jobid;
		else{
			int m=list[c].deadline;
			while(arr[m]!=-1){
				m--;
			}
			arr[m]=list[c].jobid;
		}
	}
	
	
	
	//printing sequence
	for(int g=0;g<max;g++){
		//cout<<arr[g]+1<<" ";
		for(int h=0;h<list.size();h++){
			if(arr[g]==list[h].jobid){
			 cout<<list[h].name<<" ";
			 break;
			}
		}
	}
	
	return 0;
}
