#include<iostream>
#include<queue>
using namespace std;

void firstNonRepeating(string str){// O(n)
    queue<char> q;
    int frq[26] = {0};
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        frq[ch-'a']++;
        q.push(ch);
        while(!q.empty() && frq[q.front()-'a']>1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1"<<endl;
        }else{
            cout<<q.front()<<endl;
        }
    }
};

int main(){
    string str = "aabccxb";
    firstNonRepeating(str);
return 0;
}
