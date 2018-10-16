//
// Created by ttbond on 18-10-15.
//

#ifndef SRCFIND_BACKGROUNDGENERATOR_H
#define SRCFIND_BACKGROUNDGENERATOR_H
#include<vector>
#include<string>
#include"bedFile.h"
#include"bedFile.cpp"
#include"faFile.h"
#include"faFile.cpp"
#include"basicInfo.h"
#include"basicInfo.cpp"


class backgroundGenerator {
public:
    backgroundGenerator(char *agctArr,char *agctArr2,double _selectP=1.0/30000.0,long long _length=-1,int _chr=-1);
    double selecP;
    long long length;
    int chr;
    static long long *lengthArr;
};


#endif //SRCFIND_BACKGROUNDGENERATOR_H
