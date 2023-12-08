class Solution {
    public String largestOddNumber(String num) {
        if((int)num.charAt(num.length()-1)%2==1) return num;
      
        for (int i = num.length() - 1; i >= 0; i--) {
           int n=num.charAt(i);
            if(n%2 == 1) return num.substring(0,i+1);
        }
        return "";
    }
}