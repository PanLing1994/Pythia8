import os
import linecache

root = '/home/pling/pythia8243/examples/tt'
file_names = os.listdir(root)
file_ob_list = []
for file_name in file_names:
    fileob = file_name
    file_ob_list.append(fileob)

j = 0
while j <  len(file_ob_list):
    with open(file_ob_list[j],"r") as f:
        msms = f.readlines()
        f.close()
    j += 1
    for i in msms:
        if "D" in i and "D*bar" in msms[msms.index(i)+1]:
            print(i)
            print(msms[msms.index(i)+1])
            print "---------------------"



