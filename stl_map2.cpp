#include<iostream>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;
int main()
{
    typedef map<string,int>maptype;
    maptype population;
    population.insert(pair<string,int>("MH",170));
    population.insert(pair<string,int>("GJ",70));
    population.insert(pair<string,int>("MP",190));
    population.insert(pair<string,int>("UP",210));
    population.insert(pair<string,int>("AP",140));
    population.insert(pair<string,int>("HP",50));
    population.insert(pair<string,int>("GA",10));
    population.insert(pair<string,int>("RJ",180));
    maptype::iterator p=--population.end();
    population.erase(p);
    cout<<"\nThe size of map is "<<population.size();
    for(p=population.begin();p!=population.end();p++)
    {
        cout<<p->first<<"\t"<<p->second<<" Millions\n";
    }
    string state;
    cout<<"\nEnter the name of state to search: ";
    cin>>state;
    p=population.find(state);
    if(p!=population.end())
    {
        cout<<state<<" population is "<<p->second<<" Millions";
    }
    population.clear();
}