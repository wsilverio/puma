# rawinput, ler arquivo, argv inteiros

import sys

LEN = len(sys.argv)

if LEN <= 2:
    print "Quantidade invalida de parametros\n"
    exit(1)

vector = sys.argv[1:]

fp = open("py_result.txt", "w+")
fp.write("Entrada: ")

for num in vector:
    fp.write("%s " % num)

for j in xrange(1, LEN-1):
    for i in xrange(0, LEN-j-1):
        if vector[i] < vector[i+1]:
            aux = vector[i]
            vector[i] = vector[i+1]
            vector[i+1] = aux

fp.write("\nSaida: ")

for num in vector:
    fp.write("%d " % int(num))

fp.close()

print vector
