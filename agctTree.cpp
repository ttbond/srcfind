//
// Created by ttbond on 18-10-17.
//
#ifndef SRCFIND_AGCTTREE_CPP
#define SRCFIND_AGCTTREE_CPP
#include "agctTree.h"
agctTree::agctTree(){
    root=new agctNode();
    maxLevel=20;
}
void agctTree::release(agctNode *tar){
    for(int i=0;i<4;i++){
        if(tar->son[i]!=NULL){
            release(tar->son[id]);
        }
    }
    delete tar;
}
inline int agctTree::nu2int(char *from){
    switch(*from){
        case 'a':
        case 'A':
            return 0;
        case 'g':
        case 'G':
            return 1;
        case 'c':
        case 'C':
            return 2;
        case 't':
        case 'T':
            return 3;
        default:
            return -1;
    }
}
void agctTree::addSeq(agctNode &nowNode,char *from,int len,int level){
    agctNode *nextNode=nowNode.enter
}
agctTree::~agctTree() {
    release(root);
}