#include<iostream>
#include<string>
#include<vector>
#include"Allocator.h"
using namespace std;
void initialise(){
    cout<<endl;
    cout<<"      Choose the operation you want to perform "<<endl;
    cout<<endl;
    cout<<"1 : Allocate a block of size consecutive free memory units and assign it the id mID"<<endl;
    cout<<"2 : Free all memory units with the given id mID. "<<endl;
    cout<<"0 : To exit"<<endl;
}
void create(Allocator* arr){
    cout<<" Enter the size and id mID separated by a space "<<endl;
    int s,MiD;
    cin>>s>>MiD;
    arr->allocate(s,MiD);
}
void freed(Allocator* arr){
    cout<<"Enter the id mID you want to free"<<endl;
    int id; cin>>id;
    arr->free(id);
}
void start(Allocator* arr){
    bool flag = true;
    while( flag ){

        initialise();
        int t; cin>>t;
        switch(t)
        {
            case 0:
                flag = 0;
                cout<<"You have succesfully exited"<<endl;
                break;
            case 1:
                create(arr);
                break;

            case 2: freed(arr);
                break;
        }
    }
}
int main(){
    
    cout<<" Enter the size of memory array you want to create "<<endl;
    int n; cin>>n;
    Allocator* nums = new Allocator(n);

    start(nums);

    return 0;
}
