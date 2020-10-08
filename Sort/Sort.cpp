#include<iostream>
using namespace std;

void BubbleSort(int a[],int n)
{
    int flag;
    for(int i=0;i<n-1;i++)
    {
        flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            return;
        }
    }
}

void InsertionSort(int a[],int n)
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)        
        {
            if(a[j]>temp)
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }
        }
    }
    a[j+1]=temp;
}

void SelectionSort(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(a[k]>a[j])
            {
                k=j;
            }
        }
        int temp;
        temp=a[i];
        a[i]=a[k];
        a[k]=temp;
    }
}

int main()
{
    int a[100];
    int n;
    cout<<"ENTER TOTAL NUMBER OF ELEMENTS"<<endl;
    cin>>n;
    cout<<"NOW ENTER THE NUMBERS"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    SelectionSort(a,n);
    cout<<"THE SORTED LIST IS ===>"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}
