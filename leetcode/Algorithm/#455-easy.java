class Solution {
    public int findContentChildren(int[] g, int[] s) {
        if (s.length == 0) return 0;
        
        int cnt = 0;
        int j = 0, i = 0;

        Arrays.sort(g);
        Arrays.sort(s);
        
        while (i < g.length && j < s.length) {
            if (g[i] > s[j]){ 
                if (j < s.length) j++;
                else break;
            }
            else {
                cnt++;
                i++; j++;    
            }
        }

        return cnt;
    }
}