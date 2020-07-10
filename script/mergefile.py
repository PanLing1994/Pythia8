# -*- coding:utf-8 -*-  
import os
root='/home/pling/pythia_root/pythia8/pythia8243/examples'
path='/home/pling/pythia_root/pythia8/pythia8243/examples/X_3872data' 
files=os.listdir(path) 
result=os.path.join(root,'X_3872.txt') #生成最终txt文件(X_3872.txt)的路径 
with open(result,'w') as r:
    for i in range(1,54): 
        print(i) 
        fname=str(i) 
        filename=os.path.join(path,fname) 
        with open(filename,'r') as f: 
            for line in f:
                r.writelines(line)
            r.write('\n')


