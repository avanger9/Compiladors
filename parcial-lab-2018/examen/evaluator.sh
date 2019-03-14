#! /bin/bash

score=0
for jp in jps/*.json; do

    bname=`basename $jp .json` 
    ./json2xml < $jp >& $bname.tmp
    if [[ $? > 1 ]]; then
        cat $bname.tmp
        rm -f $bname.tmp
        exit
    fi

    if ( grep -q '<OBJECT>' $bname.tmp ); then
        xmllint -format -encode utf8 $bname.tmp > $bname.out
    else
        mv $bname.tmp $bname.out
    fi

    error=`diff jps/$bname.out $bname.out | wc -l`
    if [[ $error == 0 ]]; then
       s="OK"
    else 
       s="NO"
    fi
    echo "$jp: $s"
    
    rm -f $bname.tmp $bname.out    
done
