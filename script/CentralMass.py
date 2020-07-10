import re
import math
import	numpy	as	np


with open("X_3872.txt","r")as f:
    msm = f.readlines()
    f.close()


event2 = []
#list2 =['0','0']
i = 0
while i < len(msm):
    try:
        #a = re.findall("\d+.\d+",msm[i])
        #b = re.findall("\d+.\d+",msm[i+2])


        a = re.findall(r'\d+\.?\d*',msm[i])
        b = re.findall(r'\d+\.?\d*',msm[i+2])

        print (a)
        print (b)
        print "-----------------"
        c = float(a[10])-float(b[10]) 
        d = float(a[11])-float(b[11])    
        f = float(a[12])-float(b[12])
        e = float(math.sqrt(c*c+d*d+f*f))  #ralatitive momentum
        print"relatitive momentum"
        print(e)
        n = float(a[10])*float(a[10])+float(a[11])*float(a[11])+float(a[12])*float(a[12])
        f = float(math.sqrt(n))  #|D0|
        print"D0 absolute value"
        print(f)
        o = float(b[10])*float(b[10])+float(b[11])*float(b[11])+float(b[12])*float(b[12])
        g = float(math.sqrt(o))  #|D*0|
        print"D*_bar0 absolute value"
        print(g)
        h = float(float(a[10])*float(b[10])+float(a[11])*float(b[11])+float(a[12])*float(b[12]))
        j = float(h/(g*f))   #costha
        print"theta"
        print(j)
        p = float(2*f*g*j*j)
        print(p)
        k = float(math.sqrt(float(a[14])*float(a[14])+float(b[14])*float(b[14])+2*float(a[13])*float(b[13])-p)) #central mass energy
        print"cm energy"
        print(k)
        m = float(e*float(b[14])/k)
        print (m)

        if m < 0.3:
         
            event2.append(msm[i])
            #event2.extend(list2)
            event2.append(msm[i+2])
            #event2.extend(list2)
    except:
        pass
    i += 4
#print (event2)

num2 = 0
f2 = open("p_star.txt","w")
for line2 in event2:
    f2.write(str(line2)+"\n")
    num2 +=1
f2.close()

