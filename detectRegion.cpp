//
// Created by ttbond on 18-9-16.
//

#include <cstring>
#include "detectRegion.h"

char *detectRegion::base=new char[5];
bool detectRegion::firstRegion=true;
int detectRegion::maxMismatchNum=2;
int detectRegion::maxDetectLen=1000;
int detectRegion::minDetectLen=1;


detectRegion::detectRegion(char *str,int _chr,long long _st,long long _ed){
    if(firstRegion){
        base[0]='A';
        base[1]='G';
        base[2]='C';
        base[3]='T';
        base[4]='\0';
        firstRegion=false;
    }
    st=_st;
    ed=_ed;
    chr=_chr;
    length=ed-st+1;
    cacheLen=length*4+10;
    agct=new char[length+10];
    char *i=agct,*j=str+st-1,*charEd=str+ed-1;
    for(;j<=charEd;j++,i++){
        (*i)=(*j);
    }
    (*i)='\0';
    agctEnd=agct+length;
    firstBasePos=NULL;
    cacheForDfs=new int[cacheLen];
    reverseComScore=NULL;
    firstBasePos2=NULL;
    detectRel=new int[length+10];
}

//region2 should be at the letf region of region1
detectRegion::detectRegion(char *str1,int _chr,long long _st1,long long _ed1,char *str2,int _chr2,long long _st2,long long _ed2){
    if(firstRegion){
        base[0]='A';
        base[1]='G';
        base[2]='C';
        base[3]='T';
        base[4]='\0';
        firstRegion=false;
    }
    st=_st1;
    ed=_ed1;
    chr=_chr;
    st2=_st2;
    ed2=_ed2;
    chr2=_chr2;
    length=(ed-st+1)+(ed2-st2+1);
    cacheLen=length*4+10;
    agct=new char[length+10];
    char *i=agct,*j=str1+st-1,*charEd=str1+ed-1;
    for(;j<=charEd;j++,i++){
        (*i)=(*j);
    }
    j=str2+st2-1;
    charEd=str2+ed2-1;
    for(;j<=charEd;j++,i++){
        (*i)=(*j);
    }
    (*i)='\0';
    agctEnd=agct+length;
    firstBasePos=NULL;
    cacheForDfs=new int[cacheLen];
    reverseComScore=NULL;
    firstBasePos2=NULL;
    detectRel=new int[length+10];
}

void detectRegion::localizeFirstBasePos(){
    releaseFirstBasePos(firstBasePos);
    firstBasePos=new int*[4];
    for(int **i=firstBasePos;i<firstBasePos+4;i++){
        (*i)=new int[cacheLen];
    }
    for(int i=0;i<4;i++){
        indEndOfFirstBasePos[i]=firstBasePos[i];
    }
    for(char *i=agct;i<agctEnd;i++){
        for(char *j=base;j<base+4;j++){
            if((*i)==(*j)){
                int id=j-base;
                *(indEndOfFirstBasePos[id]++)=i-agct;
                break;
            }
        }
    }
}

void detectRegion::releaseFirstBasePos(int **&_firstBasePos){
    if(_firstBasePos!=NULL){
        for(int i=0;i<4;i++){
            delete _firstBasePos[i];
        }
    }
    delete _firstBasePos;
    _firstBasePos=NULL;
}

void detectRegion::release(double *&toRelease){
    if(toRelease!=NULL){
        delete toRelease;
    }
    toRelease=NULL;
}
void detectRegion::release(int *&toRelease){
    if(toRelease!=NULL){
        delete toRelease;
    }
    toRelease=NULL;
}

void detectRegion::releaseDetectRel(){
    memset(detectRel,0,(length+10)*sizeof(int));
}

int *detectRegion::getInitMisSt(int iteNum,int **_firstBasePos,int *_cacheForDfs){
    if(_firstBasePos==NULL){
        puts("firstBasePos hasn't been loacalized");
        exit(-1);
    }
    return _cacheForDfs;
}
int *detectRegion::getInitMisEd(int iteNum,int **_firstBasePos,int *_cacheForDfs){
    if(_firstBasePos==NULL){
        puts("firstBasePos hasn't been loacalized");
        exit(-1);
    }
    return _cacheForDfs+(indEndOfFirstBasePos[iteNum]-firstBasePos[iteNum]);
}

void detectRegion::copyFirstBasePos(){
    if(firstBasePos==NULL){
        puts("No firstBasePos to copy");
        exit(-1);
    }
    releaseFirstBasePos(firstBasePos2);
    firstBasePos2=new int*[4];
    for(int **i=firstBasePos2;i<firstBasePos2+4;i++){
        (*i)=new int[cacheLen];
    }
    for(int i=0;i<4;i++){
        indEndOfFirstBasePos2[i]=firstBasePos2[i];
        for(int *j=firstBasePos[i];j<indEndOfFirstBasePos[i];j++){
            *(indEndOfFirstBasePos2[i]++)=(*j);
        }
    }
    cacheForDfs2=new int[cacheLen];
    memset(cacheForDfs2,0,cacheLen*sizeof(int));
}

void detectRegion::printDetectRel(FILE *fp){
    for(int i=0;i<length;i++){
        printf("%d ",detectRel[i]);
    }
    printf("\n");
    return;
    std::vector<int>::iterator it;
    std::vector<int> tmp[maxDetectLen+10];
    for(int i=0;i<length;i++){
        tmp[detectRel[i]].push_back(i);
    }
    if(fp==NULL){
        for(int i=0;i<length;i++){
            printf("%d ",detectRel[i]);
        }
        printf("\n");
        for(int i=0;i<maxDetectLen;i++){
            if(tmp[i].size()>0){
                printf("=%d: ",i);
                for(it=tmp[i].begin();it!=tmp[i].end();it++){
                    printf("%d ",*it);
                }
                printf("\n");
            }
        }
    }
    else{
        for(int i=0;i<length;i++){
            fprintf(fp,"%d ",detectRel[i]);
        }
        fprintf(fp,"\n");
        for(int i=0;i<maxDetectLen;i++){
            if(tmp[i].size()>0){
                fprintf(fp,"=%d: ",i);
                for(it=tmp[i].begin();it!=tmp[i].end();it++){
                    fprintf(fp,"%d ",*it);
                }
                fprintf(fp,"\n");
            }
        }
    }
}

void detectRegion::getReverseComScore(){
    release(reverseComScore);
    releaseDetectRel();
    reverseComScore=new double[length+10];
    memset(cacheForDfs,0,cacheLen*sizeof(int));
    localizeFirstBasePos();
    copyFirstBasePos();
    for(int i=0;i<4;i++){
        int comBaseNum=nuc2int(getComBase(int2nuc(i)));
        revComDfs(firstBasePos[i],indEndOfFirstBasePos[i],getInitMisSt(i,firstBasePos,cacheForDfs),getInitMisEd(i,firstBasePos,cacheForDfs),firstBasePos2[comBaseNum],indEndOfFirstBasePos2[comBaseNum],getInitMisSt(comBaseNum,firstBasePos2,cacheForDfs2),getInitMisEd(comBaseNum,firstBasePos2,cacheForDfs2),1);
    }
}

void detectRegion:: revComDfs(int *st,int *ed,int *misMatchSt,int *misMatchEd,int *st2,int *ed2,int *misMatchSt2,int *misMatchEd2,int depth){
    /*
    printf("%d\n",depth);
    for(int *nst=st;nst<ed;nst++){
        printf("%d ",*nst);
    }
    puts("");
    for(int *nst=misMatchSt;nst<misMatchEd;nst++){
        printf("%d ",*nst);
    }
    puts("");

    for(int *nst=st2;nst<ed2;nst++){
        printf("%d ",*nst);
    }
    puts("");
    for(int *nst=misMatchSt2;nst<misMatchEd2;nst++){
        printf("%d ",*nst);
    }
    puts("");
    getchar();
    */
    for(char *nuc=base;nuc<base+4;nuc++) {
        int *nst=ed,*ned=ed;
        int *nmst = misMatchEd, *nmed = misMatchEd;
        bool returnFlag=false;
        for(int *tst=st,*tmst=misMatchSt;tst<ed;tst++,tmst++){
            int partial=(*tst)+depth;
            char *nowBase=agct+partial;
            if(nowBase<agctEnd&&*nowBase!='N'){
                if(*nowBase==*nuc){
                    *(ned++)=*tst;
                    *(nmed++)=*tmst;
                }
                else{
                    if(*tmst<maxMismatchNum){
                        *(ned++)=*tst;
                        *(nmed++)=(*tmst)+1;
                    }
                    else{
                        if(depth>=minDetectLen){
                            detectRel[*tst]=max(depth,detectRel[*tst]);
                        }
                    }
                }
            }
            else{
                if(depth>=minDetectLen){
                    detectRel[*tst]=max(depth,detectRel[*tst]);
                }
            }
        }

        char tarBase=getComBase(*nuc);
        int *nst2=ed2,*ned2=ed2;
        int *nmst2 = misMatchEd2, *nmed2 = misMatchEd2;
        for(int *tst=st2,*tmst=misMatchSt2;tst<ed2;tst++,tmst++){
            int partial=(*tst)-depth;
            char *nowBase=agct+partial;
            if(nowBase>=agct&&*nowBase!='N'){
                if(tarBase==*nowBase){
                    *(ned2++)=*tst;
                    *(nmed2++)=*tmst;
                }
                else{
                    if(*tmst<maxMismatchNum){
                        *(ned2++)=*tst;
                        *(nmed2++)=(*tmst)+1;
                    }
                }
            }
        }

        if(nst==ned||nst2==ned2||depth>maxDetectLen){
            for(;nst<ned;nst++){
                detectRel[*nst]=max(detectRel[*nst],depth);
            }
        }
        else{
            revComDfs(nst,ned,nmst,nmed,nst2,ned2,nmst2,nmed2,depth+1);
        }
    }
}