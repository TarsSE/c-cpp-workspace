#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &a,int num);
void insertSort(vector<int> &a,int num);
void quickSort(vector<int> &a,int start,int end);
int partition(vector<int> &a,int start,int end);
void mergeSort(vector<int> &a,vector<int> &b,int l,int r);
void merge(vector<int> &a,vector<int> &b,int l,int mid,int r);
void swap(int &a,int &b);

int main(){
	int num;
	cin>>num;
	vector<int> a(num);
	for(int i=0;i<num;i++){
		cin>>a[i];
	}
	quickSort(a,0,num-1);
	for(int i=0;i<num;i++){
		if(i!=0)
		cout<<' '<<a[i];
		else
		cout<<a[i];
	}
}

void bubbleSort(vector<int> &a,int num){
	int cnt;
	for(int i=0;i<num-1;i++){
		cnt=0;
		for(int j=0;j<num-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				cnt++;
			}
		}
		if(cnt==0){
			break;
		}
	}
}
void insertSort(vector<int> &a,int num){
	int temp;
	for(int i=1;i<num;i++){
		for(int j=0;j<i;j++){
			if(a[i]<a[j]){
				temp=a[i];
				for(int k=i;k>j;k--){
					a[k]=a[k-1];
				}
				a[j]=temp;
				break;
			}
		}
	}
}
void quickSort(vector<int> &a,int start,int end){
	if(start>=end){
		return ;
	}
	int i;
	i=partition(a,start,end);
	quickSort(a,start,i-1);
	quickSort(a,i+1,end);
}
int partition(vector<int> &a,int start,int end){
	int i=start-1,j=end,s=a[end];
	while(1){
		while(a[(++i)]<=s){
			if(i>=end)
			break;
		}
		while(a[--j]>=s){
			if(j<=start)
			break;
		}
		if(i>=j){
			break;
		}
		swap(a[i],a[j]);
	}
	swap(a[i],a[end]);
	return i;
}
void mergeSort(vector<int> &a,vector<int> &b,int l,int r){
	if(l>=r){
		return ;
	}
	int mid=(l+r)/2;
	mergeSort(a,b,l,mid);
	mergeSort(a,b,mid+1,r);
	merge(a,b,l,mid,r);
}
void merge(vector<int> &a,vector<int> &b,int l,int mid,int r){
	int i=l,j=mid+1,s=l;
	while((i<=mid)&&(j<=r)){
		if(a[i]<=a[j]){
			b[s++]=a[i++];
		}else{
			b[s++]=a[j++];
		}
		if(i==mid+1){
			for(i=j;i<=r;i++){
				b[s++]=a[i];
			}
		}else if(j==r+1){
			for(;i<=mid;i++){
				b[s++]=a[i];
			}
		}
	}
	for(i=l;i<=r;i++){
		a[i]=b[i];
	}
}
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
