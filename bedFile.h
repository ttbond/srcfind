//
// Created by ttbond on 18-10-11.
//

#ifndef SRCFIND_BEDFILE_H
#define SRCFIND_BEDFILE_H

#include<vector>

#include"basicInfo.h"
#include"basicInfo.cpp"
#include"detectRegion.h"
#include"detectRegion.cpp"
#include"ttbond_fa.h"
#include"solRel.h"
#include"solRel.cpp"


class bedFile {
public:
    bedFile(char *fileName,char *_agct);
    bedFile(std::vector<basicInfo> _source,char *_agct);
    void solAndPrint(char *fileName,char *writeType);
    std::vector<basicInfo> myRegion;
    std::vector<solRel> myRel;
    char *agct;
};


#endif //SRCFIND_BEDFILE_H
