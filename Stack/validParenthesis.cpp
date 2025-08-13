#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string str){
    stack<char> s;
    for(int i =0;i<str.size();i++){
        char ch = str[i];
        if(ch=='{' || ch=='[' || ch=='('){//opening bracket
            s.push(ch);
        }else{//closing bracket
            if(s.empty()){
                return false;
            }

            //match
            if((s.top()=='{' && ch=='}') ||
            (s.top()=='[' && ch==']') ||
            (s.top()=='(' && ch==')')){
                s.pop();
            }else{
                return false;
            }
        }

    }
    return s.empty();
};

bool isDuplicate(string str){
    stack<char> storage;
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(ch!=')'){ //not closing bracket
            storage.push(ch);
        }
        else{
            if(storage.top()=='('){
                return true; //means it is a duplicate
            }
            while(storage.top() != '('){
                storage.pop();
            }
            storage.pop();
            
        }
    }
    return false; // not duplicate
};

int main(){
    string str1 = "{[()]}";
    string str2 = "[{(]})"; 
    // cout<<isValid(str1)<<endl;
    // cout<<isValid(str2)<<endl;

    string str3 = "((a)+(b))";
    string str4 = "((a)+((b))";
    cout<<isDuplicate(str3)<<endl; // no duplicate , should return false(0)
    cout<<isDuplicate(str4)<<endl; // duplicate , should return true(1)
return 0;
}