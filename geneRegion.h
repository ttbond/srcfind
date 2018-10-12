//
// Created by ttbond on 18-10-12.
//

class geneRegion{
public:
    geneRegion(int init);
    geneRegion(char *source,char *_agct);
    void addRegion(char *source);
    void addRegion(int _chr,long long _st,long long _ed);
    void solAndPrintRel(FILE *fp);

    static int geneRegion::firstGeneRegion;
    static int geneRegion::refChr;
    static std::map<int,std::string> geneRegion::id2name;
    static std::set<int> geneRegion::allGeneId;

};
