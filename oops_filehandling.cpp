#include<iostream>
#include<fstream>
using namespace std;

class Employee
{
    private:
    char name[20];
    int PRN;
    double salary;

    public:
    void setdata()
    {
        cout<<"enter the name:";
        cin>>name;
        cout<<"Enter PRN:";
        cin>>PRN;
        cout<<"Enter salary:";
        cin>>salary;
    }
    void display()
    {
        cout<<"Name="<<"\t"<<name<<endl;
        cout<<"PRN="<<"\t"<<PRN<<endl;
        cout<<"salary="<<"\t"<<salary<<endl;
    }

};
int main()
{
    Employee y[5];
    int i,n;
    fstream file;
    file.open("Employee.txt",ios::out);
    cout<<"Enter the no of employee"<<endl;
    cin>>n;
    cout<<"The Information of employees are "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Information of employee "<<i+1<<endl;
        y[i].setdata();
        file.write((char*)&y[i],sizeof y[i]);
    }
    file.close();
    cout<<"The information of employees are "<<endl;
    file.open("Employee.txt",ios::in);
    for(i=0;i<n;i++)
    {
        file.write((char*)&y[i],sizeof y[i]);
        y[i].display();
    }
    file.close();
    return 0;
}