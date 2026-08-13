#include<iostream>
using namespace std;

void iterative(int car[],int target , int n)
{
    cout<<"ITERATIVE:"<<endl;
    for (int i = 0; i < n; i++)
    {
        if(target==car[i])
        {
            cout<<"Car found at "<<i+1<<endl;
            continue;
        }
    }
}
int Recursive(int car[], int n, int target, int i)
{
    if (i >= n)
    {
        return -1;      
    }

    if (car[i] == target)
    {
        cout<<"Car found at "<<i+1<<endl; 
    }

    return Recursive(car, n, target, i+1);
}
int main()
{
    int n;
    cout<<"Enter the total number of cars in parking lot:";
    cin>>n;
    int car[n];
    for (int i = 0; i < n; i++)
    {
        cin>>car[i];
    }
    
    int target;

    cout<<"Enter target plate number:"<<endl;
    cin>>target;

    iterative(car,target,n);
    cout<<"RECURSIVE:"<<endl;
    Recursive(car,n,target,0);


    return 0;
}