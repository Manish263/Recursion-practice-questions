	int mod = (int)(1e9 + 7);
	
	vector<vector<int>> dp;
	int N;
	
	int fun(int pos, int sum, int arr[]) {
	    if (pos >= N)
	        return sum == 0;
	        
	    int &ans = dp[pos][sum];
	    if (ans != -1)
	        return ans;
	        
	   ans = 0;
	   
	   ans += fun(pos + 1, sum, arr);
	   ans %= mod;
	   if (arr[pos] <= sum)
	        ans += fun(pos + 1, sum - arr[pos], arr), ans %= mod;
	        
	   return ans;
	       
	}

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    dp.assign(n + 1, vector<int> (sum + 2, -1));
	    N = n;
	    
	    return fun(0, sum, arr);
	}
