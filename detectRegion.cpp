//
// Created by ttbond on 18-9-16.
//

#include "detectRegion.h"

detectRegion::detectRegion(char *str,int _chr,long long _st,long long _ed){
    st=_st;
    ed=_ed;
    chr=_chr;
    length=ed-st+1;
    agct=new char[length+10];
    char *i=agct,*j=str+st-1,*charEd=str+ed-1;
    for(;j<=charEd;j++,i++){
        (*i)=(*j);
    }
    (*i)='\0';
    puts(agct);
}

//region2 should be at the letf region of region1
detectRegion::detectRegion(char *str1,int _chr,long long _st1,long long _ed1,char *str2,int _chr2,long long _st2,long long _ed2){
    st=_st1;
    ed=_ed1;
    chr=_chr;
    st2=_st2;
    ed2=_ed2;
    chr2=_chr2;
    length=(ed-st+1)+(ed2-st2+1)+1;
    agct=new char[length+10];
    char *i=agct,*j=str1+st-1,*charEd=str1+ed-1;
    for(;j<=charEd;j++,i++){
        (*i)=(*j);
    }
    (*i)='#';//to separate the two regions
    i++;
    j=str2+st2-1;
    charEd=str2+ed2-1;
    for(;j<=charEd;j++,i++){
        (*i)=(*j);
    }
    (*i)='\0';
    puts(agct);
}