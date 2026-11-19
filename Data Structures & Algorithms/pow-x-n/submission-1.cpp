class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0){
            x = 1/x;
            n = -n;
        }

        if (n == 0)
            return 1;
        
        double temp = myPow(x, n/2);
        double result = temp * temp;
        if (n%2 == 1){
            result *= x;
        }

        return result;


    }
};
