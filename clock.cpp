#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

//指定一个页面大小为2KB,进程虚拟页数为8,分配4个物理页帧 
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
/***************页表项**********************/
PageTableItem::PageTableItem(){
    isRead=false;
    present=false;
    rFrameNum=-1;
}

/***************页表***********************/

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

    // for(int i=0;i<R_FRAME_NUM;i++){//检查是否已存在
    //     if(clock[i]==vPageNum){//存在
    //         clearRead();
    //         vPage[vPageNum].isRead=true;
    //         cur=i;
    //         pointToNext();
    //         cout<<"访问位置已在内存中"<<endl;
    //         return i;
    //     }
    // }
    int tempCur=cur;
    bool hasBlank=false;
    for(int i=0;i<R_FRAME_NUM;i++){
        if(clock[tempCur]==-1){
            // cur=tempCur;
            hasBlank=true;
            cout<<"当前物理页帧中有空页"<<"test:cur="<<cur<<endl;
            break;
        }
        tempCur=(tempCur+1)%R_FRAME_NUM;
    }
    if(!hasBlank){
        for(int i=0;i<R_FRAME_NUM;i++){//不在内存
            
            if(vPage[clock[cur]].isRead){//被读过
                vPage[clock[cur]].isRead=false;
            }else{//未被读过
                cout<<"找到可替换页面"<<endl;
                vPage[cur].isPresent=false;
                tempCur=cur;
                break;
            }
            pointToNext();
        }
    }
    


    clock[tempCur]=vPageNum;//装入页帧
    vPage[vPageNum].isPresent=true;

    //修改页表
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
    if(vPage[vPageNum].isPresent){//在内存中
        cout<<"访问内容当前在内存中"<<endl;
        while(clock[cur]!=vPageNum){
            pointToNext();
        }
        result=cur;
        clearRead();
        vPage[cur].isRead=true;
        // pointToNext();
    }else{//不在内存中
        cout<<"访问内容不在内存中"<<endl;
        result=pointToNextAvailable(vPageNum);
    }
}
/**********************物理页帧*************************/
// RFrameClock::RFrameClock(){
//     pointer=0;
//     clock.resize(R_FRAME_NUM);
// }

// int RFrameClock::pointToNextAvailable(){
//     int result=-1;
//     for(int i=0;i<R_FRAME_NUM;i++){
//         if(!(clock.at(pointer).isFilled())){//有空页帧
//             result=pointer;
//             pointToNext();
//             break;
//         }else{

//         }
//     }
// }


/*****************主函数************************/

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
