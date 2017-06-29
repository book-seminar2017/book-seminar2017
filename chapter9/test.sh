#!/bin/bash

code=$1

set -u

[ "$code" == "" ] && code="template.c"

# This is setting for C users
compile="gcc -Wall $code"
exec_command="./a.out"

# for example python users
# compile=""
# exec_command="python $code"

test_sets="A1 B1 C1 C2"

temp=$(mktemp aojtest.XXXXXX)
trap "rm $temp" EXIT

$compile
for case in $test_sets; do
  echo [case $case]
  $exec_command < input/${case}.txt > $temp
  if diff -u output/${case}.txt $temp; then
    echo OK
  fi
done