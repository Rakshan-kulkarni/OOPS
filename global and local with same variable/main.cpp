#include <iostream>

using namespace std;

int x=10;
int main()
{
    int x=10;
    cout<<"value of global variable:"<<::x<<endl;
    cout<<"value of local variable:"<<x;
}
