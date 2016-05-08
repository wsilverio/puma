#!/bin/bash

localiza(){
    local pos="-1"
    return "$pos"
}

TAM="$#"
VETOR=("$@")

# checa a quantidade de parametros
if [ $TAM -lt 2 ]; then    
    echo "Quantidade invalida de parametros"
    exit 1
fi    

# verifica se sao inteiros
for NUM in $VETOR
do
    if [ $NUM -eq $NUM ] > /dev/null 2>&1
    then
        : # nao faz nada
    else
        echo "Parametro invalido: $NUM"
        exit 1
    fi
done

echo "Numeros de entrada: ${VETOR[@]}"

# ORDENA
for j in $(seq 0 $[ $TAM-2 ])
do
    for i in $(seq 0 $[ $TAM-2-$j ])
    do
        if [ ${VETOR[$i]} -lt ${VETOR[$i+1]} ]; then
            aux=${VETOR[$i]}
            VETOR[$i]=${VETOR[$i+1]}
            VETOR[$i+1]=$aux
        fi
    done
done

echo "Vetor ordenado: ${VETOR[@]}"

# le a entrada
echo -n "Valor a buscar: "
read VAL

# verifica a entrada
if [ $VAL -eq $VAL ] > /dev/null 2>&1
then
    :
else
    "Caracter invalido."
    exit 1
fi

PONTO1=0
PONTO2=$[$TAM-1]
POS=-1

while [ $PONTO1 -le $PONTO2 ]
do
    MEIO=$[$[$PONTO1+$PONTO2]/2]

    if [ $VAL -eq ${VETOR[$MEIO]} ]; then
        POS=$MEIO
        PONTO2=-1
    elif [ $VAL -gt ${VETOR[$MEIO]} ]; then
        PONTO2=$[$MEIO-1]
    else
        PONTO1=$[$MEIO+1]
    fi
done

if [ $POS -eq -1 ]; then
    echo "Valor nao encontrado."
else
    echo "Valor encontrado primeiramente na posicao: [$POS] = ${VETOR[POS]}"
fi    

exit 0
