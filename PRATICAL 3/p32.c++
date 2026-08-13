#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        int k;
        cin>>k;
        if (k==0 || k==1 || k==2)
        {
            arr[i]=k;
        }
        else
        {
            cout<<"Enter either 0 or 1 or 2"<<endl;
            cin>>arr[i];
        }
        
        
    }

    for (int  i = 0; i <= n-1; i++)
    {
        int  j = i;
        while (j>0 && arr[j-1]>arr[j])
        {
            int temp = arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
        
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}