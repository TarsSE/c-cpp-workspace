#include <iostream>
#include <malloc.h>
using namespace std;

struct UFSet{
	int size;
	int *parent;
	UFSet(int _size){
		size=_size;
		parent=(int *)malloc(sizeof(int)*(size+1));
		for(int i=0;i<=size;i++){
			parent[i]=-1;
		}
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
	int UFUnion(int a,int b){
		if(a==b){
			return -1;
		}
		parent[b]+=parent[a];
		parent[a]=b;
		return 1;
	}
	~UFSet(){
		free(parent);
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
				if(ufset.UFUnion(ufset.UFFind(a),ufset.UFFind(b))==-1){
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
				if(ufset.UFUnion(ufset.UFFind(a),ufset.UFFind(b))==-1){
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
