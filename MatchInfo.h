/**
* 
* @author  Troulakis Georgios Rafail <rtroulak@gmail.com> 
* @version 1.0
* @since   2014-02-01 
*/
#ifndef MATCHINFO_H
#define	MAtCHINFO_H
#include <iostream>
#include <vector>

using namespace std;

enum myenum{yes,no};


class Combination
{
    public:
    
    int number;
    Combination();
};

class Homewin
{
    public:
    
    float number;
    Homewin();
    Homewin operator = (double d);
};


class Draw
{
    public:
    
    float number;
    Draw();
    Draw operator = (double d);
};


class Awaywin
{
    public:
    
    float number;
    Awaywin();
    Awaywin operator = (double d);
};



class Info
{
    public:
    
    Homewin homewin;
    Draw draw;
    Awaywin awaywin;
    int mode;
    int typeofodd;
    Info();
    Info(Homewin homewin,Draw draw);
    Info operator()(Homewin x);
    Info operator()(Awaywin x);
    Info operator()(Draw x);
    Info operator[](Info info);
     Info operator () (int t1_score,int t2_score);
    
};

class Odds
{
    public:
    Info fulltime;
    Info halftime;
    Odds();
    Odds(Info full, Info half);
    
    
};

class Over
{

    public:
    
    float number;
    Over();
    Over operator = (double d);
};

class Under
{
    public:
    
    float number;
    Under();
    Under operator = (double d);
};

class Match
{
    public:
    
    int id;
    int tmpid;
    int type;
    string team1;
    string team2;
    Combination combination;
    Over over;
    float overnumber;
    float undernumber;
    Under under;
     bool cancelled ;
    int half_score1;
    int half_score2;
    int full_score1;
    int full_score2;
    Odds odds;
    float hhome,fhome,hdraw,fdraw,haway,faway;
    int isOver;
    Match();
    Match(int id);
};

class Bet
{
    public:
        Bet();
        Bet(string bname);
        string bname;
        int actbet;
        float ammount;
        Match current_match;
        Bet operator[](enum myenum);
    
};
        
class Results{
        public:
    Results();
    int rid;
    int nogf;
    bool over;
    bool under;
    int activr;
    Results  operator[](Info i);
    

};


#endif	/* MATCHINFO_H */

        

