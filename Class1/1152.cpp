#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int cnt = 0;
    bool inWord = false;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' ' && !inWord){
            inWord = true;
            cnt++;
        }
        else if(s[i] == ' '){
            inWord = false;
        }
    }
    cout << cnt;
    return 0;
}
