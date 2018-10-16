//
// Created by ttbond on 18-10-11.
//
#ifndef SRCFIND_BEDFILE_CPP
#define SRCFIND_BEDFILE_CPP
#include "bedFile.h"

bedFile::bedFile(char *fileName,char *_agct) {
    agct=_agct;
    FILE *fp=fopen(fileName,"r");
    char cache[100];
    int chr;
    long long st,ed;
    while(fgets(cache,100,fp)!=NULL){
        char *cacheSt=cache;
        if((*cache)=='c'||(*cache)=='C'){
            cacheSt=cache+3;
        }
        sscanf(cacheSt,"%d%lld%lld",&chr,&st,&ed);
        myRegion.push_back(basicInfo(chr,st,ed));
    }
    fclose(fp);
}

bedFile::bedFile(std::vector <basicInfo> _source,char *_agct) {
    myRegion=_source;
    agct=_agct;
}

void bedFile::solAndPrint(char *fileName,char *writeType) {


    std::vector<basicInfo>::iterator it;
    FILE *fp=fopen(fileName,writeType);
    int refChr=0;
    //for debug
    /*
    for(it=myRegion.begin();it!=myRegion.end();it++){
        if(refChr!=(*it).chr){
            refChr=(*it).chr;
            loadAgctByChr(refChr,"GRCh38.d1.vd1.fa",agct);
        }
        detectRegion region(agct,(*it).chr,(*it).st,(*it).ed,(*it).sv);
        region.getReverseComScore(fp);
        region.getDirectRepeatScore(fp);
        region.getMirrorRepeatScore(fp);
    }
     */

    //for background set
    int infoNum=myRegion.size();
    puts("aaaaa");
    for(int i=0;i<infoNum;i++){
        if(myRegion[i].chr!=refChr){
            refChr=myRegion[i].chr;
            loadAgctByChr(refChr,"GRCh38.d1.vd1.fa",agct);
        }
        detectRegion region(agct,myRegion[i].chr,myRegion[i].st,myRegion[i].ed,myRegion[i].sv);
        region.getMirrorRepeatScore();
        region.getDirectRepeatScore();
        region.getReverseComScore();
        myRel.push_back(solRel(region));
    }
    puts("bbbbb");
    for(int i=0;i<infoNum;i++){
        if(myRegion[i].chr==24){
            continue;
        }
        //fprintf(fp,"%d\t%d\t",id,i+1);
        myRel[i].printMe(fp);
        fprintf(fp,"\n");
    }
    fclose(fp);
}

#endif