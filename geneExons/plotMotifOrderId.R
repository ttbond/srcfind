r#plot one vs orderId
library(ggplot2)
region<-read.table("geneExonCancer.gms",header=FALSE)
region<-data.frame(region)
dataNames<-c('gene','orderId','dir','mir','inv','range')
colnames(region)<-dataNames
region<-subset(region,region$orderId<=30)
region<-subset(region,region$mir<50)
region<-subset(region,region$dir<50)
region<-subset(region,region$inv<50)
region$orderId<-factor(region$orderId)
bp<-ggplot(data=region,aes(x=orderId,y=inv))+
  geom_boxplot()
print(bp)

#plot mul vs orderId
region<-read.table("geneExonCancer.gms",header=FALSE)
region<-data.frame(region)
dataNames<-c('gene','orderId','dir','mir','inv')
colnames(region)<-dataNames
region<-subset(region,region$orderId<=10)
region<-subset(region,region$mir<50)
region<-subset(region,region$dir<50)
region<-subset(region,region$inv<50)
region<-data.frame(c(region$dir,region$mir,region$inv),
                   rep(region$orderId,3),
                   c(rep("dir",length(region$dir)),rep("mir",length(region$mir)),rep("inv",length(region$inv))))
colnames(region)<-c('score','orderId','type')
region$orderId<-factor(region$orderId)
bp<-ggplot(data=region,aes(x=orderId,y=score))+
  geom_boxplot(aes(fill=type))
print(bp)

#reverse orderId
region<-read.table("geneExonCancer.gms",header=FALSE)
region<-data.frame(region)
dataNames<-c('gene','orderId','dir','mir','inv')
colnames(region)<-dataNames
nowPos<-0
maxId<-0
for(j in 1:length(region$gene)){
  if(nowPos!=region[j,"gene"]){
    nowPos<-region[j,"gene"]
    maxId<-max(region[which(region$gene==region[j,"gene"]),"orderId"])
    region[which(region$gene==nowPos),"orderId"]<-maxId-region[which(region$gene==nowPos),"orderId"]+1
  }
}

#plot one score vs range
region<-read.table("geneExonCancer.gms",header=FALSE)
region<-data.frame(region)
dataNames<-c('gene','orderId','dir','mir','inv','range')
colnames(region)<-dataNames
region<-data.frame(region)
region<-subset(region,region$inv<20)
#region$inv<-region$inv * region$range
ggplot(data=region,aes(x=range,y=inv))+
  geom_point()

#plot range vs orderId
region<-read.table("geneExonCancer.gms",header=FALSE)
region<-data.frame(region)
dataNames<-c('gene','orderId','dir','mir','inv','range')
colnames(region)<-dataNames
region<-subset(region,region$orderId<=30)
region<-subset(region,region$range<5000)
region$orderId<-factor(region$orderId)
bp<-ggplot(data=region,aes(x=orderId,y=range))+
  geom_boxplot()
print(bp)

#plot exon1 with background data
lowR=200
highR=300
region<-read.table('geneExonCancer.gms',header=FALSE)
region<-data.frame(region)
dataNames<-c('gene','orderId','dir','mir','inv','range')
colnames(region)<-dataNames
region<-subset(region,region$orderId==1)
region<-data.frame(region$dir,region$mir,region$inv,region$range,rep('exon1',length(region$dir)))
dataNames<-c('dir','mir','inv','range','type')
colnames(region)<-dataNames
ggplot(region,aes(x=range))+
  geom_density()+
  coord_cartesian(xlim=c(0,1000))
region<-subset(region,region$range<=highR+30)
region<-subset(region,region$range>=highR-30)
backGround1<-read.table(paste('../backGround_',as.character(lowR),sep=''),header=FALSE)
backGround1<-data.frame(backGround1,rep(lowR,length(backGround1[,1])),rep('lowR',length(backGround1[,1])))
colnames(backGround1)<-dataNames
backGround2<-read.table(paste('../backGround_',as.character(highR),sep=''),header=FALSE)
backGround2<-data.frame(backGround2,rep(highR,length(backGround2[,1])),rep('highR',length(backGround2[,1])))
colnames(backGround2)<-dataNames
region<-rbind(region,backGround1,backGround2)
region$type<-factor(region$type,levels=(c('lowR','exon1','highR')))
#region<-subset(region,region$type=='lowR')
#region<-subset(region,region$dir<9)
bp<-ggplot(region,aes(x=type,y=inv))+
  geom_boxplot(aes(fill=type))+
  coord_cartesian(ylim=c(4,5))
print(bp)
print(length(subset(region,region$type=='exon1')[,1]))

