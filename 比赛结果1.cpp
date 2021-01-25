#include <iostream>
#include <vector>
using namespace std;

struct Graph{
	int dotNum;
	vector<vector<char> > graph;
	Graph(int _dotNum){
		dotNum=_dotNum;
		graph.resize(dotNum+1);
		for(int i=0;i<=dotNum;i++){
			graph[i].resize(dotNum+1,0);
		}
	}
	bool addLine(int i,int j){
		if(graph[i][j]==0){
			graph[i][j]=1;
			return true;
		}
		return false;
	}
}; 

int main(){
	int n,m,a,b,i,j,cnt=0;
	scanf("%d %d",&n,&m);
	Graph graph(n);
	vector<int> in(n+1,0);
	for(i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		if(graph.addLine(a,b)){
			in[b]++;
		}
	}
	while(cnt<n){
		for(i=1;i<=n;i++){
			if(in[i]==0){
				cnt++;
				if(cnt==1){
					printf("%d",i);
				}else{
					printf(" %d",i);
				}
				in[i]=-1;
				for(j=1;j<=n;j++){
					if(graph.graph[i][j]!=0){
//						graph.graph[j][i]=0;
						in[j]--;
					}
				}
				break;
			}
		}
	}
}
