//
// Created by ttbond on 18-9-16.
//

#include <cstring>
#include "detectRegion.h"

char *detectRegion::base=new char[5];
bool detectRegion::firstRegion=true;
int detectRegion::mismatchNum=2;


detectRegion::detectRegion(char *str,int _chr,long long _st,long long _ed){
    if(firstRegion){
        base[0]='A';
        base[1]='G';
        base[2]='C';
        base[3]='T';
        base[4]='\0';
        firstRegion=false;
    }
    st=_st;
    ed=_ed;
    chr=_chr;
    length=ed-st+1;
    cacheLen=length*4+10;
    agct=new char[length+10];
    char *i=agct,*j=str+st-1,*charEd=str+ed-1;
    for(;j<=charEd;j++,i++){
        (*i)=(*j);
    }
    (*i)='\0';
    agctEnd=agct+length;
    firstBasePos=NULL;
    cacheForDfs=new int[cacheLen];
    reverseComScore=NULL;
}

//region2 should be at the letf region of region1
detectRegion::detectRegion(char *str1,int _chr,long long _st1,long long _ed1,char *str2,int _chr2,long long _st2,long long _ed2){
    if(firstRegion){
        base[0]='A';
        base[1]='G';
        base[2]='C';
        base[3]='T';
        base[4]='\0';
        firstRegion=false;
    }
    st=_st1;
    ed=_ed1;
    chr=_chr;
    st2=_st2;
    ed2=_ed2;
    chr2=_chr2;
    length=(ed-st+1)+(ed2-st2+1)+1;
    cacheLen=length*4+10;
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
    agctEnd=agct+length;
    firstBasePos=NULL;
    cacheForDfs=new int[cacheLen];
    reverseComScore=NULL;
}

void detectRegion::localizeFirstBasePos(){
    releaseFirstBasePos(firstBasePos);
    firstBasePos=new int*[4];
    for(int **i=firstBasePos;i<firstBasePos+4;i++){
        (*i)=new int[cacheLen];
    }
    for(int i=0;i<4;i++){
        indEndOfFirstBasePos[i]=firstBasePos[i];
    }
    for(char *i=agct;i<agctEnd;i++){
        for(char *j=base;j<base+4;j++){
            if((*i)==(*j)){
                int id=j-base;
                *(indEndOfFirstBasePos[id]++)=i-agct;
                break;
            }
        }
    }
}

void detectRegion::releaseFirstBasePos(int **&_firstBasePos){
    if(_firstBasePos!=NULL){
        for(int i=0;i<4;i++){
            delete _firstBasePos[i];
        }
    }
    delete _firstBasePos;
    _firstBasePos=NULL;
}

void detectRegion::release(double *&toRelease){
    if(toRelease!=NULL){
        delete toRelease;
    }
    toRelease=NULL;
}
void detectRegion::release(int *&toRelease){
    if(toRelease!=NULL){
        delete toRelease;
    }
    toRelease=NULL;
}

int *detectRegion::getInitMisSt(int iteNum,int **_firstBasePos,int *_cacheForDfs){
    if(_firstBasePos==NULL){
        puts("firstBasePos hasn't been loacalized");
        exit(-1);
    }
    return _cacheForDfs;
}
int *detectRegion::getInitMisEd(int iteNum,int **_firstBasePos,int *_cacheForDfs){
    if(_firstBasePos==NULL){
        puts("firstBasePos hasn't been loacalized");
        exit(-1);
    }
    return _cacheForDfs+(indEndOfFirstBasePos[iteNum]-firstBasePos[iteNum]);
}

void detectRegion::copyFirstBasePos(){

}

void detectRegion::getReverseComScore(){
    release(reverseComScore);
    reverseComScore=new double[length+10];
    memset(cacheForDfs,0,cacheLen);
    localizeFirstBasePos();
    copyFirstBasePos();
    for(int i=0;i<4;i++){
        revComDfs(firstBasePos[i],indEndOfFirstBasePos[i],getInitMisSt(i,firstBasePos,cacheForDfs),getInitMisEd(i,firstBasePos,cacheForDfs),1);
    }
}

void detectRegion:: revComDfs(int *st,int *ed,int *misMatchSt,int *misMatchEd,int *st2,int *ed2,int *misMatchSt2,int *misMatchEd2,int depth){
    for(char *nuc=base;nuc<base+4;nuc++) {
        printf("%c\n",*nuc);
        /*
        int *nst = ed, *ned = ed;
        int *nmst = misMatched, *nmed = misMatched;
        for (int *i = st; i < ed; i++) {
            if (*(agct + (*i) + depth))
        }
         */
    }
}