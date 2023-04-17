#include<iostream>
#include<utility>
#include<map>
#include<string>
using namespace std;

int main()
{
    typedef map<string,int>mapType;
    mapType populationMap;
    populationMap.insert(pair<string,int>("MH",199));
    populationMap.insert(pair<string,int>("UP",255));
    populationMap.insert(pair<string,int>("MP",170));
    populationMap.insert(pair<string,int>("RJ",102));
    populationMap.insert(pair<string,int>("GJ",70));
    mapType::iterator it=--populationMap.end();
    populationMap.erase(it);
    cout<<"\nSize of populationMap "<<populationMap.size()<<"\n";
    for(it=populationMap.begin();it!=populationMap.end();++it)
    {
        cout<<it->first<<":"<<it->second<<" Millions\n";
    }
    string state;
    cout<<"\nEnter the state:";
    cin>>state;
    it=populationMap.find(state);
    if(it!=populationMap.end())
    {
        cout<<state<<" Popuation is"<<it->second<<" Millions\n";
    }
    else
    {
        cout<<"Key is not in in population Map"<<"\n";
    }
    populationMap.clear();

}