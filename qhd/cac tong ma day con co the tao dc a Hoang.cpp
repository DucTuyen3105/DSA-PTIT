int n, s, a[202];
bool f[202][100005]; // f[i][j]: co tao duoc tong j tu cac so tu 1 den i hay khong?
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    // s la tong cac a[i]
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    // co so qhd
    f[0][0] = 1; // ta co the tao duoc tong 0 tu 0 so
    for (int i = 1; i <= n; i++)
    { // duyet cac i
        for (int j = 0; j <= s; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= a[i])
            {
                f[i][j] = max(f[i][j], f[i - 1][j - a[i]]);
            }
        }
    }
    for (int sum = 0; sum <= s; sum++)
    { // duyet cac tong xem tong nao tao duoc
        for (int i = 1; i <= n; i++)
        {
            if (f[i][sum])
            { // tao duoc tong sum voi i phan tu dau tien
                cout << sum << ' ';
                break;
            }
        }
    }
    return 0;
}
