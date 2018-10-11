from collections import defaultdict

contig="/home/ttbond/桌面/srcfind/geneExons/"

name2id=defaultdict(int)
id2name=defaultdict(str)
isCancerGene=defaultdict(int)
cancerGenef=open(contig+"cancer_associatedGenes.txt")
while True:
    cancerGene=cancerGenef.readline()
    if cancerGene=='':
        break
    cancerGene=cancerGene.split('\n')[0]
    isCancerGene[cancerGene]=1
cancerGenef.close()
namef=open(contig+"geneExon.bed")
nameIdf=open(contig+"geneExonId.bed",'w')
cancerGenef=open(contig+"geneExonCancer.bed",'w')
noCancerGenef=open(contig+"geneExonNoCancer.bed",'w')
id=1
while True:
    name=namef.readline()
    if name=='':
        break
    record=name
    name=name.split('\t')[3].split('\n')[0]
    if name2id[name]==0:
        name2id[name]=id
        id2name[id]=name
        id=id+1
    record=record.split('\n')[0].split('\t')
    record[3]=str(name2id[name])
    for i in range(0,4):
        print(record[i],end='\t',file=nameIdf)
    print('',file=nameIdf)
    if isCancerGene[name]!=0:
        for i in range(0, 4):
            print(record[i], end='\t', file=cancerGenef)
        print('', file=cancerGenef)
    else:
        for i in range(0, 4):
            print(record[i], end='\t', file=noCancerGenef)
        print('', file=noCancerGenef)
namef.close()
nameIdf.close()
cancerGenef.close()
noCancerGenef.close()
namef=open(contig+"name2id.dat","w")
for id in id2name:
    print(id,id2name[id],file=namef)
namef.close()
