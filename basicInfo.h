//
// Created by ttbond on 18-9-26.
//

#ifndef SRCFIND_BASICINFO_H
#define SRCFIND_BASICINFO_H
#include"ttbond_math.h"

class basicInfo {
public:
    basicInfo();
    basicInfo(int _chr,long long _st,long long _ed,svType _sv=OTHER);
    int chr;
    long long st,ed;
    svType sv;
};


#endif //SRCFIND_BASICINFO_H
