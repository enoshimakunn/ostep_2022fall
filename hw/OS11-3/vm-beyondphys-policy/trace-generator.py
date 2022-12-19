import random 
from optparse import OptionParser

out = []

parser = OptionParser()
parser.add_option('-n', '--number', default='10', help='number of addresses to generate')
parser.add_option('-M', '--max_option', default='10', help='max address generated')

(options, args) = parser.parse_args()
num = int(options.number)
maximum = int(options.max_option)

for i in range(0, num):
    addr = random.randint(0, maximum - 1)
    out.append(addr)

print(f'Generate trace: {out}')
