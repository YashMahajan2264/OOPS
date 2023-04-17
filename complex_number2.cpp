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
        cout<<"\nEnter the real part: ";
        input>>t.x;
        cout<<"Enter the imaginary part: ";
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
    cout<<"Default constructor value :";
    cout<<c1;
    cout<<"\nEnter the first number: ";
    cin>>c1;
    cout<<"\nEnter the second number: ";
    cin>>c2;
    complex c3,c4;
    cout<<"\nAddition two number:";
    c3=c1+c2;
    cout<<c3;
    cout<<"\nMultiplication of two number: ";
    c4=c1*c2;
    cout<<c4;
    return 0;
}