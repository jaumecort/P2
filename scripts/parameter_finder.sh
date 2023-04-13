#!/bin/bash

# Be sure that this file has execution permissions:
# Use the nautilus explorer or chmod +x run_vad.sh

# Write here the name and path of your program and database
DIR_P2=$HOME/PAV/P2
DB=$DIR_P2/db.v4
CMD=$DIR_P2/bin/vad 

BESTSCORE=0

echo "" > out.txt

for PARAM1 in $(seq 3 .05 3.5);
do
    for PARAM2 in $(seq 4.3 .05 4.7);
    do
        echo -e -n "\rVAD with alpha1=$PARAM1 and alpha2=$PARAM2"

        for filewav in $DB/*/*wav; 
        do
            filevad=${filewav/.wav/.vad}
            $CMD -i $filewav -o $filevad -1 $PARAM1 -2 $PARAM2 || exit 1
        done

        A=$(scripts/vad_evaluation_noverb.pl $DB/*/*lab)

        if ! echo "$A $BESTSCORE -p" | dc | grep > /dev/null ^-; then
            BESTSCORE=$A
            BESTP1=$PARAM1
            BESTP2=$PARAM2
            clear
            echo "New Best score $BESTSCORE with parameters alpha1=$BESTP1 and alpha2=$BESTP2"
        fi

        echo "$PARAM1 $PARAM2 $A" >> out.txt

        #echo $($A-100)
    done
done
python3 scripts/biplot.py out.txt
exit 0
