#include<iostream>
#include<string.h>
using namespace std;
class publication
{
    private:
    string title;
    float price;

    public:
    publication()
    {
        title="";
        price=0.0;
    }
    void set_data()
    {
        cout<<endl;
        cout<<"enter the title: ";
        cin>>title;
        cout<<"enter the price: ";
        cin>>price;
    }
    void put_data()
    {
        cout<<"*****INFORMATION******\n";
        cout<<"Title:\t"<<title<<endl;
        cout<<"Price:\t"<<price<<endl;
    }
};
class book:public publication
{
    private:
    int pages;
    public:
    book()
    {
        pages=0;
    }
    void set_data()
    {
        cout<<"\nEnter the book info:\n";
        publication::set_data();
        cout<<"Enter the no of pages: ";
        cin>>pages;
    }
    void put_data()
    {
        publication::put_data();
        try
        {
            if(pages<0)
            throw pages;}
        catch(int f)
        {
            cout<<"\nError invalid page count: "<<pages;
        }
        cout<<"No of pages:\t"<<pages<<endl;
    }
};
class tape:public publication
{
    private:
    float playtime;
    public:
    tape()
    {
        playtime=0.0;
    }
    void set_data()
    {
        cout<<"\nEnter the tape info:\n";
        publication::set_data();
        cout<<"enter the playtime: ";
        cin>>playtime;
    }
    void put_data()
    {
        publication::put_data();
        try
        {
            if(playtime<0.0)
            throw playtime;
        }
        catch(float f)
        {
            cout<<"\nError invalid playtime: "<<playtime<<endl;
        }
        cout<<"Playtime:\t"<<playtime<<endl;
    }
};
int main()
{
    book k;
    tape e;
    k.set_data();
    e.set_data();
    k.put_data();
    e.put_data();
    return 0;
}

