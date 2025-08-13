#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    map<int , string> m ;
    m[101] = "abhay";
    m[102] = "shokeen";
    m[103] = "sindhu";

    m[102] = "sarna"; //overwrite hojaega

    // cout<<m[102]<<endl;
    // cout<<m[121]<<endl;

    // cout<< m.count(102)<<endl;//1
    // cout<< m.count(112)<<endl;//0

    for(auto ite : m){
        cout<<"key: "<<ite.first<<", value: "<<ite.second<<endl;
    }

}
