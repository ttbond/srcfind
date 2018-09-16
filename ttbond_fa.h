//
// Created by ttbond on 18-9-14.
//

#ifndef SRCFIND_TTBOND_FA_H
#define SRCFIND_TTBOND_FA_H
#include "ttbond_math.h"
//if the chr data is a normal chr return true
inline bool isRegularChr(char *str){
    char *ref=">chr";
    char source[10];
    strncpy(source,str,4);
    source[4]='\0';
    if(strcmp(source,ref)==0){
        bool firstNum=false;
        char *i;
        for(i=str+4;(*i)>='0'&&(*i)<='9';i++){
            firstNum=true;
        }
        if((*i)!=' '||firstNum==false){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}


//if the symbol is 'A/G/C/T/N' return true
inline bool isNormalAgctSymbol(const char &tmp){
    if(tmp=='A'||tmp=='G'||tmp=='C'||tmp=='T'||tmp=='N'){
        return true;
    }
    else{
        return false;
    }
}


//if the specific chrNum is found then it's sequencing will be loaded to array agct
// and return the length of the chr .... if not exist return -1
long long loadAgctByChr(int chrNum,char *fileName,char *agct){
    printf("loading chr%d from %s...\n",chrNum,fileName);
    FILE *fp;
    fp=fopen(fileName,"r");
    char chrName[10];
    bool findChr=false;
    char tmp[1000];
    while(fgets(tmp,1000,fp)!=NULL){
        if(tmp[0]=='>'&&isRegularChr(tmp)){
            char *j=chrName;
            for(char *i=tmp+4;(*i)>='0'&&(*i)<='9';i++){
                *j++=*i;
            }
            *j='\0';
            int chrN=stringChrName2int(chrName);
            if(chrN==chrNum){
                findChr=true;
                long long chrLen=0;
                char *tp=agct;
                bool comZero=false;
                while(fgets(tp,1000,fp)!=NULL){
                    if(!isNormalAgctSymbol(*tp)){
                        *tp='\0';
                        comZero=true;
                        break;
                    }
                    int newLen=strlen(tp);
                    tp+=newLen-1;
                    chrLen+=newLen-1;
                }
                if(!comZero){
                    *tp='\0';
                }
                printf("loading successfully %lld agct\n",chrLen);
                return chrLen;
            }
        }
    }
    if(!findChr){
        return -1;
    }
}



#endif //SRCFIND_TTBOND_FA_H
