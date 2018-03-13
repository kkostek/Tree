#!/bin/bash
# atom, atom shellcheck

if [[ $# = 2 ]]; then
    vv=""
else
    vv="-v"
    shift
fi

OUT=xd.out
ERR=xd.err

for f in $2/*.in; do
    j=${f%.in}
    i=${j:10}    
    ./$1 $vv <$f >$OUT 2>$ERR
    echo ${i}    
    if [[ $(diff ${f:0:(-3)}.out $OUT) ]]; then echo "ŹLE"
    else echo "DOBRZE"
    fi

    if [[ $vv = "-v" ]]; then
    if [[ $(diff ${f:0:(-3)}.err $ERR) ]]; then echo "ŹLE"
    else echo "DOBRZE"
    fi
    fi
done

rm $OUT $ERR
