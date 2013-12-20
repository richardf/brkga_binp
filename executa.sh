#!/bin/bash
#

instancias=(t60_00 t60_01 t60_02 t60_03 t60_04 t60_05 t60_06 t60_07 t60_08 t60_09 t60_10 t60_11 t60_12 t60_13 t60_14 t60_15 t60_16 t60_17 t60_18 t60_19 t120_00 t120_01 t120_02 t120_03 t120_04 t120_05 t120_06 t120_07 t120_08 t120_09 t120_10 t120_11 t120_12 t120_13 t120_14 t120_15 t120_16 t120_17 t120_18 t120_19 t249_00 t249_01 t249_02 t249_03 t249_04 t249_05 t249_06 t249_07 t249_08 t249_09 t249_10 t249_11 t249_12 t249_13 t249_14 t249_15 t249_16 t249_17 t249_18 t249_19 t501_00 t501_01 t501_02 t501_03 t501_04 t501_05 t501_06 t501_07 t501_08 t501_09 t501_10 t501_11 t501_12 t501_13 t501_14 t501_15 t501_16 t501_17 t501_18 t501_19)
sementes=(0 1 2 3 4 5 6 7 8 9)
sufixo=FALK_DECODER2N

rm saida/* 2> /dev/null

echo "Instance,Best,Avg,SD,Avg Time" > saida/saida_${sufixo}.txt

for inst in ${instancias[@]}; do
	echo "Processando ${inst} ..."


	for seed in ${sementes[@]}; do
		 ./binp -i instances/${inst} -p 100 -g 100 -s ${seed} >> saida/${inst}_${sufixo}
	done
	
	Rscript tabelasVal.r saida/${inst}_${sufixo} ${inst} | cut -d " " -f 2-10 |  sed 's/ /,/g' >> saida/saida_${sufixo}.txt
done