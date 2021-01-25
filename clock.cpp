#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

//ָ��һ��ҳ���СΪ2KB,��������ҳ��Ϊ8,����4������ҳ֡ 
const int FRAME_SIZE=1024*4;
const int V_FRAME_NUM=8;
const int R_FRAME_NUM=4; 

class PageTableItem{
private:
    bool present;
    int rFrameNum;
public:
    bool isRead;
    bool isPresent;

    PageTableItem();
    int getRFrameNum(){return rFrameNum;}
    void setRFrameNum(int num){rFrameNum=num;}
    bool isFilled(){return rFrameNum==-1;}
};

class PageTable{
private:
    vector<PageTableItem> vPage;
    int cur;
    vector<int> clock;

    void clearRead();
public:
    PageTable();
    int getVirtualFrameNum(int address);
    int getInnerAddress(int address);
    int pointToNext(){cur=(cur+1)%R_FRAME_NUM;cout<<endl<<"test:cur="<<cur<<endl;}
    int pointToNextAvailable(int vPageNum);
    void printPageTable();
    int getRFrameNum(int vPageNum);
};



// class RFrameClock{
// private:
//     int pointer;
//     vector<int> clock;

//     void pointToNext(){pointer=(pointer+1)%R_FRAME_NUM;}
//     int pointToNextAvailable();
// public:
//     RFrameClock();

// };
/***************ҳ����**********************/
PageTableItem::PageTableItem(){
    isRead=false;
    present=false;
    rFrameNum=-1;
}

/***************ҳ��***********************/

void PageTable::clearRead(){
    for(int i=0;i<R_FRAME_NUM;i++){
        if(clock[i]!=-1)vPage[clock[i]].isRead=false;
    }
}

PageTable::PageTable(){
    vPage.resize(V_FRAME_NUM);
    cur=0;
    clock.resize(R_FRAME_NUM,-1);
}

int PageTable::getVirtualFrameNum(int address){
    return address/FRAME_SIZE;
}

int PageTable::getInnerAddress(int address){
    return address%FRAME_SIZE;
}

int PageTable::pointToNextAvailable(int vPageNum){
    int result=-1;

    // for(int i=0;i<R_FRAME_NUM;i++){//����Ƿ��Ѵ���
    //     if(clock[i]==vPageNum){//����
    //         clearRead();
    //         vPage[vPageNum].isRead=true;
    //         cur=i;
    //         pointToNext();
    //         cout<<"����λ�������ڴ���"<<endl;
    //         return i;
    //     }
    // }
    int tempCur=cur;
    bool hasBlank=false;
    for(int i=0;i<R_FRAME_NUM;i++){
        if(clock[tempCur]==-1){
            // cur=tempCur;
            hasBlank=true;
            cout<<"��ǰ����ҳ֡���п�ҳ"<<"test:cur="<<cur<<endl;
            break;
        }
        tempCur=(tempCur+1)%R_FRAME_NUM;
    }
    if(!hasBlank){
        for(int i=0;i<R_FRAME_NUM;i++){//�����ڴ�
            
            if(vPage[clock[cur]].isRead){//������
                vPage[clock[cur]].isRead=false;
            }else{//δ������
                cout<<"�ҵ����滻ҳ��"<<endl;
                vPage[cur].isPresent=false;
                tempCur=cur;
                break;
            }
            pointToNext();
        }
    }
    


    clock[tempCur]=vPageNum;//װ��ҳ֡
    vPage[vPageNum].isPresent=true;

    //�޸�ҳ��
    clearRead();
    vPage[vPageNum].isRead=true;
    vPage[vPageNum].setRFrameNum(tempCur);
    if(!hasBlank)
    pointToNext();
}

void PageTable::printPageTable(){
    printf("%10s%6c%6c\n","pa_num",'R','P');
    for(int i=0;i<V_FRAME_NUM;i++){
        printf("%10d%6d%6d\n",vPage[i].getRFrameNum(),vPage[i].isRead?1:0,vPage[i].isPresent?1:0);
    }
    for(int i=0;i<R_FRAME_NUM;i++){
        printf("%d\t",clock[i]);
    }
    cout<<endl;
}
int PageTable::getRFrameNum(int vPageNum){
    int result=-1;
    if(vPage[vPageNum].isPresent){//���ڴ���
        cout<<"�������ݵ�ǰ���ڴ���"<<endl;
        while(clock[cur]!=vPageNum){
            pointToNext();
        }
        result=cur;
        clearRead();
        vPage[cur].isRead=true;
        // pointToNext();
    }else{//�����ڴ���
        cout<<"�������ݲ����ڴ���"<<endl;
        result=pointToNextAvailable(vPageNum);
    }
}
/**********************����ҳ֡*************************/
// RFrameClock::RFrameClock(){
//     pointer=0;
//     clock.resize(R_FRAME_NUM);
// }

// int RFrameClock::pointToNextAvailable(){
//     int result=-1;
//     for(int i=0;i<R_FRAME_NUM;i++){
//         if(!(clock.at(pointer).isFilled())){//�п�ҳ֡
//             result=pointer;
//             pointToNext();
//             break;
//         }else{

//         }
//     }
// }


/*****************������************************/

int main(){
    int address;
    PageTable pageTable;
    cin>>address;
	while(address>=0){
        pageTable.getRFrameNum(pageTable.getVirtualFrameNum(address));


        pageTable.printPageTable();
        cin>>address;
    }
} 
