#include <iostream>
#include <vector>
using namespace std;

struct Graph{
	vector<vector<int> > graph;
	int dotNum;
	Graph(int _dotNum){
		dotNum=_dotNum;
		graph.resize(dotNum+1);
		for(int i=0;i<=dotNum;i++){
			graph[i].resize(dotNum+1,-1);
		}
		for(int i=1;i<=dotNum;i++){
			graph[i][i]=0;
		}
	}
	void addLine(int i,int j,int w){
		graph[i][j]=w;
		graph[j][i]=w;
	}
};

int main(){
	int n,m,temps,tempe,tempw;
	scanf("%d %d",&n,&m);
	Graph p(n);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&temps,&tempe,&tempw);
		p.addLine(temps,tempe,tempw);
	}
	for(int k=1;k<=p.dotNum;k++){
		for(int i=1;i<=p.dotNum;i++){
			for(int j=1;j<=p.dotNum;j++){
				if((p.graph[i][k]!=-1&&p.graph[k][j]!=-1)&&(p.graph[i][j]==-1||p.graph[i][j]>p.graph[i][k]+p.graph[k][j])){
					p.graph[i][j]=p.graph[i][k]+p.graph[k][j];
				}
			}
		}
	}
	for(int i=1;i<=p.dotNum;i++){
		for(int j=1;j<=p.dotNum;j++){
			if(p.graph[i][j]==-1){
				p.graph[i][0]=0;
				break;
			}
			if(p.graph[i][0]<p.graph[i][j]){
				p.graph[i][0]=p.graph[i][j];
			}
		}
	}
	vector<int> l,dot;
	int num=0;
	for(int i=1;i<=p.dotNum;i++){
		if(p.graph[i][0]!=0){
			l.push_back(p.graph[i][0]);
			dot.push_back(i);
			num++;
		}
	}
	if(num!=0){
		int minl=l[0],minDot=dot[0];
		for(int i=0;i<num;i++){
			if(minl>l[i]){
				minl=l[i];
				minDot=dot[i];
			}
		}
		printf("%d %d",minDot,minl); 
	}else{
		printf("0");
	}
}
