#include <iostream>

using namespace std;

int main()
{
    char choice;
    int a,b,c;

    cout<<"Enter your choice of calculator"<<endl;
    while(1)
    {
     cin>>choice;
     cout<<"Enter value of a,b"<<endl;
     cin>>a >>b;
        switch(choice)
        {
            case'+': c=a+b;
            cout<<"Answer: "<<c;
            break;
            case'-': c=a-b;
            cout<<"Answer: "<<c;
            break;
            case'*': c=a*b;
            cout<<"Answer: "<<c;
            break;
            case'/': c=a/b;
            cout<<"Answer: "<<c;
            break;
            default: exit(0);
            break;

        }
    }
    return 0;
}
