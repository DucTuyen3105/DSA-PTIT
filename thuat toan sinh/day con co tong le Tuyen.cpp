#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];
int x[100];
int sum = 0;
vector<string>v;
void Try(int i, int pos) {
    for(int j = pos; j <= n; j++) {
        x[i] = a[j];
        sum += x[i];

        if(sum % 2 == 1) {
        	string temp = "";
            for(int k = 1; k <= i; k++) {
                temp += to_string(x[k]);
                if(k!=i) temp +=" ";
            }
            v.push_back(temp);
        }
        else
        Try(i + 1, j + 1); // Ti?p t?c th? v?i ph?n t? ti?p theo

        sum -= x[i]; // Lo?i b? ph?n t? cu?i cùng d? th? t? h?p khác
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Try(1, 1);
    sort(v.begin(),v.end());
    if(v.size()==0) cout<<"NOT FOUND";
    else
    {
    for(auto y : v)
    {
    	cout<<y;
    	cout<<endl;
    }
    }
    return 0;
}

