#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int n,m,s,e,cnt=0;
	scanf("%d %d",&n,&m);
	vector<int> v(n),pre(n+1);
	vector<vector<int> > graph(n+1);
	queue<int> q;
	for(int i=0;i<n+1;i++){
		graph[i].resize(n+1,0);
	}
	for(int i=0;i<m;i++){
		scanf("%d %d",&s,&e);
		graph[s][e]=1;
		graph[e][s]=1;
		v[s]++;
		v[e]++;
	}
	for(int i=0;i<n;i++){
		if(v[i]%2!=0){
			printf("0");
			return 0;
		}
	}
	q.push(1);
	pre[1]=++cnt;
	printf("0");
	return 0;
}
