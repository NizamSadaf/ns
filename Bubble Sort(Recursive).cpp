#include<iostream>
using namespace std;
void bubblesort(int a[],int n)
{
    if(n==1) return ;

    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1]) //Swapping
        {
            int temp;
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
     }
     bubblesort(a,n-1);
}
int main()
{
    int n,i;
    cout<<"Enter Number of Inputs:";
    cin>>n;
    int a[n];
    cout<<"Enter Elements:";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubblesort(a,n);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
