import re
import math
import	numpy	as	np


with open("p_star","r")as f:
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
        c = float(a[10])+float(b[10]) 
        d = float(a[11])+float(b[11])    
        f = float(a[12])+float(b[12])
        e = float(math.sqrt(c*c + d*d))

        print "pt"        
        print (e)

        h =float(a[10])-float(b[10])
        m =float(a[11])-float(b[11])
        n =float(a[12])-float(b[12])

        E_q =float(a[13])+float(b[13])     # E_q
        E_k =float(a[13])-float(b[13])     # E_k
 
        o =float(c*h+d*m+f*n)       
       
        h =float(c*c+d*d+f*f)
        q =float(math.sqrt(h))      #|q|
        p =float(h*h+m*m+n*n)
        k =float(math.sqrt(p))   #|k|

        costha =float(o/(k*q)) #costha
        k_par =float(k*costha)   #k perallel
        beta =float(q/E_q)
        print"costha"
        print (costha)
        r =float(1-(beta*beta))

        gama = float(math.sqrt(r))
        print"gama"
        print (gama)

        k_star_par = float(-gama*beta*E_k + gama*k_par) #k parallel
        k_star_ver =float(math.sqrt(h*h+m*m))  #k vertical
        print"k_star_par"
        print (k_star_par)

        print"k_star_ver"
        print (k_star_ver)
        k_star =float(math.sqrt(k_star_par*k_star_par+k_star_ver*k_star_ver))
        print (k_star)

        if k_star<1:
         
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

