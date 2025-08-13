#include<iostream>
#include<string>
using namespace std;

void removeDuplicates(string str , string ans  ,int i , int map[26]){
    if(i == str.size()){
        cout<<"ans: "<<ans<<"   ";
        return;
    }
    int mapIndx = (int)(str[i]-'a');
    if(map[mapIndx]){//duplicate
        removeDuplicates(str,ans,i+1,map);
    }else{// not duplicate
        map[mapIndx] = true;
        removeDuplicates(str,ans+str[i],i+1,map);
    }
}

int main(){
    string str = "appnacollege";
    string ans = "";
    int map[26] = {false};
    removeDuplicates(str,ans,0,map);
    return 0;
}