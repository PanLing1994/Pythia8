import re
import math
import	numpy	as	np


with open("4Pentaquarks_cut_follow.txt","r")as f:
    msm = f.readlines()
    f.close()


event2 = []
#list2 =['0','0']
i = 0
while i < len(msm):
    try:
        #a = re.findall("\d+.\d+",msm[i])
        #b = re.findall("\d+.\d+",msm[i+2])


        a = re.findall(r'-?\d+\.?\d*',msm[i])
        b = re.findall(r'-?\d+\.?\d*',msm[i+2])

        print (a)
        print (b)
        print "-----------------"
        c = float(a[10])-float(b[10]) 
        d = float(a[11])-float(b[11])    
        f = float(a[12])-float(b[12])
        e = float(math.sqrt(c*c+d*d+f*f))  #ralatitive momentum
        print(e)
        h = float(b[14])
        m = float(a[13])-float(b[13])
        print(m)
        n = float(a[14])*float(a[14])+float(b[14])*float(b[14])+2*float(m)*float(h)
        o = float(math.sqrt(n))
        print o
        g = float(e*h/o)


        print (g)

        if g < 1:
         
            event2.append(msm[i])
            #event2.extend(list2)
            event2.append(msm[i+2])
            #event2.extend(list2)
    except:
        pass
    i += 4
#print (event2)

num2 = 0
f2 = open("p_star1","w")
for line2 in event2:
    f2.write(str(line2)+"\n")
    num2 +=1
f2.close()

