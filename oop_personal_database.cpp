#include<iostream>
#include<string.h>
using namespace std;
class personal_info
{
    private:
    char insuarnce[50],license[50],address[50];
    long int contact;
    public:
    personal_info()
    {
        strcpy(insuarnce,"XY00");
        strcpy(address,"XYZ");
        strcpy(license,"XXX");
        contact=0000;
    }
    ~personal_info()
    {
        cout<<"I am in destructor";
    }
    friend class person;
};
class person
{
    private:
    char DOB[20],name[20],blood[10];
    float ht,wt;
    static int count;
    personal_info *pai;

    public:
    person()
    {
        strcpy(DOB,"xx/mm/yy");
        strcpy(name,"XYZ");
        strcpy(blood,"B-");
        ht=0.0;
        wt=0.0;
        pai=new personal_info;
    }
    person(person *p1)
    {
        strcpy(name,p1->name);
        strcpy(DOB,p1->DOB);
        strcpy(blood,p1->blood);
        ht=p1->ht;
        wt=p1->wt;
        pai=new personal_info;
        strcpy(pai->insuarnce,p1->pai->insuarnce);
        strcpy(pai->license,p1->pai->license);
        strcpy(pai->address,p1->pai->address);
        pai->contact=p1->pai->contact;
    }
    static void showcount()
    {
        cout<<"\nThe count is "<<count;
    }
    inline void display();
    void getdata(char name[20]);
    ~person()
    {
        cout<<"I am in destructor.";
    }
};
int person::count=0;
void person::getdata(char name[20])
{
    strcpy(this->name,name);
    cout<<"\nEnter the DOB: ";
    cin>>DOB;
    cout<<"\nEnter the blood group: ";
    cin>>blood;
    cout<<"\nEnter the height: ";
    cin>>ht;
    cout<<"\nEnter the weight: ";
    cin>>wt;
    cout<<"\nEnter the address: ";
    cin>>pai->address;
    cout<<"\nEnter the insurance no: ";
    cin>>pai->insuarnce;
    cout<<"\nEnter the license no: ";
    cin>>pai->license;
    cout<<"\nEnter the contact no: ";
    cin>>pai->contact;
    count++;
}
void person::display()
{
    cout<<name;
    cout<<"\t"<<DOB;
    cout<<"\t"<<blood;
    cout<<"\t"<<ht;
    cout<<"\t"<<wt;
    cout<<"\t"<<pai->address;
    cout<<"\t"<<pai->insuarnce;
    cout<<"\t"<<pai->license;
    cout<<"\t"<<pai->contact;
    cout<<"\n";
}
int main()
{
    person *p1,*p2;
    int n,ch;
    int x=0;
    p1=new person;
    p2=new person(p1);
    cout<<"Name\tDOB\tBlood Gr\tHeight\tWeight\tAddress\tInsurance no\tLicense no\tContact no\n";
    cout<<"Default constructor value:\n";
    p1->display();
    cout<<"Copy constructor value:\n";
    p2->display();
    cout<<"Enter how many record you want:";
    cin>>n;
    person  p3[n];
    char name[20];
    do
    {
        cout<<"*****MENU******\n";
        cout<<"1.Add member\n2.Display member\n3.Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter the name";
                cin>>name[20];
                p3[x].getdata(name);
                person::showcount;
                x++;
                break;
            }
            case 2:
            {
                cout<<"Name\tDOB\tBlood Gr\tHeight\tWeight\tAddress\tInsurance no\tLicense no\tContact no\n";
                for(int i=0;i<n;i++)
                {
                    p3[i].display();
                }
                break;
            }
            case 3:
            {
                exit(0);
            }
            default:
            {
                cout<<"INVALID CHOICE";
            }
        }
    }while (ch!=4);
    delete p1;
    delete p2;
    return 0;
    
}