//
// Created by ttbond on 18-9-26.
//

#include "solRel.h"

solRel::solRel() {

}

solRel::solRel(detectRegion &source) {
    maxSelectP=0.8;
    info=new basicInfo(source.chr,source.st,source.ed,source.mySv);
    maxRevComScore=getMax(source.reverseComScore,source.reverseComScore+source.length);
    maxDirRepScore=getMax(source.directRepScore,source.directRepScore+source.length);
    maxMirRepScore=getMax(source.mirrorRepScore,source.mirrorRepScore+source.length);
    lengthMaxRev=getSpeLen(source.reverseComScore,source.reverseComScore+source.length,maxRevComScore*maxSelectP);
    lengthMaxDir=getSpeLen(source.directRepScore,source.directRepScore+source.length,maxDirRepScore*maxSelectP);
    lengthMaxMir=getSpeLen(source.mirrorRepScore,source.mirrorRepScore+source.length,maxMirRepScore*maxSelectP);
    sumRevComScore=getSum(source.reverseComScore,source.reverseComScore+source.length);
    sumDirRepScore=getSum(source.directRepScore,source.directRepScore+source.length);
    sumMirRepScore=getSum(source.mirrorRepScore,source.mirrorRepScore+source.length);

}

double solRel::getMax(double *st, double *ed) {
    double rel=-1;
    for(double *i=st;i<ed;i++){
        if((*i)>rel){
            rel=(*i);
         }
    }
    return rel;
}

double solRel::getSum(double *st, double *ed) {
    double sum=0;
    for(double *i=st;i<ed;i++){
        sum+=(*i);
    }
    return sum;
}

long long solRel::getSpeLen(double *st, double *ed, double bar) {
    long long len=0;
    for(double *i=st;i<ed;i++){
        if((*i)>=bar){
            len++;
        }
    }
    return len;
}