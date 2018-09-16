//
// Created by ttbond on 18-9-16.
//

#ifndef SRCFIND_DETECTREGION_H
#define SRCFIND_DETECTREGION_H


class detectRegion {
public:
    detectRegion(char *str,int _chr,long long _st,long long _ed);
    detectRegion(char *str1,int _chr,long long _st1,long long _ed1,char *str2,int _chr2,long long _st2,long long _ed2);
    int chr,st,ed,length;
    //if the region is constructed by two regions in genome
    //this will be used
    int chr2,st2,ed2;
    char *agct;
};


#endif //SRCFIND_DETECTREGION_H
