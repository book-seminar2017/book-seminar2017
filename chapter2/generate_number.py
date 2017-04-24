#!/usr/bin/env python
# -*- coding: utf-8 -*-

import fileinput
import random


def main():
    f_name = 'input3.txt'
    f = open(f_name, 'w')
    min = 1
    max = 1000000000
    number = 200000
    for x in xrange(0, number):
        rand = random.randint(min, max)
        f.write(str(rand))
        f.write('\n')

if __name__ == '__main__':
    main()
