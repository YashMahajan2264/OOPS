#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define max 50
using namespace std;
class student
{
    public:
    int rollNO;
    long int telephone;
    string name;
    string dob;

    bool operator==(const student &li)
    {
        if(rollNO==li.rollNO)
        {
            return 1;
        }
        return 0;
    }
    bool operator<(const student &li)
    {
        if(rollNO<li.rollNO)
        {
            return 1;
        }
        return 0;
    }
};
vector<student>ol;
void search();
void display();
void print(student &li);
void insert();
bool compare(const student &l1,const student &l2)
{
    return l1.rollNO<l2.rollNO;
}
int main()
{
    int ch;
    do
    {
        cout<<"\n********************\n";
        cout<<"**********MENU********\n";
        cout<<"1.Insert\n2.Display\n3.Search\n4.Sort\n5.Exit\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3:
            {
                search();
                break;
            }
            case 4:
            {
                sort(ol.begin(),ol.end(),compare);
                cout<<"Data after sorting\n";
                display();
                break;
            }
            case 5:
            {
                exit(0);
            }
        }
    } while (ch!=6);
    return 0;
    
}
void insert()
{
    student li;
    cout<<"\nEnter the name of student: ";
    cin>>li.name;
    cout<<"Enter the rollno of student: ";
    cin>>li.rollNO;
    cout<<"Enter the DOB of student: ";
    cin>>li.dob;
    cout<<"Enter the telephone no of student: ";
    cin>>li.telephone;
    ol.push_back(li);
}
void display()
{
    for_each(ol.begin(),ol.end(),print);
}
void print(student &li)
{
    cout<<endl;
    cout<<"Student name:\t"<<li.name;
    cout<<"\nStudent rollno:\t"<<li.rollNO;
    cout<<"\nStudent DOB:\t"<<li.dob;
    cout<<"\nStudent conatct:\t"<<li.telephone;
}
void search()
{
    student li;
    vector<student>::iterator p;
    cout<<"\nEnter the rollno of student to be serach:";
    cin>>li.rollNO;
    p=find(ol.begin(),ol.end(),li);
    if(p==ol.end())
    {
        cout<<"NOT FOUND";
    }
    else
    {
        cout<<"Student is found\n";
    }
}