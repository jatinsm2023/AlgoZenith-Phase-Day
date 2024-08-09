#include <bits/stdc++.h>
using namespace std;

#define int long long
#define print(v)          \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << endl;
#define yes() cout << 'YES<<endl';
#define no() cout << 'NO<<endl';
using state = pair<int, int>;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    vector<int> sieve(b - a + 1, 1);
    vector<int> primes(sqrt(b) + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i <= sqrt(b); i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j <= sqrt(b); j += i)
            {
                primes[j] = 0;
            }
        }
    }
    for (int i = 2; i < primes.size(); i++)
    {
        if (primes[i] == 1)
        {
            int curmul = ((a - i + 1) / i) * i;
            while(curmul<=b){
                if(curmul>=a && curmul!=i){
                    sieve[curmul-a] = 0;
                }
                curmul+=i;
            }
        }
    }
    int num = 0;
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i] == 1 && i + a != 1)
        {
            num++;
        }
    }
    cout<<num<<'\n';
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i] == 1 && i + a != 1)
        {
            
            cout << i + a << ' ';
        }
    }
}