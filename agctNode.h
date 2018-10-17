//
// Created by ttbond on 18-10-17.
//

#ifndef SRCFIND_AGCTNODE_H
#define SRCFIND_AGCTNODE_H


class agctNode {
public:
    agctNode();
    ~agctNode();
    inline agctNode *enterSon(int id);
    agctNode *son[4];
    long long num;
};


#endif //SRCFIND_AGCTNODE_H
