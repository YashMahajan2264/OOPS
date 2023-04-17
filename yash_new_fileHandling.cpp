#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
    string name,data,dout;
    cout<<"Enter the name of file: ";
    cin>>name;
    fstream file;
    file.open(name,ios::out);
    if(!file)
    {
        cout<<"\nError in opening\n";
        exit(1);
    }
    cout<<"\nEnter the data which terminate at enter and /0:";
    while(getline(cin,data))
    {
        if(data=="/0")
        {
            break;
        }
        file>>data;
    }
    file.close();
    file.open(name,ios::in);
    cout<<"\nNow reading file data:\n";
    while(!file.eof())
    {
        getline(file,data);
        cout<<data<<endl;
    }
    file.close();
    
    return 0;
}