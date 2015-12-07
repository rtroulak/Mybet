/**
* 
* @author  Troulakis Georgios Rafail <rtroulak@gmail.com> 
* @version 1.0
* @since   2014-02-01 
*/
#include "MatchInfo.h"
#include <map>
using namespace std;
Match m;
Bet b;
Odds o;
Results r;
Info *temp=new Info;
bool type;
bool result_time = false ;

Combination::Combination()
{
    number = 0;
}

Homewin::Homewin()
{
    ;
}

Draw::Draw()
{
    ;
}

Awaywin::Awaywin()
{
    ;
}

Info::Info()
{
    ;
}



Info::Info(Homewin homewin,Draw draw)
{
    
    this->draw = draw;
    this->awaywin = awaywin;
}

Odds::Odds()
{
    ;
}

Odds::Odds(Info full, Info half)
{
    this->fulltime = full;
    this->halftime = half;
}



Homewin Homewin::operator = (double d)
{
    
    this->number = d;
    if(o.fulltime.mode) m.fhome=d;
    if(o.halftime.mode) m.hhome=d;
    cout<<"\nHomewin=";
    cout<<this->number;
    
    
    return *this;
}

Awaywin  Awaywin::operator = (double d)
{
    this->number = d;
    if(o.fulltime.mode) m.faway=d;
    if(o.halftime.mode) m.haway=d;
    cout<<"\nAwaywin=";
    cout<<this->number;
    return *this;
}

Draw Draw::operator = (double d)
{
    this->number = d;
    if(o.fulltime.mode) m.fdraw=d;
    if(o.halftime.mode) m.hdraw=d;
    cout<<"\nDraw=";
    cout<<this->number;
    return *this;
}

Over::Over()
{
    number = 0;
}

Over Over::operator = (double d)
{
    m.over.number = d;
    m.overnumber=d;
    cout<<"\nOver=";
    cout<<m.over.number;
    return *this;
}
Under::Under()
{
    number = 0;
}

Under Under::operator = (double d)
{
    m.under.number = d;
    m.undernumber=d;
    cout<<"\nUnder=";
    cout<< m.under.number;
    return *this;
}

Match::Match()
{
    ;
}

Match::Match(int id)
{
    cout<<"\n\n\nMatchID=";
    
    this->id = id;
    cout<<this->id;
}

Bet::Bet()
{
    ;
}

Bet::Bet(string bname)
{
    cout<<"\nBet=";
    this->actbet=1;
    this->ammount=1;
    this->bname = bname;
    cout<<this->bname;
}

Info Info:: operator()(Homewin x)
{
    
    if(o.fulltime.mode)
    {
        
        o.fulltime.typeofodd=1;
        
        return o.fulltime;
    
    }
    if(o.halftime.mode)
    {
       
       o.halftime.typeofodd=1;
       return o.halftime;
    }
    return o.fulltime;
}

Info Info:: operator()(Awaywin x)
{
    
    if(o.fulltime.mode)
    {
        o.fulltime.typeofodd=2;
        
        return o.fulltime;
    }
    if(o.halftime.mode)
    {
        o.halftime.typeofodd=2;
       
       return o.halftime;
    }
    return o.fulltime;
}

Info Info:: operator()(Draw x)
{
    
    if(o.fulltime.mode)
    {
        o.fulltime.typeofodd=0;
        
        return o.fulltime;
    }
    if(o.halftime.mode)
    {
         o.halftime.typeofodd=0;
       
         return o.halftime;
    }
    return o.fulltime;
}

Bet Bet::operator[](enum myenum){
    cout<<"\nb[]\n";
    return *this;
}
Info  Info:: operator[](Info i){
    
    
    return *this;
}


Info Info :: operator () (int t1_score,int t2_score)
{
    if(o.fulltime.mode)
    {
        m.full_score1 = t1_score;
        m.full_score2 = t2_score;
        cout<<"FT "<<m.full_score1<<" - "<<m.full_score2<<endl;
        if(m.full_score1+m.full_score2>2){m.isOver=1;}
        else{m.isOver=0;}
    }
    if(o.halftime.mode)
    {
        m.half_score1 = t1_score;
        m.half_score2 = t2_score;
        cout<<"HT "<<m.half_score1<<" - "<<m.half_score2<<endl;
    }
    
    
    return * this;
}       

Results::Results()
{
    ;
}
Results Results:: operator[](Info i)
{
    
    
    return * this;
}