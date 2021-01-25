#include <iostream>

using namespace std;

#define PAGE_SIZE 4096
#define PAGE_NUM 4
#define VIRTURAL_SPACE 8

class Page
{
public:
    int pa_num;
    bool R;
    bool P;

    Page();

    bool isInRAM()
    {
        return P;
    }

    void read()
    {
        R = true;
    }

    void resetRead()
    {
        R = false;
    }
};

class PageTable 
{
public:
    Page *pages;

    int *RAM;
    int PagesInRAM;
    int curPageIndex;

    PageTable(int virtual_Length, int ram_Length);
    ~PageTable(){
        delete[] pages;
        delete[] RAM;
    }

    void read(int index);

    void next()
    {
        curPageIndex++;
        curPageIndex = (curPageIndex == PAGE_NUM) ? 0: curPageIndex;
    }

    bool isFullRAM()
    {
        return PagesInRAM == PAGE_NUM;
    }

    int getCurrRamPageIndex()
    {
        return RAM[curPageIndex];
    }
    void allocatedInRAM(int index);
    Page& operator[](int i)
    {
        return pages[i];
    }

    void printTable();
};


void clock_Algorithm(PageTable &pageTable, int virtualAddress);

int main()
{
   PageTable pageTable(VIRTURAL_SPACE, PAGE_NUM);
   int virtualAddress;
   cout << "please input the virtual address (end of -1): ";
   cin >> virtualAddress;
   while (virtualAddress != -1)
   {
       clock_Algorithm(pageTable, virtualAddress);
       pageTable.printTable();

       cout << "please input the virtual address (end of -1): ";
       cin >> virtualAddress;
   }
   return 0;
}
/****************Page*******************/
Page::Page()
{
    pa_num = 0;
    R = 0;
    P = 0;
}
/******************PageTable*********************/
PageTable::PageTable(int virtual_Lenth, int ram_Lenth)
{
    PagesInRAM = 0;
    pages = new Page[virtual_Lenth];
    RAM = new int[ram_Lenth];
    
    for (int cnt = 0; cnt < ram_Lenth; cnt++)
    {
        RAM[cnt] = -1;
    }
    PagesInRAM = 0;
    curPageIndex = 0;
}

void PageTable::read(int index)
{
    pages[index].read();
    for (int cnt = 0; cnt < VIRTURAL_SPACE; cnt++)
    {
        if (cnt != index)
        {
            pages[cnt].resetRead();
        }
    }        
}
void PageTable::allocatedInRAM(int index)
{
    RAM[curPageIndex] = index;
    pages[index].pa_num = curPageIndex;
    next();
    PagesInRAM == PAGE_NUM ? PAGE_NUM : PagesInRAM++;
}

void PageTable::printTable()
{
	cout << "pa_num       " << "R        " << "P" << endl;
	for (int cnt = 0; cnt < VIRTURAL_SPACE; cnt++)
	{
		cout << "  |" << pages[cnt].pa_num << "        |" << pages[cnt].R << "       |" << pages[cnt].P << endl;
	}
    cout << endl;
}
/***********************函数****************************/
void clock_Algorithm(PageTable &pageTable, int virtualAddress)
{
    int pageIndex = virtualAddress / PAGE_SIZE;

    if (pageTable[pageIndex].isInRAM())
    {
        cout << "the page is in the RAM, and the physical address is " << virtualAddress << endl;
        pageTable.read(pageIndex);
    }
    else if (pageTable.isFullRAM())
    {
        cout << "the page is not in the RAM!" << endl;
        cout << "there is no free page in RAM, so we have to exchange one!" << endl;

        while (true)
        {
            if (pageTable[pageTable.getCurrRamPageIndex()].R)
            {
                pageTable.next();
            }
            else
            {
                pageTable[pageTable.getCurrRamPageIndex()].P = false;
                pageTable[pageIndex].P = true;
                pageTable.read(pageIndex);
                pageTable.allocatedInRAM(pageIndex);
                break;
            }
        }
        cout << "NO." << pageTable.curPageIndex - 1 << " page is exchanged!!" << endl;
    }
    else
    {
        cout << "the page is not in the RAM!" << endl;
        cout << "there are free pages, we can get NO." << pageTable.curPageIndex << " page!" << endl;

        pageTable[pageIndex].P = true;
        pageTable.read(pageIndex);
        pageTable.allocatedInRAM(pageIndex);
    }
}