# itr count 100 = 2kb 100000 = 2Mb 10000000 = 200Mb
#for itr_count in 100000000;
for itr_count in 1 10 100 1000 10000 100000 1000000 10000000 ;
do
	rm $1_fw_$itr_count	
	for i in {1..10} ;
	do
		./fw demo1_$itr_count $itr_count >> $1_fw_$itr_count
	done
done
