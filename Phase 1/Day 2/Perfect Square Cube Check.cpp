#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<long long int> square(3164);
    vector<long long int> cube(217);

    for (int i = 0; i < 3164; i++)
    {
        square[i] = i * i;
    }
    for (int i = 0; i < 217; i++)
    {
        cube[i] = i * i * i;
    }
    while (t--)
    {
        int q, n;
        bool ans = false;
        cin >> q >> n;
        if (q == 1)
        {
            for (int i = 0; i < 3164; i++)
            {
                if (square[i] == n)
                {
                    ans = true;
                    break;
                }
                else if (square[i] > n)
                {
                    ans = false;
                    break;
                }
            }
        }
        else if (q == 2)
        {
            for (int i = 0; i < 217; i++)
            {
                if (cube[i] == n)
                {
                    ans = true;
                    break;
                }
                else if (cube[i] > n)
                {
                    ans = false;
                    break;
                }
            }
        }
        if(ans==true){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}