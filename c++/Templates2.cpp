#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

class player
{
    public:
    string name;
    int jersey_no;
    void get()
    {
        cout<<"enter name";
        cin>>name;
        cout<<"enter Jersey number:";
        cin>>jersey_no;
    }

    void computeStats()=0;

};
class batsman:virtual public player
{
    public:
    int runs,balls,dismissed;
    batsman(){}
    batsman(int a,int b,int c)
    {
        get();
        runs=a;
        balls=b;
        dismissed=c;
    }
    void computeStats()
    {
        int Batting_Average=runs/dismissed;
        int StrikeRate=runs/balls;
    }

};
class bolwer:virtual public player
{
public:
int runs_conceded,wickets,bowled;

bolwer(int x,int y,int z)
{
    get();
    runs_conceded=x;
    wickets=y;
    bowled=z;
}
void computeStats()
{
    int Bowling_Average=runs_conceded/wickets;
    int Ecomomy_Rate=runs_conceded/bowled;
}
};
class AllRounder:public bolwer,public batsman
{
    public:

    void computeStats(){}
};


int main()
{





    return 0;
}