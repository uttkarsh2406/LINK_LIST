#include<iostream>
#include<list>
using namespace std;



int josephus_circle(int n,int k){
    list<int> li;
    for (int i = 0; i < n; i++)
    {
        li.push_back(i);
    }
    auto it=li.begin();
    while(li.size()>1){
        for (int i = 1; i < k; i++)
        {
            it++;

            if(it==li.end()){
                it=li.begin();
            }
        }
        it=li.erase(it);
        if(it==li.end()){
            it=li.begin();
        }
        
    }

     return li.front();

}



int main(){
    int n,k;
    cin>>n>>k;
    cout<<josephus_circle(n,k)<<endl;


}