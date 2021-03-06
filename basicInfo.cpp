//
// Created by ttbond on 18-9-26.
//
#ifndef SRCFIND_BASICINFO_CPP
#define SRCFIND_BASICINFO_CPP
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

void basicInfo::printMe(FILE *fp) {
    if(fp==NULL){
        printf("chr:%d st:%lld ed:%lld\n",chr,st,ed);
    }
    else{
        fprintf(fp,"%d\t%lld\t%lld\t",chr,st,ed);
    }
}

void basicInfo::printRange(FILE *fp){
    if(fp==NULL){
        printf("range:%lld\n",ed-st);
    }
    else{
        fprintf(fp,"%lld\t",ed-st);
    }
}

long long basicInfo::getLength() {
    return ed-st+1;
}
#endif