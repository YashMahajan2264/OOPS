#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
    string data, name, dout;
    fstream f1;
    cout<<"Enter the file name you want to create : ";
    cin>>name;
    f1.open(name, ios::out);
    if(!f1)
    {
        cout<<"Error opening file.";
        exit(1);
    }
    cout<<"Enter the data and terminate with Enter and '/0' symbol"<<endl;
    while(getline(cin,data))
    {
        if(data == "/0")
        {
            break;
        }
        f1<<data;
    }    
    f1.close();
    f1.open(name, ios::in);
    cout<<endl<<"Now, Reading data."<<endl;
    while(!f1.eof())
    {
        getline(f1,data);
        cout<<data<<endl;
    }
    f1.close();

    return 0;
}
