#include<iostream>
#include<algorithm>
#include<vector>
#define Max 50
using namespace std;

class student
{
    public:
    int rollno;
    char name[Max];
    char DOB[Max];
    long int telephone;

    bool operator==(const student &il)
    {
        if(rollno==il.rollno)
             return 1;
        return 0;
    }
    bool operator<(const student &il)
    {
        if(rollno<il.rollno)
            return 1;
        return 0;
    }
};
vector<student>ol;
void print(student &il);
void display();
void insert();
void search();
bool compare(const student &il1,const student &il2)
{
    return il1.rollno<il2.rollno;
}
int main()
{
    int ch;
    do
    {
        cout<<"\n******MENU******";
        cout<<"\n1.Insert\n2.Display\n3.Search\n4.Sort\n5.Exit\nEnter your choice";
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
                cout<<"\nsorted on roll No";
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
    student il;
    cout<<"\nEnter the student name: ";
    cin>>il.name;
    cout<<"\nEnter the DOB: ";
    cin>>il.DOB;
    cout<<"\nEnter the telephone no: ";
    cin>>il.telephone;
    cout<<"\nEnter the roolno: ";
    cin>>il.rollno;
    ol.push_back(il);
}
void display()
{
    for_each(ol.begin(),ol.end(),print);
}
void print(student &il)
{
    cout<<"\n";
    cout<<"\nStudent Name:"<<il.name;
    cout<<"\nStudent DOB:"<<il.DOB;
    cout<<"\nStudent Telephone:"<<il.telephone;
    cout<<"\nStudent rollno:"<<il.rollno;
}
void search()
{
    vector<student>::iterator p;
    student il;
    cout<<"\nenter the roll no of student to search:";
    cin>>il.rollno;
    p=find(ol.begin(),ol.end(),il);
    if(p==ol.end())
    {
        cout<<"NOT FOUND";
    }
    else 
    {
        cout<<"FOUND";
    }

}