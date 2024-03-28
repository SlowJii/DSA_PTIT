#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// main
int main(int argc, char const *argv[])
{
    /*code*/
    int t;
    cin >> t;
    while (t--)
    {
        int a[1001], n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        if (n % 2 == 0)
        {
            for (int i = 0; i < n / 2; i++)
            {
                cout << a[n - i - 1] << " " << a[i] << " ";
            }
        }
        else
        {
            for (int i = 0; i <= n / 2; i++)
            {
                if (i == n / 2)
                {
                    cout << a[i] << " ";
                }
                else
                {
                    cout << a[n - i - 1] << " " << a[i] << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}