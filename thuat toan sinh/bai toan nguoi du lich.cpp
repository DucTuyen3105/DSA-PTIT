#include<bits/stdc++.h>
using namespace std;
int n;
int c[100][100];
int x[100];
int _min = INT_MAX; int sum = 0; int ans = INT_MAX;
int visited[100]; // danh dau xem thanh pho nao dc tham
void nhap()
{ 
    cin>>n;
	for(int i = 1 ; i <= n ; i++)		
	{
	    for(int j = 1 ; j <= n ; j++)
	    {
	    	cin>>c[i][j];
	    	if(c[i][j])_min = min(c[i][j],_min);
	    }
	}
}
void Try(int i)
{
	//x[i] xac dinh luot thu i tham thanh pho nao
	for(int j = 1 ; j <= n ; j++)
	{
		if(visited[j]==0)
		{
			x[i] = j;
			visited[j] = 1;
			sum+= c[x[i-1]][x[i]]; // x[i-1] thanh pho o buoc truoc dang tham, x[i] là thành pho hien tai
			if(i==n)
			{
				ans = min(ans, sum + c[x[i]][x[1]]);// cong them chi phi di tu thanh pho cuoi cung ve thanh pho 1
				// vi con buoc quay lui nen chi dc cong gia tien cuoi cung vao sum khi cap nhat
			}
			/*else // chua danh gia can
			{
				Try(i+1);
			}*/
			// danh gia can duoi
			else if(sum + (n-i+1)*_min < ans) // n - i + 1 so thanh pho con phai di cong them 1 la tu thanh pho cuoi cung ve thanh pho thu 1
			{                                // danh gia rang di nhung thanh pho con lai voi chi phi nho nhat ( chap nhan luon )
			    Try(i+1);
			}                               // danh gia chi phi toi uu nhat nguoi day phai di de co the tao ra dap an tot nhat
			                                // neu co thi se tao ra dap an nho hon con 0 thi ko can quay lui	
			visited[j] = 0;
			sum-= c[x[i-1]][x[i]]; // quay lui tra lai nhung gi da su dung
		}
	}
}
int main()
{
	nhap();
	x[1] = 1; // luon xuat phat tu thanh pho thu nhat
	visited[1] = 1;
	Try(2);
	cout<<ans;
}
				
			
