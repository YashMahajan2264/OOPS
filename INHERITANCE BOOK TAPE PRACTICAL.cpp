#include<iostream>
#include<string>
using namespace std;
//program by yash mahajan

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
        cout<<"Enter the data:"<<endl;
        cout<<"Title:";
        cin>>title;
        cout<<"Price:";
        cin>>price;
    }
    void put_data()
    {
        cout<<"Information:"<<endl;
        cout<<"\nTitle:"<<title<<endl;
        cout<<"Price"<<price<<endl;
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
        publication::set_data();
        cout<<"Enter the page count:";
        cin>>pages;
    }
    void put_data()
    {
        publication::put_data();
        try
        {if(pages<0)
        throw pages;}
        catch(int f)
        {
            cout<<"error:invalid pages:"<<pages;
            pages=0;
        }
        cout<<"Pages are:"<<pages<<endl;
        
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
        publication::set_data();
        cout<<"Enter playtime:";
        cin>>playtime;
    }
    void put_data()
    {
        publication::put_data();
        
        try
        {if(playtime<0.0)
         throw playtime;}
         catch(float r)
        {
         cout<<"error:invalid playtime:"<<playtime;
         playtime=0.0;
        }
        cout<<"playtime is:"<<playtime<<endl;
        
    }
};
int main()
{
    book book1;
    tape tape1;
    book1.set_data();
    tape1.set_data();
    book1.put_data();
    tape1.put_data();
    
    return 0;
}
