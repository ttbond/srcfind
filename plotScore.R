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

scrFile<-file("chr1.scr",'r')
lineNum<-0
while(TRUE){
  rangeData=readLineToNumList(scrFile)
  if(length(rangeData)==0){
    break
  }
  pos<-c(rangeData[2]:rangeData[3])
  scoreData<-readLineToNumList(scrFile)
  imageData<-data.frame(pos,scoreData)
  scoreImage<-ggplot(data=imageData,aes(x=pos,y=scoreData))+
    geom_line(size=0.9)
  png(filename=paste(paste(paste('chr',as.character(rangeData[1]),sep=''),as.character(rangeData[2]),as.character(rangeData[3]),sep='_'),'.png',sep=''),width=874,height=566)
  print(scoreImage)
  dev.off()
  break
}
