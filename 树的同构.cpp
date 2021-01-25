#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

struct Graph{
	vector<vector<int> > graph;
	int dotNum;
	Graph(int _dotNum=26){
		dotNum=_dotNum;
		graph.resize(_dotNum);
		for(int i=0;i<dotNum;i++){
			graph[i].resize(dotNum,0);
		}
	}
	void addLine(int i,int j){
		graph[i][j]=1;
		graph[j][i]=1;
	}
	bool operator==(const Graph& right){
		if(dotNum!=right.dotNum){
			return false;
		}
		for(int i=0;i<dotNum;i++){
			for(int j=0;j<dotNum;j++){
				if(graph[i][j]!=right.graph[i][j]){
					return false;
				}
			}
		}
		return true;
	}
};
struct Dot{
	char alpha;
	int leftSon,rightSon;
	Dot(){
		leftSon=-1;
		rightSon=-1;
	}
};

int main(){
	int num,parent,tempDot;
	char alph,leftSon,rightSon;
	scanf("%d",&num);
	getchar();
	Graph p1;
	vector<Dot> d1(num);
	for(int i=0;i<num;i++){
		scanf("%c %c %c",&alph,&leftSon,&rightSon);
		d1[i].alpha=alph;
		getchar();
		if(isdigit(leftSon)){
			d1[i].leftSon=(int)(leftSon-'0');
		}
		if(isdigit(rightSon)){
			d1[i].rightSon=(int)(rightSon-'0');
		}
	}
	for(int i=0;i<num;i++){
		parent=(int)(d1[i].alpha-'A');
		p1.addLine(parent,parent);
		if(d1[i].leftSon!=-1){
			tempDot=(int)(d1[d1[i].leftSon].alpha-'A');
			p1.addLine(parent,tempDot);
		}
		if(d1[i].rightSon!=-1){
			tempDot=(int)(d1[d1[i].rightSon].alpha-'A');
			p1.addLine(parent,tempDot);
		}
	}
	scanf("%d",&num);
	getchar();
	Graph p2;
	vector<Dot> d2(num);
	for(int i=0;i<num;i++){
		scanf("%c %c %c",&alph,&leftSon,&rightSon);
		d2[i].alpha=alph;
		getchar();
		if(isdigit(leftSon)){
			d2[i].leftSon=(int)(leftSon-'0');
		}
		if(isdigit(rightSon)){
			d2[i].rightSon=(int)(rightSon-'0');
		}
	}
	for(int i=0;i<num;i++){
		parent=(int)(d2[i].alpha-'A');
		p2.addLine(parent,parent);
		if(d2[i].leftSon!=-1){
			tempDot=(int)(d2[d2[i].leftSon].alpha-'A');
			p2.addLine(parent,tempDot);
		}
		if(d2[i].rightSon!=-1){
			tempDot=(int)(d2[d2[i].rightSon].alpha-'A');
			p2.addLine(parent,tempDot);
		}
	}
	if(p1==p2){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}
