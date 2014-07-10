import itertools
def gcd (a,b):
	if a==0:
		return b
	elif b==0:
		return a
	else:
		if a >= b:
			return gcd(b,a%b)
		else:
			return gcd(a,b%a)
def LCM(a,b):
	return (a*b//gcd(a,b))
			
def unvis(all,k,n):
	for i in range (k,n):
		if all[i]==0:
			return i
	return -1
	
def main():
	v=[]
	ar=[]
	tr=[]
	t=int(input())
	while t>0:
		del v[:]
		n=int(input())
		tr[:]=itertools.repeat(0,n)
		ar=map(int,raw_input().split())
		q=0
		while q!=-1:
			rem=q
			cyclen=0
			while True:
				tr[q]=1
				q=ar[q]-1
				cyclen=cyclen+1
				if q==rem:
					break
			v.append(cyclen)
			q=unvis(tr,rem,n)
		lcm=1
		l=len(v)
		for i in range (0,l):
			lcm=LCM(lcm,v[i])
		lcm=lcm%1000000007
		print lcm
		t=t-1
	return 0

main()	
