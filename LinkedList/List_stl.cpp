#include<iostream>
#include<list>
using namespace std;

void printlist(list<int>ll){
    list<int>::iterator itr;
    for(itr=ll.begin();itr!=ll.end();itr++){
        cout<<(*itr)<<"->";
    }
    cout<<"NULL"<<endl;
}

int main(){
    list<int> ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    printlist(ll);

    cout<<"size: "<<ll.size()<<endl;
    cout<<"head = "<<ll.front()<<endl;
    cout<<"tail = "<<ll.back()<<endl;
    ll.pop_back();
    ll.pop_front();
    printlist(ll);
    return 0;

}