
#ifndef MAMAN3_ARRAYNODE_H
#define MAMAN3_ARRAYNODE_H


class ArrayNode
{
private:
    int key;
    int index;
    friend class Heap;

public:

    ArrayNode(int k, int i){key=k; index=i; }
    ArrayNode(): key(0),index(0){}
};




#endif //MAMAN3_ARRAYNODE_H
