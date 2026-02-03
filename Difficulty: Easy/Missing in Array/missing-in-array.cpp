// User function template for C++
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
       long long sum = 0;
        int n = arr.size();
        
        // Calculate the sum of the array elements
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        
        // Calculate the expected sum using the formula for the sum of the first n natural numbers
        long long expectedSum = (long long)(n + 1) * (n + 2) / 2;
        
        // The missing number will be the difference between the expected sum and the actual sum
        return expectedSum - sum;
 
    }
};
