double myPow(double x, int n) {
        double ans=1.0;
        long long  i=n;
        if(i<0) i=(-1)*i; //we convert all -ve integers to +ve
        while(i>0){
            if(i%2==1){ //if our power is odd then we write x=x*x^n-1
                ans=ans*x; 
                i=i-1;
            }
            else {// else toh we do x=(x*x)^n and keep dividing by 2 
                x=x*x; 
                i/=2;
            }
        }
        if(n<0) ans=1.0/ans;// if n is -ve our ans would be x=1/x.
        return ans;
