filename = 'valgrind.txt'
file = open(filename, 'r')
addrfilename = 'addrfile.txt'
file_addr = open(addrfilename, 'w')

for line in file.readlines():
    if (not line.startswith('=')):
        vm = line.split(' ')[-1]
        vm = vm.split(',')[0]
        vpn = ((int('0x' + vm, 16)) & 0xfffff000) >> 12
        file_addr.write(str(vpn) + '\n')