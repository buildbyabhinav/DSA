#include <iostream>
using namespace std;

int main(){
    int num = 5;
    int* p = &num;
    cout<<p<<endl;
    // cout<<*p<<endl;
    // cout<<&p<<endl; 
    // // int q = &num;
    // int arr[10];
    // int *temp = &arr[0];
    // cout<<arr<<endl;
    // cout<<&arr<<endl;
    // cout<<*arr<<endl;
    // cout<<arr[0]<<endl;
    // cout<<&arr[0]<<endl;
    // cout<<temp<<endl;
    // cout<<&temp<<endl;
    // cout<<*temp<<endl;
    int** p2 = &p;
    cout<<&p<<endl;
    cout<<p2<<endl;
    return 0;
}