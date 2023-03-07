void helper(int ind,int target,vector<int>&a,vector<vector<int>>&ans,vector<int>&ds){
        int n=a.size();
        if(ind==n){
            if(target==0){
                ans.push_back(ds);
            }
            return ;
        }
//we stay at same index and reduce our target to 0 by removing element each time.
//also we keep adding element to the vector ds every time we stay at same ind also when function call will be over we need to remove it from ds so we make 
//call for not pick recursion tree.
        if(a[ind]<=target){
            ds.push_back(a[ind]);
            helper(ind,target-a[ind],a,ans,ds);
            ds.pop_back();
        }
//if target!=0 then we not pick and move to next index and keep moving until it crosses arr.size() then we return to function call.
        helper(ind+1,target,a,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
            vector<vector<int>>ans;
            vector<int>ds;
            helper(0,target,a,ans,ds);
            return ans;
    }
