// Runtime: 9 ms, faster than 96.27% of Java online submissions for Sort Array By Parity.
// Memory Usage: 40.6 MB, less than 70.70% of Java online submissions for Sort Array By Parity.

class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] B = new int[A.length];

        int i, j = 0;
        
        for(i = 0 ; i < A.length ; i++)
            if(A[i] % 2 == 0)
                B[j++] = A[i];
        
        for(i = 0 ; i < A.length ; i++)
            if (A[i] % 2 == 1)
                B[j++] = A[i];
        
        return B;
    }
}