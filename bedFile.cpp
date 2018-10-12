//
// Created by ttbond on 18-10-11.
//

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

void bedFile::solAndPrint() {
    std::vector<basicInfo>::iterator it;
    FILE *fp=fopen("./geneExons/questionCancerGeneScore.dat","w");
    int refChr=0;
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
}

