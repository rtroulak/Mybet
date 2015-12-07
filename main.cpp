/**
* 
* @author  Troulakis Georgios Rafail <rtroulak@gmail.com> 
* @version 1.0
* @since   2014-02-01 
*/
#include "MatchInfo.h"
#include "macros.h"
#include <map>

using namespace std;

extern Bet b;
extern Match m;
extern Info *temp;
extern Odds o;
extern Results r;
extern bool result_time ;
map<int,Match> Matches;
map<int,Match>::iterator i;
map<string,Bet> Bets;
map<string,Bet>::iterator b_i;

void insert(Match m)
{
    Matches.insert(pair<int,Match>(m.id,m));
}

void insert_bet(Bet bet)
{
    Bets.insert(pair<string,Bet>(bet.bname,bet));
    for(b_i = Bets.begin(); b_i != Bets.end();b_i++)
    {
        cout <<endl<<b_i->first<<endl;
        cout << b_i->second.bname<<endl<<b_i->second.ammount<<endl;
    }
}

Info make_new_full()
{
    o.halftime.mode=0;
    o.fulltime.mode=1;
    
    if(b.actbet){}
    return o.fulltime;
}


Info  make_new_half()
{
    o.fulltime.mode=0;
    o.halftime.mode=1;
     
     if(b.actbet){}
    return o.halftime;
}


Match make_new_match(int id)
{
    m.tmpid=id;
    insert(m);
    if(result_time)
    {
        for(i = Matches.begin(); i!=Matches.end();i++)
        {
            if(i->second.id == id)
            {
                cout << i->first<<endl ;
                cout << i->second.team1<<"-"<<i->second.team2;
                cout<< " Match with id -> " << id << " founded " <<endl;
                return i->second;
            }
        }
        
    }else if(r.activr){
        
        return m;
    
    }
    else if(b.actbet){ 
        ;
        for(i = Matches.begin(); i!=Matches.end();i++)
    {
            if(i->second.id==id){
                         
                         b.current_match=i->first;
            }
    }
        return m;
    }
    Match temp_match(id);
    
    return temp_match;
}

Bet make_new_bet(string bname)
{
    
    Bet temp_bet(bname);
    return temp_bet;
}

Odds make_new_odd()
{
    Odds temp;
    m.odds=temp;
    
    
    
    return temp;
}

void operator - (string team1,string team2)
{
    m.team1 = team1;
    m.team2 = team2;
    cout<<"\n"+m.team1+"-"+m.team2;
}


Info operator ,(Homewin home,Draw draw)
{
    
    Info i(home,draw);
    return i;
}

Info operator ,(Info i,Awaywin away)
{
    
    i.awaywin = away;
    return i;
}




myenum operator,(Match x,Over over){
     for(i = Matches.begin(); i!=Matches.end();i++)
    {
         if(m.tmpid==i->second.id){
                        cout<<"\nA1rxiko=";
                         
                         cout<<b.ammount;
                        
                         cout<<"\nOver=";
                         cout<<i->second.over.number;
                         
                         b.ammount=b.ammount*i->second.over.number;
                         cout<<"\nAmmount=";
                         cout<<b.ammount;
                         cout<<"\nsto";
                         cout << i->first<<endl ;
                         
         }           
          
    }
     return yes;
}


myenum operator,(Match m,Under under){
     for(i = Matches.begin(); i!=Matches.end();i++)
    {
         if(m.tmpid==i->second.id){
                         cout<<"\nA2rxiko=";
                         
                         cout<<b.ammount;
                         
                         cout<<"\nDokimi=";
                         
                         cout<<i->second.faway;
                         
                         cout<<"\nUnder=";
                         
                         cout<<i->second.under.number;
                         b.ammount=b.ammount*i->second.under.number;
                         cout<<"\nAmmount=";
                         cout<<b.ammount;
                         cout<<"\nsto";
                         cout << i->first<<endl ;
                         
         }           
          
    }
     return yes;
}

myenum operator,(Match m,Info info){
    
    if(result_time){
        return yes;
    }
    
    if(o.fulltime.mode)
    {
     for(i = Matches.begin(); i!=Matches.end();i++)
    {
         if(m.id==i->second.id){
              cout<<"\nA3rxiko=";
                         
                         cout<<b.ammount;
                         
                         if(o.fulltime.typeofodd==1){
                         cout<<"\nHomewinFull=";
                         cout<<m.fhome;
                         b.ammount=b.ammount*m.fhome;
                         }
                         if(o.fulltime.typeofodd==2){
                         cout<<"\nAwaywinFull=";
                         cout<<m.faway;
                         b.ammount=b.ammount*m.faway;
                         }
                         if(o.fulltime.typeofodd==2){
                         cout<<"\nDrawFull=";
                         cout<<m.fdraw;
                         b.ammount=b.ammount*m.fdraw;
                         }
                         cout<<"\nAmmount=";
                         cout<<b.ammount;
                         cout<<"\nsto";
                         cout << i->first<<endl ;
         }
     
     
     }
    }
if(o.halftime.mode)
    {

     for(i = Matches.begin(); i!=Matches.end();i++)
    {
         if(m.id==i->second.id){
              cout<<"\nA4rxiko=";
                         
                         cout<<b.ammount;
                         
                         if(o.halftime.typeofodd==1){
                         cout<<"\nHomewinHalf=";
                         cout<<m.hhome;
                         b.ammount=b.ammount*m.hhome;
                         }
                         if(o.halftime.typeofodd==2){
                         cout<<"\nAwaywinHalf=";
                         cout<<m.haway;
                         b.ammount=b.ammount*m.haway;
                         }
                         if(o.halftime.typeofodd==2){
                         cout<<"\nDrawHalf=";
                         cout<<m.fdraw;
                         b.ammount=b.ammount*m.hdraw;
                         }
                         cout<<"\nAmmount=";
                         cout<<b.ammount;
                         cout<<"\nsto ";
                         cout << i->first<<endl ;
         }
     
     
     }


}return yes;
}


void kerdos(int am){
    insert_bet(b);
    cout<<"\nApotimisi Sto Bet= ";
    cout<<b.bname;
    cout<<"\nExoume apodosi sunoliki \nOdd= ";
    cout<<b.ammount;
    cout<<" euro";
    
    
    
    cout<<"\nPontareis Bet= ";
    cout<<am;
    cout<<" euro";
    
    cout<<"\nMegisto kerdos= ";
    cout<<am*b.ammount;
    cout<<" euro";
}

Results make_new_results(void)
{
    result_time = true;
    Results temp_res;
    cout<<" \nNEW RESULT OBJECT MADE "<<endl;
    return temp_res;
}

void match_cancelled(void)
{
    m.cancelled = true;
    cout<<m.cancelled<<endl;;
    cout<<"The Match with id "<<m.id<<" was CANCELLED"<<endl;
}

int main(int argc, char** argv)
{
    
    
    MATCH(125) TEAM(AOAN) - TEAM(Ierapetra) COMBINATION(1) ODDS
            
    FULLTIME_RESULT[HOMEWIN=1.56,DRAW=2.51,AWAYWIN=1.45],
    HALFTIME_RESULT [HOMEWIN=1.61,DRAW=2.78,AWAYWIN=2.25],
    OVER=3.40,UNDER=1.35;
    
    MATCH(126) TEAM(Ergo) - TEAM(Platanias) COMBINATION(1) ODDS
    
    HALFTIME_RESULT [HOMEWIN=1.55,DRAW=2.5,AWAYWIN=1.25],
    FULLTIME_RESULT[HOMEWIN=1.88,DRAW=2.3,AWAYWIN=1.23],
    
    OVER=1.40,UNDER=1.10;
    
   
    MATCH(127) TEAM(AOChania) - TEAM(Ofi) COMBINATION(1) ODDS
    
    HALFTIME_RESULT [HOMEWIN=1.85,DRAW=2.45,AWAYWIN=3.40],
    OVER=1.40,UNDER=2.10,
    FULLTIME_RESULT [HOMEWIN=1.20,DRAW=1.99,AWAYWIN=2.23];
   
    MATCH(128) TEAM(Episkopi) - TEAM(Kissamikos) COMBINATION(1) ODDS
    FULLTIME_RESULT [HOMEWIN=1.15,DRAW=2.53,AWAYWIN=5.23],
    OVER=1.32,UNDER=3.10,
    HALFTIME_RESULT [HOMEWIN=1.35,DRAW=1.57,AWAYWIN=3.60];
   
   
    
    BET(Bet1) MATCH(127) OVER,
            MATCH(126) OVER;AMMOUNT(45);
    BET(Bet2) MATCH(127) UNDER,
            MATCH(126) UNDER;AMMOUNT(45);
            
    BET(Bet3) MATCH(125) OVER,
            MATCH(128) OVER;AMMOUNT(45);
    
    
    RESULTS MATCH(127) FULLTIME_RESULT(3,2),
             HALFTIME_RESULT(0,1);
    
    MATCH(126) CANCELLED;
    
     
               
    
    return 0;
}
