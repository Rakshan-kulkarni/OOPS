#include <iostream>

using namespace std;

int addnumber (int a ,int b)
{
    return a+b;
}

class myclass
{
    public:
    int addnumber(int a,int b){
    return a+b;}};

int main()
{
    int result = addnumber(3,5);
    cout<<result<<endl;
    myclass obj;
    int res = obj.addnumber(5,8);
    cout<<res<<endl;
    return 0;
}
