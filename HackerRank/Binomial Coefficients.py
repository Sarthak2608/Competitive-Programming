#!/bin/python3

import os
import sys


if __name__ == '__main__':
    t=int(input())
    while t>0:
        t-=1;
        ans=1
        n,p=map(int,input().split())
        n1=n;
        while n!=0:
            ans=(ans*(n%p+1))
            n=n//p
        print(n1+1-ans)
