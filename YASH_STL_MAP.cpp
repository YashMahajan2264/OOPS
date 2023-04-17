#include<iostream>
#include<map>
#include<utility>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    typedef map<string,int>maptype;
    maptype population;
    population.insert(pair<string,int>("MH",123));
    population.insert(pair<string,int>("GJ",90));
    population.insert(pair<string,int>("RJ",102));
    population.insert(pair<string,int>("AP",99));
    population.insert(pair<string,int>("MP",150));
    maptype::iterator ip=--population.end();
    population.erase(ip);
    cout<<"\nSize of map="<<population.size();
    cout<<"\nSTATES\tPOPULATION\n";
    for(ip=population.begin();ip!=population.end();ip++)
    {
        cout<<ip->first<<"\t"<<ip->second<<"MILLIONS\n";
    }
    cout<<"Enter the state to find";
    string state;
    cin>>state;
    ip=population.find(state);
    if(ip==population.end())
    {
        cout<<"\nNOT FOUND";
    }
    else
    {
        cout<<state<<" Popuation is"<<ip->second<<" Millions\n";;
    }
    population.clear();
}