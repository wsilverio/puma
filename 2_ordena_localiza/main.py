import sys

tam = len(sys.argv)-1

if tam < 2:
    print "Quantidade invalida de parametros."
    exit(1)

def ordena(lista):
    tam = len(lista)
    for j in xrange(0,tam-1):
        for i in xrange(0,tam-j-1):
            if lista[i] < lista[i+1]:
                aux = lista[i+1]
                lista[i+1] = lista[i]
                lista[i] = aux
    return lista

def localiza(num, lista):
    pos = -1
    ponto1 = 0
    ponto2 = len(lista)

    while(ponto1 <= ponto2):
        meio = (ponto1+ponto2)/2

        if num == lista[meio]:
            pos = meio
            ponto2 = -1
        elif num > lista[meio]:
            ponto2 = meio-1
        else:
            ponto1 = meio+1

    return pos

lista = []
for arg in sys.argv[1:]:
    try:
        lista.append(int(arg))
    except:
        print "Caracter invalido."
        exit(1)

print "Numeros de entrada:", lista

lista = ordena(lista)
print "Vetor ordenado:", lista

num = int(raw_input("Valor a busca: "))

pos = localiza(num, lista)

if pos < 0:
    print "Valor nao encontrado."
else:
    print "Valor encontrado primeiramente na posicao: [%d] = %d" %(pos, lista[pos])
