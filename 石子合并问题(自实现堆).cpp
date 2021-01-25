#include <iostream>
#include <vector>
using namespace std;

struct MinHeap{
	int last,maxSize;
	vector<int> heap;
	MinHeap(int _maxSize){
		maxSize=_maxSize;
		heap.resize(maxSize+1);
		last=0;
	}
	void insert(int item){
		if(last==maxSize){
			return ;
		}
		int i=++last;
		while(i!=1&&item<heap[i/2]){
			heap[i]=heap[i/2];
			i/=2;
		}
		heap[i]=item;
	}
	int deleteMin(){
		if(last==0){
			exit(1);
		}
		int x=heap[1];
		int y=heap[last--];
		int i=1,ci=2;
		while(ci<=last){
			if(heap[ci]>heap[ci+1]){
				ci++;
			}
			if(y<=heap[ci]){
				break;
			}
			heap[i]=heap[ci];
			i=ci;
			ci*=2;
		}
		heap[i]=y;
		return x;
	}
};

int main(){
	int heapNum,rockNum,pay=0,afterMerge;
	cin>>heapNum;
	MinHeap rock(heapNum);
	for(int i=0;i<heapNum;i++){
		cin>>rockNum;
		rock.insert(rockNum);
	}
	for(int i=0;i<heapNum-1;i++){
		afterMerge=0;
		afterMerge+=rock.deleteMin();
		afterMerge+=rock.deleteMin();
		pay+=afterMerge;
		rock.insert(afterMerge);
	}
	cout<<pay;
}
