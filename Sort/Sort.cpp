#include<iostream>
#include<bits/stdc++.h>
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

void ShellSort(int a[],int n)
{
    int step;
    int temp;
    int i,j;
    for(step=n/2;step>0;step=step/2)
    {
        for(i=step;i<n;i++)                  
        {
            temp=a[i];
            for(j=i-step;j>=0;j=j-step)
            {
                if(a[j]>temp)
                {
                    a[j+step]=a[j];
                }
                else
                {
                    break;
                }
            }
         a[j+step]=temp;
        }
    }
}

int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;
    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)
        {
            int t;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }while(i<j);
    int temp;
    temp=a[j];
    a[j]=a[l];
    a[l]=temp;

    return j;
}
void QuickSort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}

void merge(int a[], int l, int mid, int r)
{
    int i,j,k;
    int nl=mid-l+1,nr=r-mid;
    int left[nl],right[nr];
    for (i = 0; i < nl; i++) 
        left[i] = a[l+i]; 
    for (j = 0; j < nr; j++) 
        right[j] = a[mid+1+j];
    i=0;
    j=0;
    k=l;
    while (i < nl && j < nr) 
    { 
        if (left[i] <= right[j])
         { 
            a[k] = left[i]; 
            i++; 
        } 
        else 
        { 
            a[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < nl)
    { 
        a[k] = left[i]; 
        i++; 
        k++; 
    } 
    while (j < nr) { 
        a[k] = right[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int a[], int l, int r)
{
    if(l<r)
    {
        int mid = l+(r-l)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
void heapify(int a[], int n, int i) 
{ 
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2;
    if (l < n && a[l] > a[largest]) 
        largest = l;  
    if (r < n && a[r] > a[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        swap(a[i], a[largest]); 
        heapify(a, n, largest); 
    } 
} 
void heapSort(int a[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(a, n, i);  
    for (int i=n-1; i>0; i--) 
    { 
        swap(a[0], a[i]); 
        heapify(a, i, 0); 
    } 
} 
  
int main()
{
    int a[100];
    int n;
    int select;
    do
    {
        cout<<"WHICH SORT DO YOU WANT"<<endl;
        cout<<"1. BUBBLE SORT"<<endl;
        cout<<"2. INSERTION SORT"<<endl;
        cout<<"3. SELECTION SORT"<<endl;
        cout<<"4. QUICK SORT"<<endl;
        cout<<"5. SHELL SORT"<<endl;
        cout<<"6. MERGE SORT"<<endl;
        cout<<"7. HEAP SORT"<<endl;
        cout<<"8. EXIT"<<endl;
        cout<<"CHOOSE OPTION"<<endl;
        cin>>select;
        switch (select)
        {
            case 1:
            {
                cout<<"ENTER TOTAL NUMBER OF ELEMENTS"<<endl;
                cin>>n;
                cout<<"NOW ENTER THE NUMBERS"<<endl;
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                }
                BubbleSort(a,n);
                cout<<"THE SORTED LIST WITH BUBBLE SORT ===>"<<endl;
                break;
            }
            case 2:
            {
                cout<<"ENTER TOTAL NUMBER OF ELEMENTS"<<endl;
                cin>>n;
                cout<<"NOW ENTER THE NUMBERS"<<endl;
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                }
                InsertionSort(a,n);
                cout<<"THE SORTED LIST WITH INSERTION SORT ===>"<<endl;
                break;
            }
            case 3:
            {
                cout<<"ENTER TOTAL NUMBER OF ELEMENTS"<<endl;
                cin>>n;
                cout<<"NOW ENTER THE NUMBERS"<<endl;
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                }
                SelectionSort(a,n);
                cout<<"THE SORTED LIST WITH SELECTION SORT ===>"<<endl;
                break;
            }
            case 4:
            {
                cout<<"ENTER TOTAL NUMBER OF ELEMENTS"<<endl;
                cin>>n;
                cout<<"NOW ENTER THE NUMBERS"<<endl;
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                }
                int h=n+1;
                a[h]=INT32_MAX;
                QuickSort(a,0,h);
                cout<<"THE SORTED LIST WITH QUICK SORT ===>"<<endl;
                break;
            }
            case 5:
            {
                cout<<"ENTER TOTAL NUMBER OF ELEMENTS"<<endl;
                cin>>n;
                cout<<"NOW ENTER THE NUMBERS"<<endl;
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                }
                ShellSort(a,n);
                cout<<"THE SORTED LIST WITH SHELL SORT ===>"<<endl;
                break;
            }        
            case 6:
            {
                cout<<"ENTER TOTAL NUMBER OF ELEMENTS"<<endl;
                cin>>n;
                cout<<"NOW ENTER THE NUMBERS"<<endl;
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                }
                mergeSort(a,0,n-1);
                cout<<"THE SORTED LIST WITH MERGE SORT ===>"<<endl;
                break;    
            }   
            case 7:
            {
                cout<<"ENTER TOTAL NUMBER OF ELEMENTS"<<endl;
                cin>>n;
                cout<<"NOW ENTER THE NUMBERS"<<endl;
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                }
                heapSort(a,n);
                cout<<"THE SORTED LIST WITH HEAP SORT ===>"<<endl;
                break;
            }
            default:
            {
                cout<<"INVALID INPUT"<<endl;
                break;
            }
        }
        for(int i=0;i<n;i++)
         {
            cout<<a[i]<<endl;
         }
    }while(select != 8);
}
