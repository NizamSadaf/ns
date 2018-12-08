#include<iostream>
using namespace std;
void bubblesort(int a[],int n)
{
    if(n==1) return ;

    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1]) //Check korlam j kono element boro naki thakle swap hobe
        {
            int temp;
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
     }//swap hoar por array update hobe
     bubblesort(a,n-1);// jehetu ekta element kore swap tai oi element guli ar swap erdorkr hobena tai n-1 hoise element
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
