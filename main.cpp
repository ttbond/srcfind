//
// Created by ttbond on 18-10-9.
//
#include<stdio.h>
#include<string.h>
#include<vector>
#include<stdlib.h>

#include"geneRegionFile.h"
#include"geneRegionFile.cpp"

char agct[300000000];
int main(){

    geneRegionFile grf("./geneExons/geneExonCancer.bed",agct);
    grf.solAndPrintRel();

    /*
    bedFile bf("./geneExons/questionCancerGene.bed",agct);
    bf.solAndPrint();
     */
}
