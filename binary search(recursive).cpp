#include<iostream>
using namespace std;
void sortt(int a[],int n)
{
    if(n==1) return ;


        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                int temp;
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
         sortt(a,n-1);
}
int binarysearch(int a[],int beg,int eend,int x)
{
    int mid;
    mid=(beg+eend)/2;
    if(a[mid]==x) return mid;
        if(x>a[mid])
        {
            //beg=mid+1;
            return binarysearch (a,mid+1,eend,x);
        }
        else
        {
            //eend=mid-1;
            return binarysearch (a,beg,mid-1,x);
        }
}
int main()
{
    int n,x,i,pos,beg=0;
    cout<<"Enter Number of Item:";
    cin>>n;
    int a[n];
    cout<<"Enter Elements:";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sortt(a,n);
    cout<<"Sorted Array:";
    for(i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl<<"Enter Searching Item:";
    cin>>x;
    pos=binarysearch(a,beg,n-1,x);
    cout<<"Position:"<<pos+1;
    return 0;
}
