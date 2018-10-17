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
            release(tar->son[i]);
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
    if(level<maxLevel&&len>0){
        agctNode *nextNode=nowNode.enterSon(nu2int(from));
        addSeq(*nextNode,from+1,len-1,level+1);
    }
    else{
        nowNode.num++;
    }
}
void agctTree::getTotalNum(std::vector<int> &rel,agctNode *nowNode,int level){
    if(nowNode->num>0&&level>=leastLen){
        rel.push_back(-(nowNode->num));
    }
    for(int i=0;i<4;i++){
        if(nowNode->son[i]!=NULL){
            getTotalNum(rel,nowNode->son[i],level+1);
        }
    }
}
void agctTree::printMostSeq(int rank,int _leastLen,char *fileName){
    FILE *fp=fopen(fileName,"w");
    leastLen=_leastLen;
    std::vector<int> nums;
    getTotalNum(nums,root,0);
    sort(nums.begin(),nums.end());
    std::vector<int>::iterator it;
    for(it=nums.begin();it!=nums.end();it++){
        fprintf(fp,"%d\t",(*it));
    }
    fclose(fp);
}
agctTree::~agctTree() {
    release(root);
}
#endif