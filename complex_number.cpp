#include<iostream>
using namespace std;

class complex
{
    private:
    float x,y;
    public:
    complex()
    {
        x=0;
        y=0;
    }
    complex operator+(complex);
    complex operator*(complex);
    friend istream & operator>>(istream &input,complex &t)
    {
        cout<<"\nEnter Real Part: ";
        input>>t.x;
        cout<<"\nEnter Imaginary Part :";
        input>>t.y;
    }
    friend ostream & operator<<(ostream &output,complex &t)
    {
        output<<t.x<<"+"<<t.y<<"i\n";
    }

};
complex complex::operator+(complex c)
{
    complex temp;
    temp.x=x+c.x;
    temp.y=y+c.y;
    return temp;
}
complex complex::operator*(complex c)
{
    complex temp2;
    temp2.x=(x*c.x)-(y*c.y);
    temp2.y=(y*c.x)+(x*c.y);
    return temp2;
}
int main()
{
    complex c1,c2;
    cout<<"Default constructor value:\n";
    cout<<c1;
    cout<<"Enter the 1st number :\n";
    cin>>c1;
    cout<<"Enter the 2nd number :\n";
    cin>>c2;
    complex c3,c4;
    c3=c1+c2;
    c4=c1*c2;
    cout<<"Addition of 2 number: \n";
    cout<<c3;
    cout<<"Multiplication of 2 numbers: \n";
    cout<<c4;
    return 0;
}