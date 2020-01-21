#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#define ll long long
using namespace std;

bool isPrime(ll n)
{
        bool ans = true;
        for(ll i = 2; i*i <= n; ++i)
        {
                if(n % i == 0) 
                {
                        ans = false;
                         break;
                }
        }
        return ans;
}

ll gcd(ll a, ll b) 
{ 
        if (a < b) 
                return gcd(b, a); 
        if (a % b == 0) 
                return b; 
        return gcd(b, a % b); 
} 

int main()
{

//generating random prime numbers and calculating n 

        ll p, q;
        srand(time(0));
        while (1)
        {
                p = rand();
                if (isPrime(p)) break;
        }
        while (1)
        {
                q = rand();
                if (isPrime(q)) break;
        }
        ll n=p*q;
        cout << endl;        
        cout << "p: " << p << endl;
        cout << "q: " << q << endl;
        cout << "n: " << n << endl;        

// calculating Euler's totient function

        ll phi = (p-1)*(q-1);

// calculating e        

        ll e = 3;
        while (e < phi)
        {
                if (gcd(e, phi) == 1) break;
                else e++;
        }        
        cout << "e: " << e << endl;        

// calculating d

        ll d;
        ll a = 1;
        while (1)
        {
                a=a+phi;
                if (a%e == 0)
                {
                        d = a/e;
                        break;
                }
        }
        cout << "d: " << d << endl;

// printing out keys

        cout << endl;        
        cout << "public key (e, n): " << e << ", " << n <<  endl;
        cout << "private key (d, n): " << d << ", " << n << endl;
        cout << endl;

// recieving message (int)

        ll m;
        cout << "enter message (int): ";
        cin >> m;

// encrypting 

        ll c = pow(m, e);
        c = fmod(c, n);
        cout << "encypted message: " << c << endl;

// decypting

        ll decrypted_m = pow(c, d);
        decrypted_m = fmod(decrypted_m, n);
        cout << "decrypted message: " << m << endl;
        cout << endl;
        
}
