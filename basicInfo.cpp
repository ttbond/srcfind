//
// Created by ttbond on 18-9-26.
//

#include "basicInfo.h"
basicInfo::basicInfo(){
    chr=-1;
    st=-1;
    ed-1;
    svType=OTHER;
}

basicInfo::basicInfo(int _chr,long long _st,long long _ed,svType _sv){
    chr=_chr;
    st=_st;
    ed=_ed;
    sv=_sv;
}
