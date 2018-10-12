//
// Created by ttbond on 18-10-12.
//

#ifndef SRCFIND_GENEREGION_H
#define SRCFIND_GENEREGION_H
//
// Created by ttbond on 18-10-9.
//

#include "geneRegion.h"

class geneRegion{
public:
    geneRegion(int init);
    geneRegion(char *source,char *_agct);
    static int geneRegion::firstGeneRegion;
    static int geneRegion::refChr;
    static std::map<int,std::string> geneRegion::id2name;
    static std::set<int> geneRegion::allGeneId;
    void addRegion(char *source);
    void addRegion(int _chr,long long _st,long long _ed);
    void solAndPrintRel(FILE *fp);
};


#endif //SRCFIND_GENEREGION_H
