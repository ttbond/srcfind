//
// Created by ttbond on 18-10-17.
//
#ifndef SRCFIND_AGCTNODE_CPP
#define SRCFIND_AGCTNODE_CPP
#include "agctNode.h"
agctNode::agctNode(){
    num=0;
    for(int i=0;i<4;i++){
        son[i]=NULL;
    }
}

inline agctNode *agctNode::enterSon(int id){
    if(id<0||id>3){
        printf("wrong Id in agctNode::enterSon(int id) value:%d\n",id);
        exit(-1);
    }
    if(son[id]==NULL){
        son[id]=new agctNode();
    }
    return son[id];
}

agctNode::~agctNode(){
    for(int i=0;i<4;i++){
        if(son[i]!=NULL){
            delete son[i];
        }
    }
}
#endif