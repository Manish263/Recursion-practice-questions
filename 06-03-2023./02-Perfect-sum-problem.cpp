	
TIME LIMIT EXCEED SOLUTION:
const int mod = 1e9 + 7;
	int helper(int arr[],int n,int sum,int ind,int s,vector<int>&v){
	    if(ind==n){
	        if(s==sum){
	            return 1;
	        }
	        return 0;
	    }
	    
	    //first we write recursive calls to take ind elements .
	    //and add sum together.
	    int cnt=0;
	    cnt=(cnt+helper(arr,n,sum,ind+1,s+=arr[ind],v))%mod;
	    v.pop_back();
	    
	   //then we write recursive calls to not take elements 
	   //to chekc s ==sum or not
	    s-=arr[ind];
       cnt=(cnt+helper(arr,n,sum,ind+1,s,v))%mod;
      return cnt;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<int>v;
	    int cnt = helper(arr,n,sum,0,0,v);
	    
	    return cnt;
	}


ACCEPTED:

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
