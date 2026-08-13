#include<iostream>
using namespace std;

int iterative(int books[],int key,int high , int low)
{
    
    while (low<=high)    
    {
        int mid = high - (high-low)/2;
        if (books[mid]==key)
        {
            return mid;
        }
        else if (books[mid]>key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        } 
    }
    return -1;
}

int recursive(int books[],int key,int high , int low)
{
    
    while (low<=high)    
    {
        int mid = high - (high-low)/2;
        if (books[mid]==key)
        {
            return mid;
        }
        else if (books[mid]>key)
        {
            return recursive(books,key,mid - 1 ,low);
        }
        else
        {
            return recursive(books,key,high, mid + 1);
        } 
    }
    return -1;
}
 

int main()
{
    int n;
    cout<<"Enter total number of books:";
    cin>>n;

    int books[n];
    for (int i = 0; i < n; i++)
    {
        cin>>books[i];
    }
    
    int high = n;
    int low = 0;
    
    int key;
    cout<<"Enter the book id you want to find:";
    cin>>key;
    int result = iterative(books,key,high,low);
    if (result>-1)
    {
        cout<<"Iterative Book found at "<<result+1<<endl;
    }
    else
    {
        cout<<"404 : Book Not Found"<<endl;
    }


    int r = recursive(books,key,high,low);
    if (r>-1)
    {
        cout<<"Recursive Book found at "<<r+1<<endl;
    }
    else
    {
        cout<<"404 : Book Not Found"<<endl;
    }
    return 0;
}