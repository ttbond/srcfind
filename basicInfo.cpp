//
// Created by ttbond on 18-9-26.
//

#include "basicInfo.h"
basicInfo::basicInfo(){
    chr=-1;
    st=-1;
    ed-1;
    sv=OTHER;
}

basicInfo::basicInfo(const basicInfo &source) {
    chr=source.chr;
    st=source.st;
    ed=source.ed;
    sv=source.sv;
}

basicInfo::basicInfo(int _chr,long long _st,long long _ed,svType _sv){
    chr=_chr;
    st=_st;
    ed=_ed;
    sv=_sv;
}

bool basicInfo::operator <(basicInfo &right){
    if(chr!=right.chr){
        return chr<right.chr;
    }
    else if(st!=right.st){
        return st<right.st;
    }
    else{
        return ed<right.ed;
    }
}

bool basicInfo::operator ==(basicInfo &right){
    return chr==right.chr&&st==right.st&&ed==right.ed&&sv==right.sv;
}