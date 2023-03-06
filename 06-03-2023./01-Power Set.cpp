 vector<vector<int>> subsets(vector<int>& a) {
        int n=a.size(),i,j;
        vector<vector<int>>ans;
        // The loop iterates over all possible subsets
        for(i=0;i<(1<<n);i++){
            vector<int>res;
             // The inner loop checks if each element should be included in the current subset
            for(j=0;j<n;j++){
                if(i &1<<j){ // using bitwise AND to check if the jth bit is set
                //means if we are checking if and of 1 1 0 and 1 0 0 is coming out to be 1 then it means it's set bit and if turns out 0 in any case of shifting not set bit.
                    res.push_back(a[j]);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
