gene=read.table("geneExonCancer.bed",header=FALSE)
gene[which(is.na(gene[,1])),1]=23
gene[which(gene[,1]=='Y')]=24
