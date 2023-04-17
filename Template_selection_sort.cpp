#include<iostream>
#include<limits.h>
using namespace std;

template<class T>
T selection_sort()
{
    T a[10];
    T temp;
    cout<<"enter the data for sorting"<<endl;
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
    cout<<"The  data element after sorting:"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    cout<<"\nInteger Sorting:\n";
    selection_sort<int>();
    cout<<"\nfloat Sorting:";
    selection_sort<float>();
    return 0;
}