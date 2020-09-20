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

        a = re.findall("-?\d+\.?\d*",msm[i])
        b = re.findall("-?\d+\.?\d*",msm[i+2])

#        a = re.findall(r'\d+\.?\d*',msm[i])
 #       b = re.findall(r'\d+\.?\d*',msm[i+2])

        print (a)
        print (b)
        print "-----------------"
        c = float(a[10])+float(b[10]) 
        d = float(a[11])+float(b[11])    
        f = float(a[12])+float(b[12])
        q_absolute_value = float(math.sqrt(c*c + d*d + f*f))#|q|

        E_q =float(a[13])+float(b[13])     # E_q
        print "|q|"        
        print (q_absolute_value)

        h =float(a[10])-float(b[10])
        m =float(a[11])-float(b[11])
        n =float(a[12])-float(b[12])
        k_absolute_value = float(math.sqrt(h*h + m*m + n*n)) #|k|
        E_k =float(a[13])-float(b[13])     # E_k
        
        print "|k|"
        print(k_absolute_value)

        o =float(c*h+d*m+f*n)       

        costha =float(o/(k_absolute_value*q_absolute_value)) #costha
        k_par =float(k_absolute_value*costha)   #k perallel in lab frame
        k_ver = float(k_absolute_value*math.sqrt(1-costha*costha))# k vertical in lab frame

        print "costha"
        print(costha)
        print "k perallel in lab frame"
        print(k_par)
        print "k vertical in lab frame"
        print(k_ver)
        
  
        beta =float(q_absolute_value/E_q)
        gama =float(1/math.sqrt(1-beta*beta))
        
        print "beta"
        print(beta)
        print "gama"
        print(gama)

        k_star_par = float(-gama*beta*E_k + gama*k_par) #k parallel in central of mass
        k_star_ver = k_ver  #k vertical in central of mass

        print"k parallel in central of mass"
        print(k_star_par)
        print"k vertical in central of mass"
        print(k_star_ver)

        k_star =float(math.sqrt(k_star_par*k_star_par+k_star_ver*k_star_ver))
        print (k_star)

        if k_star<0.5:
         
            event2.append(msm[i])
            #event2.extend(list2)
            event2.append(msm[i+2])
            #event2.extend(list2)
    except:
        pass
    i += 4
#print (event2)

num2 = 0
f2 = open("p_star1.txt","w")
for line2 in event2:
    f2.write(str(line2)+"\n")
    num2 +=1
f2.close()

