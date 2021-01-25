#include <iostream>
#include <vector>
using namespace std;

struct UFSet{
	vector<int> parent;
	int size;
	UFSet(int _size){
		size=_size;
		parent.resize(size+1,-1);
	}
	int UFFind(int a){
		if(a<1||a>size){
			return -1;
		}
		int j=a,i;
		while(parent[j]>0){
			j=parent[j];
		}
		while(a!=j){
			i=parent[a];
			parent[a]=j;
			a=i;
		}
		return j;
	}
	int UFUnion(int i,int j){//将j所在集合合并到i所在集合，以i所在集合命名 
		if(i==j){
			return -1;
		}
		parent[i]+=parent[j];
		parent[j]=i; 
		return 1;
	}
}; 

int main(){
	int n,q,operation,a,b,temp;
	scanf("%d %d",&n,&q);
	UFSet ufset(n);
	for(int i=0;i<q-1;i++){
		scanf("%d",&operation);
		switch(operation){
			case 1:
				scanf("%d %d",&a,&b);
				if(ufset.UFUnion(ufset.UFFind(b),ufset.UFFind(a))==-1){
					printf("ERROR\n");
				}
				break;
			case 2:
				scanf("%d",&a);
				temp=ufset.UFFind(a);
				printf("%d %d\n",temp,-(ufset.parent[temp]));
				break;
			default:
				break;
		}
	}
	scanf("%d",&operation);
		switch(operation){
			case 1:
				scanf("%d %d",&a,&b);
				if(ufset.UFUnion(ufset.UFFind(b),ufset.UFFind(a))==-1){
					printf("ERROR");
				}
				break;
			case 2:
				scanf("%d",&a);
				temp=ufset.UFFind(a);
				printf("%d %d",temp,-(ufset.parent[temp]));
				break;
			default:
				break;
		}
}
