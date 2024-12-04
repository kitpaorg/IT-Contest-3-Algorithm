import sys
input=lambda:sys.stdin.readline().rstrip()
Q=int(input())
P=input()
hf=[0];hb=[0];mhf=[0];mhb=[0]
elf=[];elb=[]
C=0;i=0
for c in P:
    if c=='(':
        elf.append('(')
        hf.append(hf[-1]+1)
        mhf.append(mhf[-1])
    if c==')':
        elf.append(')')
        hf.append(hf[-1]-1)
        mhf.append(min(hf[-1],mhf[-1]))
    if c=='<':
        if not elf:
            pass
        elif elf[-1]=='(':
            elf.pop()
            hf.pop()
            mhf.pop()
            elb.append('(')
            hb.append(hb[-1]-1)
            mhb.append(min(hb[-1],mhb[-1]))
        else:
            elf.pop()
            hf.pop()
            mhf.pop()
            elb.append(')')
            hb.append(hb[-1]+1)
            mhb.append(mhb[-1])
    if c=='>':
        if not elb:
            pass
        elif elb[-1]==')':
            elb.pop()
            hb.pop()
            mhb.pop()
            elf.append(')')
            hf.append(hf[-1]-1)
            mhf.append(min(hf[-1],mhf[-1]))
        else:
            elb.pop()
            hb.pop()
            mhb.pop()
            elf.append('(')
            hf.append(hf[-1]+1)
            mhf.append(mhf[-1])
    if c=='X':
        if elf:
            elf.pop()
            hf.pop()
            mhf.pop()
    i+=1
    if mhf[-1]>=0 and mhb[-1]>=0 and hf[-1]==hb[-1]:
        C^=i
    #print(elf,[*reversed(elb)])
    #print(hf,[*reversed(hb)])
    #print(mhf,[*reversed(mhb)])
assert i==Q
print(C)
