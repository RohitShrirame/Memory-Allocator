#include<iostream>
using namespace std;
class Allocator {
private:
    int* arr = 0;
    int en = 0;
    int st = 0;
    int spaceoccupied = 0;
public:
    Allocator(int n) {
        en = n;
        arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = -1;
        }
        cout<<"The initialised Memory array is"<<" [";
        print();
    }
    void print(){
        for(int i=0; i<en; i++){
            cout<<arr[i]<<" ";
        }cout<<"]";
    }
    void rehash(){
        int p=0,q=0;
        while( q < en ){
            if( arr[q] != -1 ){
                swap(arr[p++],arr[q]);
            }
            q++;
        }
        cout<<endl<<"After Rehashing the array Becomes [";
        print();
    }
    int allocate(int size, int mID) {
        if( en-spaceoccupied < size ){
            cout<<"We can not find any free block with "<<size<<" consecutive free memory units"<<endl;
            cout<<"The array remains same [";
            print();
            return -1;
        }
        else{
            int i = 0, j=0;
            while( j < en ){
                if( j-i == size ){
                    break;
                }
                else if( arr[j] == -1 )
                    j++;
                else{
                    j++;
                    i = j;
                }                 
            }
            if( j-i == size ){
                for(int p=i; p<j; p++){
                    arr[p] = mID;
                    spaceoccupied++;
                }
                cout<<"The leftmost block's first index is "<<i<<"."<<endl;
                cout<<"The Memory array becomes [";
                print();
                return i;
            }
            else{
                cout<<"Memory of size "<<size<<" is available but its not consecutive"<<endl;
                cout<<"So we need to rehash "<<endl;
                cout<<"The array before rehashing is [";
                print();
                rehash();
                int p = spaceoccupied;
                int s = p+size;
                while( p < s ){
                    arr[p++] = mID;
                }
                cout<<endl<<"The leftmost block's first index is "<<spaceoccupied<<"."<<endl;
                cout<<"The Memory array becomes [";
                print();
                return spaceoccupied;
            }
            cout<<"We can not find any free block with "<<size<<" consecutive free memory units"<<endl;
            cout<<"The array remains same [";
            print();
            return -1;
        }
    }
    
    int free(int mID) {
        int cnt =0;
        for(int i=0; i<en;i++){
            if( arr[i] == mID ){
                cnt++;
                arr[i] = -1;
                spaceoccupied--;
            }
        }
        if( cnt ){
            cout<<"Freed "<<cnt<<" memory units with mID "<<mID<<"."<<endl;
            cout<<" The memory array becomes [";
            print();
        }
        else{
            cout<<"The memory array remains the same since there is no memory unit with mID "<<mID<<endl;
        }
        return cnt;
    }
};