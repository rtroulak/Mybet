/**
* 
* @author  Troulakis Georgios Rafail <rtroulak@gmail.com> 
* @version 1.0
* @since   2014-02-01 
*/
#ifndef macros_h
#define	macros_h



#define MATCH(id)  m = make_new_match(id),
#define BET(bname) b = make_new_bet(#bname),
#define RESULTS r=make_new_results();
#define AMMOUNT(id) kerdos(id);
#define TEAM(name) (string(#name))
#define COMBINATION(num);  m.combination.number = num;
#define ODDS o = make_new_odd(); 
#define HALFTIME_RESULT *temp = make_new_half()
#define FULLTIME_RESULT *temp = make_new_full()
#define HOMEWIN temp->homewin
#define DRAW temp->draw
#define AWAYWIN temp->awaywin
#define OVER m.over
#define UNDER m.under
#define END ; insert(m);
#define CANCELLED match_cancelled();
#define xstr(s) str(s)
#define str(s) #s

#endif