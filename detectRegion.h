//
// Created by ttbond on 18-9-16.
//

#ifndef SRCFIND_DETECTREGION_H
#define SRCFIND_DETECTREGION_H
#include<stdio.h>
#include<string.h>
#include"ttbond_math.h"

class detectRegion {
public:
    detectRegion(char *str,int _chr,long long _st,long long _ed);
    detectRegion(char *str1,int _chr,long long _st1,long long _ed1,char *str2,int _chr2,long long _st2,long long _ed2);
    void getReverseComScore();
    void localizeFirstBasePos();
    void releaseFirstBasePos(int **&_firstBasePos);
    void release(double *&toRelease);
    void release(int *&toRelease);
    void revComDfs(int *st,int *ed,int *misMatchSt,int *misMatchEd,int *st2,int *ed2,int *misMatchSt2,int *misMatchEd2,int depth);
    int *getInitMisSt(int iteNum,int **_firstBasePos,int *_cacheForDfs);
    int *getInitMisEd(int iteNum,int **_firstBasePos,int *_cacheForDfs);
    void copyFirstBasePos();

    static bool firstRegion;
    static char *base;
    static int mismatchNum;
    int chr,st,ed,length;
    //if the region is constructed by two regions in genome
    //this will be used
    int chr2,st2,ed2;
    char *agct,*agctEnd;
    double *reverseComScore;
    int **firstBasePos,**firstBasePos2;
    int *indEndOfFirstBasePos[4];
    int *cacheForDfs,*cacheForDfs2;
    long long cacheLen;
};


#endif //SRCFIND_DETECTREGION_H
