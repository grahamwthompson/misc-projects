#!/usr/bin/env python

def print_byte(mybyte):
    ''' Prints out a text representation of bits in a bytearray of length 1'''

    for onebyte in mybyte:
        for i in range(8):
            print('{}'.format( (onebyte >> i) & 1), end='')
        print('\n')

# start here do stuff
with open('random.txt', 'rb') as f:
    mybyte = True
    while mybyte:
        mybyte = f.read(1)

        print('base: ')
        print_byte(mybyte)

        print('and 1')
        print_byte(mybyte[0] & 1)
