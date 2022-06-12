#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

string convert(int n, int k){
    string s = "";
    while (n){
        long temp = n%k;
        s = s + to_string(temp);
        n /= k;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool isPrime(long num){
    if (num == 1) return false;
    else if (num == 2) return true;
    
    for (long i = 3; i <= sqrt(num); i++){
        if (num%i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s = convert(n, k), temp = "";
    
    for (long i = 0; i < s.length(); i++){
        if (s[i] == '0') {
            if (temp == "") continue;
            else {
                long num = stol(temp);
                if (isPrime(num)) answer++;
                temp = "";
            }
        }
        else {
            temp += s[i];
        }
    }   
    if (temp == "") return answer;
    
    long num = stol(temp);
    if (isPrime(num)) answer++;
    
    return answer;
}