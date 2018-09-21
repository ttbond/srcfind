library(ggplot2)
readLineToNumList<- function(fileLink){
  line <- readLines(fileLink,1)
  line <- strsplit(line,' ')
  line <- unlist(line)
  return(as.numeric(line))
}
readLineToStrList<- function(fileLink){
  line <- readLines(fileLink,1)
  line <- strsplit(line,' ')
  line <- unlist(line)
  return(line)
}

scrFile<-file("chr1MirRep.scr",'r')
lineNum<-0
while(TRUE){
  rangeData<-readLineToStrList(scrFile)
  if(length(rangeData)==0){
    break
  }
  pos<-c(as.numeric(rangeData[2]):as.numeric(rangeData[3]))
  scoreData<-readLineToNumList(scrFile)
  imageData<-data.frame(pos,scoreData)
  scoreImage<-ggplot()+
    geom_line(data=imageData,aes(x=pos,y=scoreData))
  png(filename=paste('./chr1MirRep/',paste(paste('chr',rangeData[1],sep=''),rangeData[2],rangeData[3],rangeData[4],sep='_'),'.png',sep=''),width=1755,height=566)
  print(scoreImage)
  dev.off()
}
