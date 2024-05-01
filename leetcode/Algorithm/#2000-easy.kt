class Solution {
    fun reversePrefix(word: String, ch: Char): String {
        var idx = word.indexOf(ch)
        return if (idx == -1) 
            word 
        else word.slice(0..idx).reversed() + word.slice(idx+1..word.length-1)
    }
}