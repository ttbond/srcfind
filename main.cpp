//
// Created by ttbond on 18-10-9.
//
#include<stdio.h>
#include<string.h>
#include<vector>
#include<stdlib.h>

#include"geneRegionFile.h"
#include"geneRegionFile.cpp"

#include"basicInfo.h"
#include"basicInfo.cpp"
#include"bedFile.h"
#include"bedFile.cpp"
#include"faFile.h"
#include"faFile.cpp"
#include"backgroundGenerator.h"
#include"backgroundGenerator.cpp"


char agct[300000000];
char agctForBedFile[300000000];
std::vector<basicInfo> tmpVec;
int main(){

    /*
    backgroundGenerator bg(agct,agctForBedFile);
    */


    geneRegionFile grf("./geneExons/geneExonNoCancer.bed",agct);
    grf.solAndPrintRel();

    /*
    bedFile bf("./geneExons/questionCancerGene.bed",agct);
    bf.solAndPrint();
    */
}
