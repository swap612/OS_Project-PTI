for size in 512K 1M 10M 100M ;
do 
	#fname=$1_$size
 	cat $1_$size | while read line; do
	x=$(( x+1 ))
	if [[ $x -eq "2" || $x -eq "4" || $x -eq "6" || $x -eq "8" || $x -eq "10" || $x -eq "12"  ]]; then
	echo $line >> r_$1

  	fi
if [[ $x -eq "3" || $x -eq "5" || $x -eq "7" || $x -eq "9" || $x -eq "11" || $x -eq "13"  ]]; then
        echo $line >> w_$1

        fi
	
	done
	
	echo " " >> r_$1
	echo " " >> w_$1 
done


