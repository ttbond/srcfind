//
// Created by ttbond on 18-10-17.
//

#ifndef SRCFIND_AGCTTREE_H
#define SRCFIND_AGCTTREE_H
#include"agctTree.h"
#include"agctTree.cpp"
class agctTree {
    agctTree();
    ~agctTree();
    void release(agctNode *tar);
    void addSeq(char *from,int len,int level);
    inline int nu2int(char *from);
    agctNode *root;
    int maxLevel;
};


#endif //SRCFIND_AGCTTREE_H
