#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE    1
#define FALSE   0

typedef int LData;

struct Node {
    LData data;
    Node* next = NULL;
};

class LinkedList {
public:
    Node* tail;
    Node* cur;
    Node* before;
    int numOfData;
    LinkedList();
    
    void Insert(Ldata data);
    void FInsert(Ldata data);
    void FInsertFront(Ldata data);
    void SInsert(Ldata data);
    
    int LFirst(LData* pdata);
    int LNext(LData* pdata);

    LData LRemove();
    int LCount();
};

#endif