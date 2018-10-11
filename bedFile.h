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


class bedFile {
public:
    bedFile(char *fileName,char *agct);
    void solAndPrint();
    std::vector<basicInfo> myRegion;
    char *agct;
};


#endif //SRCFIND_BEDFILE_H
