#include <cstring>
#include<string>
#include<math.h>
#include<iostream>
using namespace std;

int search(int n,int pr[], int len);

//Function to find whether the number is present in prime numbers array or not
int search(int n,int pr[], int len)
{
	int i;
	for(i=0;i<len;i++)
	    {
	        if(n==pr[i])          //if number is present return 1
	        return 1;
	    }

	    if(i>=len)               //return 0 if the number is absent
	    return 0;
}

int  main ()
{
	int N = 100;                 // Number of elements in an array
	int a[N];					//  Array to store numbers from 1 to 100
	int prime_count = 0;       // Number of prime numbers between 0 and 100 is initialized to 0
	int prime[prime_count];    //Array to store the list of prime numbers
	int i = 0;
	for(i=0;i<=1;i++)
	{
		a[i] = 0;
	}
	for (i=2; i<=100; i++)
	{
		a[i] = i;
	}

	for (i = 2 ;i<sqrt(N); i++)
	{
		if(a[i] != 0)
			for	(int j = i*i ; j<=N; j=j+i)
			{
				a[j] = 0;
			}
	}

    // Printing the array of primes using Sieve of Eratosthenes

		cout<<"Primes:"<<endl<<endl;
			for(i=1; i<=100; i++)
			{
				if(a[i] == 0)
					cout<<".\t";
				else if(a[i] !=0)
					cout <<a[i]<<"\t";
				if((i%10) == 0)
					cout<<endl;

			}

	// 	Segregating the prime numbers from array a[] and copying to array prime[]
	int j=0;
	for (i = 0 ; i<100 ; i++)
	{
		if(a[i] != 0)
		{
		  prime_count++;
		  prime[j] = a[i];
		  j++;

		}
	}

	cout <<endl<<"Test of Goldbach's Conjecture:"<<endl<<endl;

	for (int x=4; x<=100; x=x+2)
	{
		cout<<x<<":";
	for(i=2; i<=x/2; ++i)
	    {
	        // condition for i to be a prime number
	        if (search(i,prime,prime_count) == 1)
	        {
	        // condition for n-i to be a prime number
	            if (search((x-i),prime,prime_count) == 1)
	            {
	        // n = primeNumber1 + primeNumber2

	            	cout<<"\t"<<i<<"\t"<<(x-i);
	            	cout <<endl;


	            }

	        }
	    }
	if (x<100)
	cout <<endl;
	}
}
