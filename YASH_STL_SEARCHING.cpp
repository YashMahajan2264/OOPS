#include<iostream>
#include<vector>
#include<algorithm>
#define Max 50
using namespace std;
class student
{
    public:
    int rollno;
    long int telephone;
    char name[Max];
    char DOB[Max];
    bool operator==(const student &il)
    {
        if(rollno==il.rollno)
        {
            return 1;
        }
        return 0;
    }
    bool operator<(const student &il)
    {
        if(rollno<il.rollno)
        {
            return 1;
        }
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
        cout<<"\n1.Insert\n2.Display\n3.Sort\n4.Search\n5.Exit\nEnter your choice: ";
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
                sort(ol.begin(),ol.end(),compare);
                cout<<"\nData after Sorting: \n";
                display();
                break;
            }
            case 4:
            {
                search();
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
    cout<<"\nEnter the name: ";
    cin>>il.name;
    cout<<"\nEnter the DOB: ";
    cin>>il.DOB;
    cout<<"\nEnter the telephone no: ";
    cin>>il.telephone;
    cout<<"\nEnter the roll No: ";
    cin>>il.rollno;
    ol.push_back(il);
}
void print(student &il)
{
    cout<<"Name:\t"<<il.name<<endl;
    cout<<"DOB:\t"<<il.DOB<<endl;
    cout<<"Telephone:\t"<<il.telephone<<endl;
    cout<<"Roll No:\t"<<il.rollno<<endl;
}
void display()
{
    for_each(ol.begin(),ol.end(),print);
}
void search()
{
    vector<student>::iterator p;
    student il;
    cout<<"Enter the roll no of student to search: ";
    cin>>il.rollno;
    p=find(ol.begin(),ol.end(),il);
    if(p==ol.end())
    {
        cout<<"\nNOT FOUND";
    }
    else
    {
        cout<<"\nFOUND";
    }
}
