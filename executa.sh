#!/bin/bash
#

instancias=(t60_00 t60_05 t60_10 t60_15 t120_00 t120_10 u120_00 u120_05 u120_10 u120_15)
sementes=(0 1 2 3 4 5 6 7 8 9)
sufixo=NBOX_DECODER2N

rm saida/* 2> /dev/null

echo "Instance,Best,Avg,SD,Avg Time" > saida/saida_${sufixo}.txt

for inst in ${instancias[@]}; do
	echo "Processando ${inst} ..."


	for seed in ${sementes[@]}; do
		 ./binp -i instances/${inst} -p 100 -g 100 -s ${seed} >> saida/${inst}_${sufixo}
	done
	
	Rscript tabelasVal.r saida/${inst}_${sufixo} ${inst} | cut -d " " -f 2-10 |  sed 's/ /,/g' >> saida/saida_${sufixo}.txt
done