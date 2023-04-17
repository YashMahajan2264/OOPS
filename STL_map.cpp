#include<iostream>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;
int main()
{
    typedef map<string,int>maptype;
    maptype populationMap;
    populationMap.insert(pair<string,int>("MH",170));
    populationMap.insert(pair<string,int>("GJ",70));
    populationMap.insert(pair<string,int>("MP",190));
    populationMap.insert(pair<string,int>("UP",270));
    populationMap.insert(pair<string,int>("AP",110));
    populationMap.insert(pair<string,int>("TN",101));
    populationMap.insert(pair<string,int>("GA",17));
    populationMap.insert(pair<string,int>("RJ",165));
    maptype::iterator p=--populationMap.end();
    populationMap.erase(p);
    for(p=populationMap.begin();p!=populationMap.end();p++)
    {
        cout<<p->first<<":\t"<<p->second<<" MILLIONS"<<endl;
    }
    cout<<"\nSize of map population is "<<populationMap.size()<<endl;
    string state;
    cout<<"\nEnter the name of state to be search: ";
    cin>>state;
    p=populationMap.find(state);
    if(p==populationMap.end())
    {
        cout<<"\nNOT FOUND\n";
    }
    else
    {
        cout<<state<<" Population is "<<p->second<<"Millions"<<endl;
    }
    populationMap.clear();


}