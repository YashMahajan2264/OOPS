#include<iostream>
#include<string.h>
using namespace std;
class personal
{
    public:
    char license[50],insurance[50],address[50];
    long int contact;

    public:
    personal()
    {
        strcpy(license,"XY2");
        strcpy(address,"XYZ");
        strcpy(insurance,"XY1Z");
        contact=000;
    }
    ~personal()
    {
        cout<<"I am in destructor";
    }
    friend class perosn;
};
class person
{
    private:
    char name[50],dob[20],blood[10];
    float  ht,wt;
    static int count;
    personal *pai;

    public:
    person()
    {
        strcpy(name,"XYZ");
        strcpy(dob,"XX/YY//");
        strcpy(blood,"B+");
        ht=0.0;
        wt=0.0;
        pai=new personal;
    }
    person(person *p1)
    {
        strcpy(name,p1->name);
        strcpy(dob,p1->dob);
        strcpy(blood,p1->blood);
        ht=p1->ht;
        wt=p1->wt;
        pai=new personal;
        strcpy(pai->license,p1->pai->license);
        strcpy(pai->address,p1->pai->address);
        strcpy(pai->insurance,p1->pai->insurance);
        pai->contact=p1->pai->contact;

    }
    static void showcount()
    {
        cout<<"\nThe count is "<<count<<endl;
    }
    ~person()
    {
        cout<<"I am in destructor";
    }
    void getdat(char  name[]);
    inline void display();


};
int person::count=0;
void person::getdat(char name [])
{
    strcpy(this->name,name);
    cout<<"Enter the dob :";
    cin>>dob;
    cout<<"Enter the blood group :";
    cin>>blood;
    cout<<"Enter the height :";
    cin>>ht;
    cout<<"Enter the weight :";
    cin>>wt;
    cout<<"Enter the address :";
    cin>>pai->address;
    cout<<"Enter the insurance no :";
    cin>>pai->insurance;
    cout<<"Enter the license   no :";
    cin>>pai->license;
    cout<<"Enter the contact no :";
    cin>>pai->contact;
    count++;
}
void person::display()
{
    cout<<"\nNAME\t"<<name;
    cout<<"\nDOB\t"<<dob;
    cout<<"\nBLOOD\t"<<blood;
    cout<<"\nHEIGHT\t"<<ht;
    cout<<"\nWEIGHT\t"<<wt;
    cout<<"\nADDRESS\t"<<pai->address;
    cout<<"\nLICENSE\t"<<pai->license;
    cout<<"\nINSURANCE\t"<<pai->insurance;
    cout<<"\nCONTACT\t"<<pai->contact;
}
int main()
{
    person *p1,*p2;
    p1=new person;
    p2=new person(p1);
    cout<<"\nDefault constructor value:\n ";
    p1->display();
    cout<<"\nCopy constructor value:\n";
    p2->display();
    char name[50];
    int ch;
    int n;
    int x=0;
    cout<<"\nEnter how many record you want";
    cin>>n;
    person p3[n];
    do
    {
        cout<<"\n**************\n";
        cout<<"******MENU******\n";
        cout<<"1.Enter the record\n2.Display the record\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter the name :";
                cin>>name;
                p3[x].getdat(name);
                person::showcount();
                x++;
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
        }
    } while (ch!=3);
    delete p1;
    delete p2;
    return 0;
}