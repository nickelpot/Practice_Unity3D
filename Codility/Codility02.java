// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

// CyclicRotation
// 25%

class Solution {
    public int[] solution(int[] A, int K) {
        // write your code in Java SE 8
        
        int[] T = new int[K];
        int i, j;
        int iLen = A.length;
        if(iLen == 0)
            return A;
            
        for(i = 0 ; i < K ; i++)
            T[K-1-i] = A[iLen-1-i];

        for(i = K ; i < iLen ; i++)
            A[i] = A[i-K];
        
        for(i = 0 ; i < K ; i++)
            A[i] = T[i];
        
        return A;
    }
}