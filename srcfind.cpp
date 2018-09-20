#include<stdio.h>
#include<string.h>
#include<vector>
#include<stdlib.h>


#include"ttbond_fa.h"
#include"vcfFile.h"
#include"vcfFile.cpp"
#include"detectRegion.h"
#include"detectRegion.cpp"

char agct[300000000];

int main()
{
    long long agctLen=loadAgctByChr(1,"GRCh38.d1.vd1.fa",agct);
    vcfFile myVcfFile("NA19240.vcf");
    vcfFile chr1SV(myVcfFile.selectByChr(1));
    //vcfFile chr1NormalSV(chr1SV.selectBySv(DEL,false));
    std::vector<int>chr;
    std::vector<long long>st;
    //std::vector<long long>st2;
    std::vector<long long>ed;
    std::vector<svType>svs;
    //std::vector<long long>ed2;
    chr1SV.getDetetionRegions(chr,st,ed,svs,agctLen);
    int regionNum=chr.size();
    /* for test;

    detectRegion region("AGCTAGCT",1,1,8);
    region.getReverseComScore();
    region.printDetectRel();
    */

     //
    //
    FILE *fp=fopen("chr1.rcf","w");
    FILE *scrFile=fopen("chr1.scr","w");
    double maxLen=0;
    for(int i=0;i<regionNum;i++){
        //detectRegion region(agct,chr[i],st[i],ed[i],agct,chr[i],st2[i],ed2[i]);
        detectRegion region(agct,chr[i],st[i],ed[i],svs[i]);
        region.getReverseComScore(scrFile);
        //region.printDetectRel(fp);
        //getchar();
    }
    fclose(fp);
    fclose(scrFile);
     //
    //printf("%d\n",chr1NormalSV.vcfNum);
    //ab.print();
    //printf("%d\n",oneVCF::knowFormat);
    //char *fileName="GRCh38.d1.vd1.fa";
    //loadAgctByChr(11,fileName,agct);
    return 0;
}