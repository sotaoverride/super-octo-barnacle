class Solution {
public:
    double myPow(double x, int n) {
        if ( n < 0 ) return ((1/ (myPow(x,((n+1)*-1))) *(1/x)));
       if( n == 0) return 1;
        else if (n%2 == 0) {double tmp=myPow(x, n/2); return (tmp*tmp);}
        else return (x * myPow(x, n-1));
    }
};
