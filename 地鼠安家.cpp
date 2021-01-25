#include <iostream>
#include <vector>
using namespace std;

struct House{
	int up,left,right;
	House(){
		up=-1;
		left=-1;
		right=-1;
	}
};

void throughBSTree(vector<House> &house,int root,vector<int> &rats);
int getBSTreeDepth(vector<House> &house,int root);

int main(){
	int num,root=-1;
	cin>>num;
	vector<House> house(num+1);
	vector<int> rats;
	int mid,left,right;
	for(int i=0;i<num;i++){
		cin>>left>>mid>>right;
		if(left>num||right>num||mid>num||left==mid||mid==right||(right==left&&left!=-1)){
			cout<<-1;
			return 0;
		}
		house[mid].left=left;
		house[mid].right=right;
		if(left!=-1){
			if(house[left].up==-1){
				house[left].up=mid;
			}else{
				cout<<-1;
				return 0;
			}
		}
		if(right!=-1){
			if(house[right].up==-1){
				house[right].up=mid;
			}else{
				cout<<-1;
				return 0;
			}
		}
	}
	for(int i=1;i<=num;i++){
		if(house[i].up==-1){
			root=i;
			break;
		}
	}
	if(root==-1){
		cout<<-1;
		return 0;
	}
	throughBSTree(house,root,rats);
	if(rats.size()==num){
		for(int i=0;i<num;i++){
			if(rats[i]!=i+1){
				cout<<-1;
				return 0;
			}
		}
	}else{
		cout<<-1;
		return 0;
	}
	cout<<getBSTreeDepth(house,root);
}

void throughBSTree(vector<House> &house,int root,vector<int> &rats){
	if(house[root].left!=-1){
		throughBSTree(house,house[root].left,rats);
	}
	rats.push_back(root);
	if(house[root].right!=-1){
		throughBSTree(house,house[root].right,rats);
	}
}

int getBSTreeDepth(vector<House> &house,int root){
	if(house[root].left==-1&&house[root].right==-1){
		return 1;
	}
	int left=0,right=0;
	if(house[root].left!=-1){
		left=getBSTreeDepth(house,house[root].left);
	}
	if(house[root].right!=-1){
		right=getBSTreeDepth(house,house[root].right);
	}
	return left>right?left+1:right+1;
}

