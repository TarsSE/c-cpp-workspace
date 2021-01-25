#include <iostream>
#include <vector>
using namespace std;

struct UFSet{
	vector<int> parent,root;
	int size;
	UFSet(int _size){
		size=_size;
		parent.resize(size+1,1);
		root.resize(size+1,1);
	}
	int UFFind(int a){
		int j=a,i;
		while(root[j]<1){
			j=parent[j];
		}
		while(a!=j){
			i=parent[a];
			parent[a]=j;
			a=i;
		}
		return j;
	}
	int UFUnion(int a,int b){
		if(a==b){
			return -1;
		}
		root[a]+=root[b];
		root[b]=0;
		parent[b]=a;
		return 1;
	}
};

int main(){
	int n,q,a,b,operation,temp;
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
				printf("%d %d\n",temp,ufset.root[temp]);
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
				printf("%d %d",temp,ufset.root[temp]);
				break;
			default:
				break;
		}
}
