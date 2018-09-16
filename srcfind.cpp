#include<stdio.h>
#include<string.h>
#include<vector>


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
    vcfFile chr1NormalSV(chr1SV.selectBySv(OTHER,false));
    std::vector<int>chr;
    std::vector<long long>st;
    std::vector<long long>st2;
    std::vector<long long>ed;
    std::vector<long long>ed2;
    chr1NormalSV.getDetetionRegions(chr,st,st2,ed,ed2,agctLen);
    int regionNum=chr.size();
    for(int i=0;i<regionNum;i++){
        detectRegion region(agct,chr[i],st[i],ed[i],agct,chr[i],st2[i],ed2[i]);
        break;
    }
    //printf("%d\n",chr1NormalSV.vcfNum);
    //ab.print();
    //printf("%d\n",oneVCF::knowFormat);
    //char *fileName="GRCh38.d1.vd1.fa";
    //loadAgctByChr(11,fileName,agct);
    return 0;
}