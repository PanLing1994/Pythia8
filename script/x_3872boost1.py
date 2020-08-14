import re
import math
import	numpy	as	np


with open("p_star1","r")as f:
    msm = f.readlines()
    f.close()

numbers = 0
event2 = []
#list2 =['0','0']
i = 0
while i < len(msm):
    try:

        a = re.findall("-?\d+\.?\d*",msm[i])
        b = re.findall("-?\d+\.?\d*",msm[i+2])
#       a = re.findall(r'\d+\.?\d*',msm[i])
#      b = re.findall(r'\d+\.?\d*',msm[i+2])

        print (a)
        print (b)
        print "-----------------"
        c = float(a[10])-float(b[10]) 
        d = float(a[11])-float(b[11])    
        f = float(a[12])-float(b[12])
        e = float(math.sqrt(c*c + d*d+f*f))


        print (c)
        print (d)
        print (f)
        print (e)

        if e < 1:
            event2.append(msm[i])
            #event2.extend(list2)
            event2.append(msm[i+2])
            #event2.extend(list2)
            #event2.append(numbers)
            #event2.append(numbers)
    except:
        pass
    i += 4

    numbers = numbers + 4

num2 = 0
f2 = open("p_star2","w")
for line2 in event2:
    f2.write(str(line2)+"\n")
    num2 +=1
f2.close()

