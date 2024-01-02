class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int[] freq = new int[nums.length + 1];
        
        for (int c: nums){
            if (freq[c] >= ans.size()) {
                ans.add(new ArrayList());
            }
            ans.get(freq[c]).add(c);
            freq[c]++;
        }
        return ans;
    }
}