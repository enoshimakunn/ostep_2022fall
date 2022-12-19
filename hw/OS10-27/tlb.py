import os
import numpy as np
import matplotlib.pyplot as plt

if __name__ == '__main__':
    os.system('gcc tlb.c -o tlb.out -O0')
    if os.path.exists('out.txt'):
        os.remove('out.txt')
    for i in range(20):
        os.system(f'./tlb.out {pow(2, i)} 100000')
        #os.system(f'./tlb.out {i} 100000')
    
    f = open('out.txt')
    x_space = []
    y_space = []
    for line in f.readlines():
        [x, y] = line.split('\t')
        #x = float(x)
        y = float(y)
        x_space.append(x)
        y_space.append(y)
    
    #plt.plot(x_space, y_space, color='c')
    plt.plot(x_space, y_space, color='c')
    plt.xlabel('Number of Pages')
    plt.ylabel('Time per Access (ns)')
    plt.title('TLB Size Measurement')
    #plt.show()
    plt.savefig('test_result.png')