#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

ll _sieve_size;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes;           // compact list of primes in form of vector<int>

// first part

void sieve(ll upperbound)
{                                 // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set();                     // set all bits to 1
    bs[0] = bs[1] = 0;            // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i])
        {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i); // also add this vector containing list of primes
        }
} // call this method in main method

int main()
{
    
}