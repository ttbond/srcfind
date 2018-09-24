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

mirScrFile<-file("chr1MirRep.scr",'r')
dirScrFile<-file("chr1DirRep.scr",'r')
revScrFile<-file("chr1RevRep.scr",'r')
lineNum<-0
while(TRUE){
  rangeData=readLineToStrList(revScrFile)
  readLineToStrList(mirScrFile)
  readLineToStrList(dirScrFile)
  if(length(rangeData)==0){
    break
  }
  pos<-c(as.numeric(rangeData[2]):as.numeric(rangeData[3]))
  scoreData<-readLineToNumList(revScrFile)
  typeData<-c(rep('rev',length(scoreData)),rep('dir',length(scoreData)),rep('mir',length(scoreData)))
  scoreData<-c(scoreData,readLineToNumList(dirScrFile))
  scoreData<-c(scoreData,readLineToNumList(mirScrFile))
  
  imageData<-data.frame(pos,scoreData,typeData)
  scoreImage<-ggplot()+
    geom_line(data=imageData,aes(x=pos,y=scoreData,color=typeData))
  png(filename=paste('./chr1All/',paste(paste('chr',rangeData[1],sep=''),rangeData[2],rangeData[3],rangeData[4],sep='_'),'.png',sep=''),width=1755,height=566)
  print(scoreImage)
  dev.off()
}
mirScrFile.close()
dirScrFile.close()
revScrFile.close()