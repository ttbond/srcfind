library(plyr)
rel=read.table("geneExonCancer.gms",head=FALSE);
rel<-subset(rel,rel[,3]==0)
rel<-rel[,1]
rel<-sort(rel)
rel<-unique(rel)
print(rel)
source=read.table("geneExonCancer.bed",head=FALSE)
source<-subset(source,source[,4] %in% rel)
source<-data.frame(source)
source$V1<-as.character(source$V1)
source[which(source[,1]=='X'),1]='23'
source[which(source[,1]=='Y'),2]='24'
source$V1<-as.numeric(source$V1)
source<-source[order(source$V1,source$V2,source$V3),]
source<-ddply(source, .(V1,V2,V3), head, n = 1)
source$V1<-as.character(source$V1)
source[which(source[1,]=='23'),1]='X'
source[which(source[1,]=='24'),1]='Y'
write.table(source,"questionCancerGene.bed",quote=FALSE,row.names=FALSE,col.names=FALSE,sep='\t')
