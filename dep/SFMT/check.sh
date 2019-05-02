#!/bin/sh
bit_len=$1
prefix=$2
tmp=tmp.$$
tmp64=tmp64.$$
exps="607 1279 2281 4253 11213 19937 44497 86243 132049 216091"
for mexp in $exps; do
    if [ $bit_len = "64" ]; then
	./test-std-M${mexp} -b64 > $tmp64
	compare=$tmp64
    else
	compare=SFMT.${mexp}.out.txt
    fi
    command=${prefix}-M${mexp}
    if ./$command -b${bit_len}> $tmp; then
	:;
    else
	echo $command exexute error!
	rm -f $tmp
	if [ -n "$tmp64" ] && [ -e $tmp64 ]; then
	    rm -f $tmp64
	fi
	exit 1
    fi
    if diff -q -w $tmp $compare; then
	echo $command output check OK
	rm -f $tmp
    else
	echo $command output check NG!
	rm -f $tmp
	if [ -n "$tmp64" ] && [ -e $tmp64 ]; then
	    rm -f $tmp64
	fi
	exit 1
    fi
done
if [ -n "$tmp64" ] && [ -e $tmp64 ]; then
    rm -f $tmp64
fi
exit 0
