#include<iostream>
#include<limits.h>
using namespace std;
template<class Yash>
Yash selction_sort()
{
    Yash a[10];
    Yash temp;
    cout<<"\nEnter the element for sorting: \n";
    for(int i=0;i<10;i++)
    {
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }
    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"\nData element after the sorting:\n";
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    cout<<"Integer sorting\n";
    selction_sort<int>();
    cout<<"floating point sorting\n";
    selction_sort<float>();
    return 0;
}
