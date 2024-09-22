ll crossing_sum(int a[], int l, int mid, int r){
	ll sum_left = 0, max_sum_left = 0;
	ll sum_right = 0, max_sum_right = 0;
	for(int i = mid; i >= l; i--){
		sum_left += a[i];
		max_sum_left = max(max_sum_left, sum_left);
	} 
	for(int i = mid+1; i <= r; i++){
		sum_right += a[i];
		max_sum_right = max(max_sum_right, sum_right);
	}
	return max_sum_left + max_sum_right;
}
ll xuly(int a[], int l, int r){
	if(l == r) return a[l];
	int mid = (l + r) / 2;
	return max({
		xuly(a, l, mid),
		xuly(a, mid+1, r),
		crossing_sum(a, l, mid, r)	
	});
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    cout << xuly(a, 0, n-1);
}	

	
