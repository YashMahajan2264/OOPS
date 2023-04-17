#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
    string name,data;
    cout<<"Enter the name of file: ";
    cin>>name;
    fstream f2;
    f2.open(name,ios::out);
    if(!f2)
    {
        cout<<"\nError in oprning file\n";
        exit(1);
    }
    cout<<"\nenter the data which terminate after enter and /0:\n";
    while(getline(cin,data))
    {
        if(data=="/0")
        {
            break;
        }
        f2<<data;
    }
    f2.close();
    cout<<"\nNow reading the file content:\n";
    f2.open(name,ios::in);
    while(!f2.eof())
    {
        getline(f2,data);
        cout<<data<<endl;
    }
    f2.close();
}