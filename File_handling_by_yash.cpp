#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
    string name , data , dout;
    fstream file;
    cout<<"\nEnter the name of file: ";
    cin>>name;
    file.open(name,ios::out);
    if(!file)
    {
        cout<<"Error in openinig file";
        exit(1);
    }
    cout<<"\nEnter the data which terminate after enter and /0 \n";
    while(getline(cin,data))
    {
        if(data=="/0")
        {
            break;
        }
        file<<data;
    }
    file.close();
    file.open(name,ios::in);
    cout<<"\nNow reading the file content:\n";
    while(!file.eof())
    {
        getline(file,data);
        cout<<data<<endl;
    }
    file.close();
}