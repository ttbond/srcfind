//
// Created by ttbond on 18-9-26.
//

#ifndef SRCFIND_BASICINFO_H
#define SRCFIND_BASICINFO_H
#include"ttbond_math.h"

class basicInfo {
public:
    basicInfo();
    basicInfo(const basicInfo &source);
    basicInfo(int _chr,long long _st,long long _ed,svType _sv=OTHER);
    bool operator <(basicInfo &right);
    bool operator ==(basicInfo &right);
    void printMe(FILE *fp=NULL);
    void printRange(FILE *fp=NULL);
    long long getLength();

    int chr;
    long long st,ed;
    svType sv;
};


#endif //SRCFIND_BASICINFO_H
