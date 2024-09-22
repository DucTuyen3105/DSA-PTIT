int n; cin >> n;
	int d[5] = {0};
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		d[x]++;
	}
	int res4 = d[4];
	int res3 = d[3];
	if(d[1] >= d[3]) d[1] -= d[3];
	else d[1] = 0;
		
	int res22 = d[2] / 2;
	
	int res211 = 0;
	if(d[2] % 2 == 1){
		res211++;
		if(d[1] >= 2) d[1] -= 2;
		else d[1] = 0;
	}
	
	int res1111 = d[1] / 4;
	if(d[1] % 4 != 0) res1111++;
	
	cout << res4 + res3 + res22 + res211 + res1111;
