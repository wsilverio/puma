sum = 0

while True:
    try:
        sum += float(raw_input("%s: " %sum))
    except:
        break

print sum,"\n"