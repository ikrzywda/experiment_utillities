#!/usr/bin/python

import sys
import numpy as np
from matplotlib import pyplot as plt

def parse_data(filename):

    data = np.genfromtxt(filename, delimiter=',',names=["x", "y"])

    for i in data:
        i['x'] = ((5/1024) * i['x']) * 10000
        i['y'] = (5/1024) * i['y'] 

    return data

def plot(data):
    plt.plot(data['x'], data['y'])

    plt.xlabel('R2 [ohms]')
    plt.ylabel('ouptut voltage [V]')
    plt.title(sys.argv[2])

    plt.savefig(sys.argv[2] + '.png')
    plt.show()


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print('compute_data <input csv> <plot name>')
        exit()
    plot(parse_data(sys.argv[1]))
