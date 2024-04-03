#include <iostream>

using namespace std;

int main()
{
    int marks,i;
    float perc=0,sum=0;
    cout<<"Enter marks"<<endl;
    for(i=0;i<5;i++)
    {
        cin>>marks;
        sum=sum+marks;
    }
    cout<<"Total marks : "<<sum<<endl;
    perc = (sum/500)*100;
    cout<<"percentage : "<<perc<<endl;
    return 0;
}
