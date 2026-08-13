#include<iostream>
using namespace std;

void bubbleSort(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag=0;
        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if (flag==0)
        {
            break;
        }
        
    }
}

void selectionSort(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if(a[min]>a[j])
            {
               min = j; 
            }
        }
        swap(a[min],a[i]);
        
    }
    
}

void insertionSort(int a[],int n)
{
    for (int  i = 0; i <= n-1; i++)
    {
        int  j = i;
        while (j>0 && a[j-1]>a[j])
        {
            int temp = a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            j--;
        }
        
    }
}


int main()
{
    int n;
    cout<<"enter total number of marksheets:";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    insertionSort(a,n);
    cout<<endl<<"Insertion Sort:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<", ";
    }
    selectionSort(a,n);
    cout<<endl<<"Selection Sort:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<", ";
    }
    bubbleSort(a,n);
    cout<<endl<<"Bubble Sort:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<", ";
    }
    
    return 0;
}