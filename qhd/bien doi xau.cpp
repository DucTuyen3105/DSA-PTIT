#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
int f[102][102]; // f[i][j] : so phep bien doi it nhat de bien s1[1:i] thanh s2[1:j]
                 //  dap an: f[n][m] -> so phep bien doi it nhat de s1->s2
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;
 
    // co so qhd
    for (int i = 1; i <= m; i++)
    {
        f[0][i] = i; // xau rong thanh xau s2[1:i] -> chen i ky tu
    }
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = i; // xau co i ky tu thanh xau rong -> delete i lan
    }
 
    // cong thuc qhd
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i] == s2[j])
            {
                f[i][j] = f[i - 1][j - 1];
            }
            else
            {
                f[i][j] = min({
                              f[i - 1][j],    // su dung delete
                              f[i][j - 1],    // su dung insert
                              f[i - 1][j - 1] // su dung replace
                          }) +
                          1; // chi phi
            }
        }
    }
    cout << f[n][m];
    return 0;
}
