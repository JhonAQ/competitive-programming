#!/bin/bash

# Mostrar cómo usar el script si no se proporcionan argumentos o se solicita ayuda
usage() {
    echo "Uso: $0 <nombre_del_archivo> <ruta_destino>"
    echo
    echo "Este script mueve un archivo al destino especificado y actualiza un archivo de problema relacionado."
    echo
    echo "Argumentos:"
    echo "  <nombre_del_archivo>   Nombre del archivo que se va a mover."
    echo "  <ruta_destino>         Ruta donde se moverá el archivo. (sin ./)"
    exit 1
}

# Verificar si se proporcionaron menos de dos argumentos
if [ "$#" -lt 2 ]; then
    usage
fi

fileName=$1
path=$2

# Mover el archivo
mv "$fileName" "$path" 

read -p "Cree un nuevo problema local y presione una tecla para continuar"

# Encontrar archivos relacionados
probFileSurce=$(find ./.cph -name ".$fileName*" -type f | head -n 1)
probFileDest=$(find ./$path/.cph -name ".$fileName*" -type f | head -n 1)

# Actualizar archivo de problema con la nueva ruta
command="sed -i 's#$fileName#$path/$fileName#g' $probFileSurce"
eval $command

# Copiar el archivo de problema
cp "$probFileSurce" "$probFileDest"
