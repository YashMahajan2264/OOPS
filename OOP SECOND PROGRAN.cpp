
#include <iostream>
#include<string.h>

using namespace std;

class personal_info
{
    char address[20],license[20],insurance[20];
    long int contact;
    
    public:
    personal_info()
    {
        strcpy(address,"XYZ");
        strcpy(license,"XY.0");
        strcpy(insurance,"XY0X");
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
    char name[20],dob[10],blood[10];
    float ht,wt;
    static int count;
    personal_info *pai;
    
    public:
    person()
    {
        strcpy(name,"XYZ");
        strcpy(blood,"A+");
        strcpy(dob,"dd/mm//yy");
        ht=0;
        wt=0;
        pai=new personal_info;
    }
    person(person *p1)
    {
        strcpy(name,p1->name);
        strcpy(dob,p1->dob);
        strcpy(blood,p1->blood);
        ht=p1->ht;
        wt=p1->wt;
        pai=new personal_info;
        strcpy(pai->address,p1->pai->address);
        strcpy(pai->license,p1->pai->license);
        strcpy(pai->insurance,p1->pai->insurance);
        pai->contact=p1->pai->contact;
    }
    static void showcount()
    {
        cout<<"\nNO of counts ="<<count;
    }
    ~person()
    {
        cout<<"i am in destructor";
    }
    void getdata(char name[20]);
    inline void display();
};
void person::getdata(char name[20])
{
    strcpy(this->name,name);
    cout<<"\n Enter the date of birth";
    cin>>dob;
    cout<<"\nEnter blood group";
    cin>>blood;
    cout<<"\nEnter thr height";
    cin>>ht;
    cout<<"\nenter the weight";
    cin>>wt;
    cout<<"\nEnter address";
    cin>>pai->address;
    cout<<"\nEnter License number";
    cin>>pai->license;
    cout<<"\nEnter insurance number";
    cin>>pai->insurance;
    cout<<"\nEnter contact number";
    cin>>pai->contact;
    count++;
    
    
}
void person::display()
{
    cout<<"\t"<<name;
    cout<<"\t"<<dob;
    cout<<"\t"<<blood;
    cout<<"\t"<<ht;
    cout<<"\t"<<wt;
    cout<<"\t"<<pai->address;
    cout<<"\t"<<pai->license;
    cout<<"\t"<<pai->insurance;
    cout<<"\t"<<pai->contact;
}
int person::count=0;

int main()
{
    person *p1,*p2;
    int ch;
    p1=new person;
    p2=new person(p1);
    cout<<"\tName";
    cout<<"\tDob";
    cout<<"\tblood";
    cout<<"\tHt";
    cout<<"\tWt";
    cout<<"\tAddress";
    cout<<"\tLicense";
    cout<<"\tInsurance";
    cout<<"\tContact";
    cout<<endl;
    
    cout<<"\nDefault constructor value";
    p1->display();
    cout<<endl;
    cout<<"\n\t copy constructor value";
    p2->display();
    cout<<endl;
    int n;
    cout<<"Enter how many records you want";
    cin>>n;
    person p3[n];
    char name[20];
    int x=0;
    do
    {
        cout<<"\nWelcome to personal data base system";
        cout<<"\n1.Enter the record";
        cout<<"\n2.Dispaly the record";
        cout<<"\n3.Exit";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"\nEnter the name";
                cin>>name;
                p3[x].getdata(name);
                person::showcount();
                x++;
            break;
            }
            case 2:
            {
                cout<<"\tName";
                cout<<"\tDob";
                cout<<"\tblood";
                cout<<"\tHt";
                cout<<"\tWt";
                cout<<"\tAddress";
                cout<<"\tLicense";
                cout<<"\tInsurance";
                cout<<"\tContact";
                for(int i=0;i<n;i++)
                {
                    cout<<"\n";
                    p3[i].display();
                }
            break;
                
            }
        }
    }while(ch!=3);
    delete p1;
    delete p2;
    return 0;
    

    return 0;
}