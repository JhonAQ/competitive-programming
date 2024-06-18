#!/bin/bash

fileName=$1
path=$2

mv $fileName $path 

read -p "Cree un nuevo problema local y presione una tecla para continuar"

probFileSurce=$(find ./.cph -name ".$fileName*" -type f | head -n 1)
probFileDest=$(find ./$path/.cph -name ".$fileName*" -type f | head -n 1)

command="sed -i 's#$fileName#$path/$fileName#g' $probFileSurce"

echo $command
eval $command

cp $probFileSurce $probFileDest


