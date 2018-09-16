//
// Created by ttbond on 18-9-14.
//

#ifndef SRCFIND_TTBOND_MATH_H
#define SRCFIND_TTBOND_MATH_H

#include<string.h>

enum svType{DEL,DUP,INV,INS,OTHER};

//translate a small str data to int data
inline int stringChrName2int(char *str){
    int rel=0;
    char *i;
    if((*str)=='c'||(*str)=='C'){
        i=str+3;
    }
    else{
        i=str;
    }
    if((*i)=='x'||(*i)=='X'){
        return 23;
    }
    for(;(*i)!='\0';i++){
        rel*=10;
        rel+=(*i)-'0';
    }
    return rel;
}

inline long long string2ll(char *str){
    long long rel=0;
    char *i=str;
    for(;(*i)!='\0';i++){
        rel*=10;
        rel+=(*i)-'0';
    }
    return rel;
}

inline bool selectFromSepStr(char *rel,char *source,char *tar,char sepSymbol){
    int length=strlen(source);
    char cache[length+10];
    strcpy(cache,source);
    char *strSt=source,*i=source;
    for(;;i++){
        if((*i)==sepSymbol||(*i)=='\0'){
            bool endStrFlag=false;
            if((*i)=='\0'){
                endStrFlag=true;
            }
            (*i)='\0';
            bool findE=false;
            char *j=strSt;
            for(;j!=i;j++){
                if((*j)=='='){
                    findE=true;
                    (*j)='\0';
                    break;
                }
            }
            if(strcmp(strSt,tar)==0){
                if(findE){
                    strcpy(rel,j+1);
                }
                else{
                    rel[0]='\0';
                }
                return true;
            }
            if(endStrFlag){
                return false;
            }
            strSt=i+1;
        }
    }
}





#endif //SRCFIND_TTBOND_MATH_H
