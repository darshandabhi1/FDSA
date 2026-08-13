#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"ENTER THE TOTAL NUMBER OF PROCUCT:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int h;
    cout<<"ENTER HOURS:";
    cin>>h;

    h=h%n;
    for (int i = 0; i < h; i++)
    {
        int temp=a[0];
        for (int j = 0; j < n-1; j++)
        {
            a[j]=a[j+1];
        }
        a[n-1]=temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i];
    }
    
    return 0;
}