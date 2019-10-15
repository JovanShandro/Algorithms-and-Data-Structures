import math
import time

sqrt5 = math.sqrt(5)
phi = (1+sqrt5)/2

x = [[1, 1],
	[0, 1]]

def naive (n):
	if(n == 0):
		return 0
	if(n == 1):
		return 1
	return (naive(n-1)+naive(n-2))

def bottom (x):
	a,b = 0,1
	for i in range(x):
		a,b = b,a+b
	return a
#power funciton in log n complexity
def power (a, b):
	if (b == 0):
		return 1
	elif (b%2 == 0):
		return power(a*a,b/2)
	else:
		return a * power(a*a,(b-1)/2)

def closed (d):
	return int(power(phi,d)/sqrt5 + 0.5)

def mult(m1, m2):
	m = [[1,1], [1,1]]
	m[0][0] = m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0];	
	m[0][1] = m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1];
	m[1][0] = m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0];
	m[1][1] = m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1];
	return m

mat = [[1,1], [1,0]]
def m_pow (m ,exp):
	if(exp == 0):
		return [[1, 0],[0, 1]]
	elif(exp%2 == 0):
		return m_pow(mult(m,m),exp/2)
	else:
		return mult(m,m_pow(mult(m,m),(exp-1)/2))


def matrix_fib (a):
	if(a == 0):
		return 0
	b = m_pow(mat,a)
	return b[0][1]

#loop for the naive approach
print("Naive approach:\n")
done = False
while (not done):
	nr = int(input("n:"))
	a = time.time()
	naive(nr)
	b = time.time()
	c = b-a
	print(f"n = {nr}: {c} seconds\n")
	if(c>0.5):
		done = True


#loop for the bottom up approach
print("Bottom up approach:\n")
done = False
while (not done):
	nr = int(input("n:"))
	a = time.time()
	bottom(nr)
	b = time.time()
	c = b-a
	print(f"n = {nr} : {c} seconds\n")
	if(c>0.5):
		done = True

#loop for the closed approach
print("Closed approach:\n")
done = False
while (not done):
	nr = int(input("n:"))
	a = time.time()
	bottom(nr)
	b = time.time()
	c = b-a
	print(f"n = {nr} : {c} seconds\n")
	if(c>0.5):
		done = True

#loop for the matrix form approach
print("Matrix approach:\n")
done = False
while (not done):
	nr = int(input("n:"))
	a = time.time()
	bottom(nr)
	b = time.time()
	c = b-a
	print(f"n = {nr} : {c} seconds\n")
	if(c>0.5):
		done = True
k = input("just so that the last value can be seen")