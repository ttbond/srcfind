//
// Created by ttbond on 18-10-17.
//

#ifndef SRCFIND_AGCTTREE_H
#define SRCFIND_AGCTTREE_H
#include<vector>
#include<algorithm>
#include"agctNode.h"
#include"agctNode.cpp"
class agctTree {
    agctTree();
    ~agctTree();
    void release(agctNode *tar);
    void addSeq(agctNode &nowNode,char *from,int len,int level);
    inline int nu2int(char *from);
    void printMostSeq(int rank,int _leastLen,char *fileName);
    void getTotalNum(std::vector<int> &rel,agctNode *nowNode,int level);
    agctNode *root;
    int maxLevel,leastLen;
};


#endif //SRCFIND_AGCTTREE_H
