#include<iostream>
#include<algorithm>
#include<vector>
#define max 50
using namespace std;
class student
{
    public:
    int rollno;
    long int telephone;
    char name[max];
    char DOB[max];

    bool operator==(const student &li)
    {
        if(rollno==li.rollno)
        {
            return 1;
        }
        return 0;
    }
    bool operator<(const student &li)
    {
        if(rollno<li.rollno)
        {
            return 1;
        }
        return 0;
    }
};
vector<student>ol;
void print(student &li);
void display();
void insert();
void search();
bool compare(const student &l1,const student &l2)
{
    return l1.rollno<l2.rollno;
}
int main()
{
    int ch;
    do
    {
        cout<<"\n*****MENU*****\n";
        cout<<"1.Add studet\n2.Display\n3.Search\n4.Sort\n5.Exit\nEnter your choice";
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
                cout<<"\nSorted Data :\n";
                display();
                break;
            }
            case 5:
            {
                exit(0);
            }
            default:
            {
                cout<<"INVALID CHOICE";
            }
        }
    } while (ch!=6);
    return 0;
    
}
void insert()
{
    student li;
    cout<<"\nEnter name of student: ";
    cin>>li.name;
    cout<<"Enter the DOB: ";
    cin>>li.DOB;
    cout<<"Enter the roll no: ";
    cin>>li.rollno;
    cout<<"Enter the telephone no: ";
    cin>>li.telephone;
    ol.push_back(li);
}
void display()
{
    for_each(ol.begin(),ol.end(),print);
}
void print(student &il)
{
    cout<<"\nName:\t"<<il.name;
    cout<<"\nDOB:\t"<<il.DOB;
    cout<<"\nRollNO:\t"<<il.rollno;
    cout<<"\nContactNO:\t"<<il.telephone;
}
void search()
{
    student li;
    cout<<"\nEnter the rolll no of student to search: ";
    cin>>li.rollno;
    vector<student>::iterator ip;
    ip=find(ol.begin(),ol.end(),li);
    if(ip==ol.end())
    {
        cout<<"NOT FOUND";
    }
    else
    {
        cout<<"FOUND";
    }
}