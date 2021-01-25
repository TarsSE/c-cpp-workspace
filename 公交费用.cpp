#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Weight{
	int c,t;
	Weight(int _c=-1,int _t=-1){
		c=_c;
		t=_t;
	}
	bool isNoEdge()const{
		return t==-1&&c==-1;
	}
	bool operator<(const Weight& right){
		if(this->isNoEdge()){
			return false;
		}else if(!this->isNoEdge()&&right.isNoEdge()){
			return true;
		}
		if(c<right.c){
			return true;
		}else if(c==right.c){
			if(t<right.t){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}
	Weight operator+(const Weight& right){
		Weight w;
		w.c=c+right.c;
		w.t=t+right.t;
		return w;
	}
};

struct Dot{
	Weight dist;
	bool isUsed;
	int pre;
	Dot(){
		dist.c=-1;
		dist.t=-1;
		isUsed=false;
		pre=0;
	}
};

struct Graph{
	int dotNum;
	vector<vector<Weight> > graph;
	Graph(int _dotNum){
		dotNum=_dotNum;
		graph.resize(dotNum+1);
		for(int i=0;i<=dotNum;i++){
			graph[i].resize(dotNum+1);
		}
	}
	void addLine(int i,int j,int c,int t){
		Weight w(c,t);
		if(graph[i][j].isNoEdge()){
			graph[i][j]=w;
			graph[j][i]=w;
		}else{
			if(w<graph[i][j]){
				graph[i][j]=w;
				graph[j][i]=w;
			}
		}
	}
};

int main(){
	int n,m,a,b,c,t;
	scanf("%d %d",&n,&m);
	Graph pic(n);
	for(int i=0;i<m;i++){
		scanf("%d %d %d %d",&a,&b,&c,&t);
		pic.addLine(a,b,c,t);
	}
	vector<Dot> dot(n+1);
//	for(int i=1;i<=n;i++){
//		if(!(pic.graph[1][i].isNoEdge())){
//			dot[i].isUsed=true;
//			dot[i].dist=pic.graph[1][i];
//			dot[i].pre=1;
//		}
//	}
	dot[1].dist.c=0;
	dot[1].dist.t=0;
	while(1){
		Weight min;
		int v=0;
		for(int i=1;i<=n;i++){
			if(dot[i].isUsed==false&&dot[i].dist<min){
				min=dot[i].dist;
				v=i;
			}
		}
		if(v==0){
			break;
		}
		for(int i=1;i<=n;i++){
			if((!dot[i].isUsed)&&(!pic.graph[v][i].isNoEdge())){
				if(dot[v].dist+pic.graph[v][i]<dot[i].dist){
					dot[i].dist=dot[v].dist+pic.graph[v][i];
					dot[i].pre=v;
				}
			}
		}
		dot[v].isUsed=true;
	}
	if(dot[n].isUsed){
		printf("%d %d",dot[n].dist.c,dot[n].dist.t);
	}else{
		printf("-1");
	}
}
