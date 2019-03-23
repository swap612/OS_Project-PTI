for size in 512K 1M 10M 100M ;
do 
 	cat $1_$size | while read line; do
	x=$(( x+1 ))
	if [ $x -eq "35" ]; then
	echo $line
    	break
  	fi
	done
done


