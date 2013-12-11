args <- commandArgs(TRUE)

arq <- read.table(args[1], header=FALSE)
inst <- args[2]

solMin <- min(arq$V1)
solMedia <- round(mean(arq$V1), 2)
solDP <- round(sd(arq$V1), 2)
tempoMedia <- round(mean(arq$V2), 2)


saida <- paste(inst, solMin)
saida <- paste(saida, solMedia)
saida <- paste(saida, solDP)
saida <- paste(saida, tempoMedia)

print(saida, quote = FALSE)