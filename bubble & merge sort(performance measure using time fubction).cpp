#include<iostream>
#include<ctime>
using namespace std;
void bubblesort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;++i)
	{
		for(j=0;j<(n-i);j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	}
}
void mergee(int a[],int i1,int j1,int i2,int j2);
void mergesort(int a[],int i,int j)
{
	int mid;

	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);
		mergesort(a,mid+1,j);
		mergee(a,i,mid,mid+1,j);
	}
}

void mergee(int a[],int i1,int j1,int i2,int j2)
{
	int temp[50];
	int i,j,k;
	i=i1;
	j=i2;
	k=0;

	while(i<=j1 && j<=j2)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}

	while(i<=j1)
		temp[k++]=a[i++];

	while(j<=j2)
		temp[k++]=a[j++];
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}
int main()
{
	int a[30],n,i;
	cout<<"Enter Number of Elements:";
	cin>>n;
	cout<<"Enter Numbers:";
	for(i=0;i<n;i++)cin>>a[i];

    clock_t t1,t2,t3,t4,diff1,diff2;
    t1=clock();
    bubblesort(a,n);
    t2=clock();
    diff1=t2-t1;
    cout<<endl<<".....Time Require For Bubble Sort....";
    cout<<endl<<"Time:"<<diff1/CLOCKS_PER_SEC<<endl;
    t3=clock();
    mergesort(a,0,n-1);
    t4=clock();
    diff2=t4-t3;
    cout<<endl<<".....Time Require For Merge Sort....";
    cout<<endl<<"Time:"<<diff2/CLOCKS_PER_SEC;
	return 0;
}


