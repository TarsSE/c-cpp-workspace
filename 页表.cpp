#include <iostream>
#include <vector>

class TableItem{
	int physicalPageNum;
	int r;
	int p;
};
class PageQueue{
	int cur;
	int size;
	vector<TableItem> circleQueue;
	PageQueue(int _size){
		cur=0;
		size=_size;
		
	}
};
