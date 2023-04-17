#include<iostream>
#include<string.h>
#define max 50
using namespace std;
class personal_info
{
    private:
    char address[max],license[max],insurance[max];
    long int contact;
    public:
    personal_info()
    {
        strcpy(address,"XYZ");
        strcpy(license,"XY0");
        strcpy(insurance,"XY02");
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
    char name[max],dob[max],blood[max];
    float ht,wt;
    static int count;
    personal_info *pai;
    public:
    person()
    {
        strcpy(name,"XYZ");
        strcpy(dob,"XX//YY");
        strcpy(blood,"X+");
        ht=0.0;
        wt=0.0;
        pai=new personal_info;
    }
    person(person*p1)
    {
        strcpy(name,p1->name);
        strcpy(dob,p1->dob);
        strcpy(blood,p1->blood);
        ht=p1->ht;
        wt=p1->wt;
        pai=new personal_info;
        strcpy(pai->address,p1->pai->address);
        strcpy(pai->insurance,p1->pai->insurance);
        strcpy(pai->license,p1->pai->license);
        pai->contact=p1->pai->contact;
    }
    static void showcount()
    {
        cout<<"\nThe count is "<<count<<endl;
    }
    ~person()
    {
        cout<<"i am in destructor";
    }
    void getdata(char name[]);
    inline void display();
};
void person::getdata(char name[])
{
    strcpy(this->name,name);
    cout<<"\nEnter the DOB: ";
    cin>>dob;
    cout<<"Enter the blood group: ";
    cin>>blood;
    cout<<"Enter the height: ";
    cin>>ht;
    cout<<"Enter the weight: ";
    cin>>wt;
    cout<<"Enter the address: ";
    cin>>pai->address;
    cout<<"Enter the license no: ";
    cin>>pai->license;
    cout<<"Enter the insurance no: ";
    cin>>pai->insurance;
    cout<<"Enter the conatct no: ";
    cin>>pai->contact;
    count++;
}
int person::count=0;
void person::display()
{
    cout<<"\nName:\t"<<name;
    cout<<"\nDOB:\t"<<dob;
    cout<<"\nBlood:\t"<<blood;
    cout<<"\nHeight:\t"<<ht;
    cout<<"\nWeight:\t"<<wt;
    cout<<"\nAddress:\t"<<pai->address;
    cout<<"\nLicense:\t"<<pai->license;
    cout<<"\nInsurance:\t"<<pai->insurance;
    cout<<"\nContact:\t"<<pai->contact;
}
int main()
{
    person *p1,*p2;
    p1=new person;
    p2=new person(p1);
    int ch,n;
    cout<<"\nDefault constructor value: \n";
    p1->display();
    cout<<"\nCopy constructor value:\n";
    p2->display();
    cout<<"\nEnter how many records you want:";
    cin>>n;
    char name[max];
    person p3[n];
    do
    {
        cout<<"\n********MENU*******\n";
        cout<<"1.Add member\n2.Display member\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                for(int i=0;i<n;i++)
                {
                    cout<<"\nEnter the name: ";
                    cin>>name;
                    p3[i].getdata(name);
                    person::showcount();
                }
                break;
            }
            case 2:
            {
                for(int i=0;i<n;i++)
                {
                    p3[i].display();
                }
                break;
            }
            default:
            cout<<"Invalid choice";
        }
    } while (ch!=3);
    return 0;
    
}