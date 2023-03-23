#!/bin/bash

# Be sure that this file has execution permissions:
# Use the nautilus explorer or chmod +x run_vad.sh

# Write here the name and path of your program and database
DIR_P2=$HOME/PAV/P2
DB=$DIR_P2/db.v4
CMD=$DIR_P2/bin/vad 

for PARAM1 in $(seq 1.0 .01 1.1);
do
    for PARAM2 in $(seq 1.0 .01 1.1);
    do
        for filewav in $DB/*/*wav; 
        do
            filevad=${filewav/.wav/.vad}
            $CMD -i $filewav -o $filevad -1 $PARAM1 -2 $PARAM2 || exit 1
            scripts/vad_evaluation_noverb.pl $DB/*/*lab
        done
    done
done

exit 0
