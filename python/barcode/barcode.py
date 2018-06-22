import sys, argparse
import math
import numpy as np
from PIL import Image

MIN_DIM = 400


def encode(msg, out_name):
    msg = msg + '#END'
    msg_bytes = len(msg)
    img_side = int( math.ceil(math.sqrt(msg_bytes)) )
    print 'Message Bytes: ' + str(msg_bytes) + '\nImage Dimensions: ' + str(img_side) + ' ' + str(img_side)

    if img_side < MIN_DIM:
        img_side = MIN_DIM

    test = np.zeros((img_side, img_side, 3), 'uint8')

    count = 0
    maxp = (img_side * img_side) * 3
    while count < maxp:
        test[ (count/3) / img_side , (count/3) % img_side, count%3] = ord(msg[ count % msg_bytes ])
        count +=1

    testimg = Image.fromarray(test, mode=None)
    testimg.save(out_name + '.png')


def decode(infile):
    try:
        img = Image.open(infile)
    except IOError:
        print 'Error opening file: ' + infile
        return 0

    in_data = np.asarray(img, dtype=np.uint8)
    img_side = in_data.shape[0]

    count = 0
    endcode = [u'#', u'E', u'N', u'D']
    endbuff = ['a', 'b', 'c', 'd']
    message = []
    maxp = (img_side * img_side) * 3
    while count < maxp:
        code = in_data[ (count/3) / img_side , (count/3) % img_side, count%3]
        endbuff.append(chr(code))
        del endbuff[0]
        message.append(chr(code))

        if endcode == endbuff:
            print 'Finished Reading Message...'
            return ''.join(message)

        count +=1

    #print message
    print 'Message not Found...'
    return 0



def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("input", help="filename or message to decode/encode")
    parser.add_argument("-e", "--encode", action="store_true", help="encode message")
    parser.add_argument("-d", "--decode", action="store_true", help="decode message")
    args = parser.parse_args()

    if args.decode and args.encode:
        print 'Please select only one option'
        return 1
    if not args.decode and not args.encode:
        print 'Please select at least one option'
        return 1
    if args.decode:
        print 'decoding...'
        msg = decode(args.input)
        if msg:
            print msg
    if args.encode:
        print 'encoding...'
        encode(args.input, 'output')




if __name__ == "__main__":
    main()
