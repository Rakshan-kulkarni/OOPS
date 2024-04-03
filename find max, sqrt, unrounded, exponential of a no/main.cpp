#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    float a,b,sqr;
    cout << "Enter a number" << endl;
    cin>>a;
    cout<<"Enter another number"<<endl;
    cin>>b;
    if(a>b)
    {
        cout<<"a is max"<<endl;
    }
    else
    {
        cout<<"b is max"<<endl;
    }
    sqr=sqrt(a);
    cout<<"Sqr of a is "<<sqr<<endl;
    return 0;
}
