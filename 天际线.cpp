#include <iostream>
//#include <malloc.h> 
#include <vector>
#include <set>

using namespace std;

struct Dot{
    int x,height;
    Dot *next;
    Dot(int _x,int _height){
        x=_x;
        height=_height;
        next=NULL;
    }
};

struct DotList{
    Dot *head;
    int nodeNum;
    DotList(){
        head=new Dot(0,0);
        nodeNum=0;
    }
    void insertDot(Dot* aDot){
        aDot->next=head->next;
        head->next=aDot;
        nodeNum++;
    }
    void deleteAll(){
        Dot *p=head,*temp;
        while(p!=NULL){
            temp=p->next;
            delete p;
            p=temp;
        }
    }
    void sort(){
        Dot *pre,*cur1,*cur2,*temp;
        for(int i=0;i<nodeNum-1;i++){
            pre=head;
            cur1=pre->next;
            cur2=cur1->next;
            for(int j=0;j<nodeNum-i-1;j++){
                if(cur1->x>cur2->x){
                    pre->next=cur2;
                    cur1->next=cur2->next;
                    cur2->next=cur1;
                    temp=cur2;
                    cur2=cur1;
                    cur1=temp;
                }
                pre=pre->next;
                cur1=pre->next;
                cur2=cur1->next;
            }
        }
    }
};

struct HeightNode{
    int height;
    HeightNode* next;
    HeightNode(int _height){
        height=_height;
        next=NULL;
    }
};

struct HeightList{
    HeightNode* head;
    HeightList(){
        head=new HeightNode(1001);
        head->next=new HeightNode(0);
    }
    void insertHeight(int height){
        HeightNode *h=new HeightNode(height);
        HeightNode *p=head->next,*pre=head;
        while(p!=NULL){
            if(height>p->height){
                h->next=pre->next;
                pre->next=h;
                break;
            }
            pre=pre->next;
            p=pre->next;
        }
    }
    int getHighest(){
//    	if
        return head->next->height;
    }
    void deleteHeight(int height){
        HeightNode *pre,*cur;
        pre=head;
        cur=pre->next;
        while(cur!=NULL){
            if(height==cur->height){
                pre->next=cur->next;
                delete cur;
                break;
            }
            pre=pre->next;
            cur=pre->next;
        }
    }
    void deleteAll(){
        HeightNode *temp,*p;
        p=head;
        while(p!=NULL){
            temp=p->next;
            delete p;
            p=temp;
        }
    }
};

int main(){
    DotList dList,resultList;
    Dot *left,*right;
    HeightList hList;
    int num,li,hi,ri;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>li>>hi>>ri;
        left=new Dot(li,hi);
        right=new Dot(ri,-hi);
        dList.insertDot(left);
        dList.insertDot(right);
    }
    dList.sort();
    Dot *p=dList.head->next,highestDot(-3001,0);
    while(p!=NULL){
        if(p->height>0){
            hList.insertHeight(p->height);
        }else{
            hList.deleteHeight(-(p->height));
        }
        int curMaxHeight=hList.getHighest();

        if(curMaxHeight!=highestDot.height){
            resultList.insertDot(new Dot(p->x,curMaxHeight));
            highestDot.height=curMaxHeight;
            highestDot.x=p->x;
//            highestDot.height=p->height;
//            highestDot.x=curMaxHeight;
        }
        p=p->next;
    }
    p=resultList.head->next;
    while(p!=NULL){
        cout<<p->x<<" "<<p->height<<endl;
        p=p->next;
    }
    resultList.deleteAll();
    hList.deleteAll();
    dList.deleteAll();
}
