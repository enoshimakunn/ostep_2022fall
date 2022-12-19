import os
import matplotlib.pyplot as plt
import numpy as np

'''
pList = ['FIFO', 'LRU', 'OPT', 'UNOPT', 'RAND', 'CLOCK']
CList = ['1', '2', '3', '4', '5']
file_name = 'addrfile.txt'
out = 'out.txt'
outptr = open(out, 'w')

for p in pList:
    for C in CList:
        outfile = f'output_{p}_{C}.txt'
        os.system(f'python3 paging-policy.py -C {C} -p {p} -f {file_name} -c >{outfile}')
        fptr = open(outfile, 'r')
        hitrate = fptr.readlines()[-3].split(' ')[-1]
        print(hitrate)
        outptr.write(f'{p}\t{C}\t{hitrate}\n')
        
outptr_rd = open(out, 'r')
for line in outptr_rd.readlines():
    p_val = line.split('\t')[0]
    C_val = line.split('\t')[1]
    hrate = line.split('\t')[2]
'''

result = [[45.85, 92.79, 96.27, 97.31, 97.76], [45.85, 94.97, 97.25, 98.08, 98.37], [45.85, 95.10, 97.74, 98.53, 98.85]]  
x_list = [1, 2, 3, 4, 5]
plist = ['FIFO', 'LRU', 'OPT']
colorlist = ['m', 'c', 'g']
i = 0
for y_list in result:
    plt.plot(x_list, y_list, color=colorlist[i], linewidth=0.5, linestyle='-', )
    i += 1

plt.legend(plist)
plt.xlabel('Cache Size')
plt.ylabel('Hitrate')
plt.savefig('result.png', dpi=216)