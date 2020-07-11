#!/usr/bin/env python

with open("out_10.log","r") as f:
    msms = f.readlines()
    f.close()

file1 = open('X_3872.txt','w+')

num = 0
event = []
for i in msms:
    if "PYTHIA Event Listing  (complete event) " in i:
        num += 1
        for j in event:
            if "psi(2S)" in j:
                for k in event: 
                    if "D*bar0"in k:
                        print(j)
                        print(k)
                        print "---------------------"
                        event = []
                        file1.write(j+'\n')
                        file1.write(k+'\n')

    event.append(i)
file1.close()
print num
