#include <iostream>

using namespace std;

string input, bomb;

int main(void){
    cin >> input >> bomb;
    
    string answer = "";

    for (int i = 0; i < input.size(); i++){
        answer += input[i];
        if (answer[answer.size()-1] == bomb[bomb.size()-1]){
            int cnt = 1;
            
            for (int j = 0; j < bomb.size()-1; j++){
                if (answer[answer.size()-2-j] == bomb[bomb.size()-2-j]) cnt++;
                else break;
            }

            if (cnt == bomb.size()){
                for(int b = 0; b < bomb.length(); b++){
                        answer.pop_back();
                }
            }
        }
    }
    answer.size() > 0 ? cout << answer : cout << "FRULA";
    return 0;
}