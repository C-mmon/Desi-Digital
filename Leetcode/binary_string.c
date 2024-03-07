class Solution {
    public int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[maxLength + 1];
        f[0] = 1;
        for (int i = 1; i <= maxLength; ++i) {
          //we want this function to run atleast i-oneGroup or i-zeroGroup times
            if (i - oneGroup >= 0) {
              //fetch the solutiion of the previous 
                f[i] += f[i - oneGroup]) % mod;
            }
            if (i - zeroGroup >= 0) {
                f[i] += (f[i] + f[i - zeroGroup]) % mod;
            }
        }
        int ans = 0;

      //Calculatting the sum in the range of minimum to maximum.
        for (int i = minLength; i <= maxLength; ++i) {
            ans = (ans + f[i]) % mod;
        }
        return ans;
    }
}
