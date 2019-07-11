#include<iostream>
#include<algorithm>
using namespace std;
struct item
{
    int value,weight;
};
bool cmp(item a,item b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}
double fknapsack(int w,item *arr,int n)
{
    sort(arr,arr+n,cmp);
    int curweight=0;
    double finale=0.0;
    for(int i=0;i<n;i++)
    {
        if(curweight+arr[i].weight<=w)
        {
            curweight=curweight+arr[i].weight;
            finale=finale+arr[i].value;
        }
        else
        {
            int remain=w-curweight;
            finale+=arr[i].value*(remain*1.0/arr[i].weight);
            break;
        }
    }
    return finale;
}
int main()
{
    int w,n;
    cin>>w>>n;
    item arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].value>>arr[i].weight;
    }
    cout<<"Maximum value obtained "<<fknapsack(w,arr,n);
    return 0;
}
