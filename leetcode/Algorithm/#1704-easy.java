class Solution {
    public boolean halvesAreAlike(String s) {
        char[] ss = (s.toLowerCase()).toCharArray();
        int a = 0, b = 0;

        for (int i = 0; i < ss.length; i++) {
            if (isVowel(ss[i])) {
                System.out.println(ss[i]);
                if (i < ss.length / 2) a++;
                else b++;
            }
        }
        
        return a == b;
    }

    public boolean isVowel(char input) {
        char[] vowels = {'a', 'e', 'i', 'o', 'u'};
        for (char vowel: vowels) {
            System.out.print(vowel);
            if (vowel == input) return true;
        }
        return false;
    }
}