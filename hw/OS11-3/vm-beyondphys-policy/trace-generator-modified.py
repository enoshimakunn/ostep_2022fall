import random 
from optparse import OptionParser

out = []

parser = OptionParser()
parser.add_option('-n', '--number', default='10', help='number of addresses to generate')
parser.add_option('-M', '--max_option', default='10', help='max address generated')
parser.add_option('-t', '--threshold', default='0.8', help='threshold for locality')

(options, args) = parser.parse_args()
num = int(options.number)
maximum = int(options.max_option)
focus = int(maximum / 3)
threshold = float(options.threshold)

for i in range(0, num):
    key = random.random()
    print(key)
    if key >= threshold:
        addr = random.randint(focus, maximum - 1)
    else:
        addr = random.randint(0, focus - 1)
    out.append(addr)

print(f'Generate trace: {out}')