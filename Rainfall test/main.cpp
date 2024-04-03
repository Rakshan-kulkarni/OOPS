#include <iostream>

using namespace std;

float rainfall[15];
float avg,mini,maxi,total;
int i;

void displayMonthly()
{
    for(i=1;i<=12;i++)
        cout<<rainfall[i]<<"  ";
    cout<<endl;
}

void displayTotal()
{
    for(i=1;i<=12;i++)
    {
        total+=rainfall[i];
    }
    cout<<"total rainfall = "<<total<<endl;
}

void displayAverage()
{
  avg=total/12;
    cout<<"Avearage rainfall = "<<avg<<endl;
}

void displayHigh()
{
    maxi=rainfall[1];
    for(i=1;i<=12;i++)
    {
        if(maxi < rainfall[i])
        maxi=rainfall[i];
    }
    cout<<"maximum rainfall = " <<maxi<<endl;
}

void displayLow()
{
    mini=rainfall[1];
    for(i=1;i<=12;i++)
    {
        if(mini > rainfall[i])
        mini=rainfall[i];
    }
    cout<<"minimum rainfall = " <<mini<<endl;
}

int main()
{
    int choice;

    for(i=1;i<=12;i++)
    {
        cout<<"Enter rainfall for month "<<i<<":"<<endl;
        cin>>rainfall[i];
    }
    while(1)
    {
        cout<<" 1. Display monthly amount\n 2. Display total amout\n 3. Display average amount\n 4. Display highest amount\n 5. Display lowest amount\n 6. End program\n";
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: displayMonthly(); break;
            case 2: displayTotal(); break;
            case 3: displayAverage(); break;
            case 4: displayHigh(); break;
            case 5: displayLow(); break;
            case 6: exit(0); break;
        }
    }
    return 0;
}
