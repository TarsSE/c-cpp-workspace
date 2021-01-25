#include <iostream>
#include <vector>
using namespace std;

struct UFSet{
	vector<int> parent;
	int size;
	UFSet(int _size){
		size=_size;
		parent.resize(_size+1,-1);
	}
	int UFFind(int a){
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
	void UFUnion(int i,int j){
		if(i==j)return ;
		parent[i]+=parent[j];
		parent[j]=i;
	}
};

int main(){
	int n,m,mi,root,temp;
	scanf("%d %d",&n,&m);
	UFSet ufset(n);
	for(int i=0;i<m;i++){
		scanf("%d %d",&mi,&root);
		for(int j=0;j<mi-1;j++){
			scanf("%d",&temp);
			ufset.UFUnion(ufset.UFFind(root),ufset.UFFind(temp));
		}
	}
	int max=0;
	for(int i=1;i<=n;i++){
		if(max>ufset.parent[i]){
			max=ufset.parent[i];
		}
	}
	printf("%d",-max);
}
