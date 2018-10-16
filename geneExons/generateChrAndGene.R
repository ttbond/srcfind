library(plyr)
library(ggplot2)
gene=read.table("questionCancerGene.bed",header=FALSE)
gene[,1]<-as.character(gene[,1])
gene[which(gene[,1]=='X'),1]=23
gene[which(gene[,1]=='Y'),1]=24
gene[,1]<-as.numeric(gene[,1])
gene<-data.frame(gene)
gene<-gene[order(gene$V1,gene$V2,gene$V3),]
gene<-ddply(gene, .(V1,V2,V3), head, n = 1)
ran<-gene[,2]
ran<-data.frame(ran)
ggplot(ran,aes(x=ran))+geom_density()

