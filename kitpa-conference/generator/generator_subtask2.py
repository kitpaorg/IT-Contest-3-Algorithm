import sys
import random
import hashlib

words = ['social', 'history', 'language', 'literacy', 'bigdata', 'public', 'society']
choice = random.choice(words)
otherlen = random.randint(1, 100 - len(choice))
others = list('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ')

while True:
    leflen = random.randint(0, otherlen)
    riglen = otherlen - leflen
    out = ''
    for i in range(leflen):
        out += random.choice(others)
    out += choice
    for i in range(riglen):
        out += random.choice(others)

    chk = True
    for i in words:
        if i == choice and out.count(i) > 1:
            chk = False
        elif i != choice and i in out:
            chk = False

    if chk:
        print(out)
        break