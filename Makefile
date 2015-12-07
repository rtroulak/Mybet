main.o:main.cpp macros.h MatchInfo.h
	g++ -Wall -c main.cpp
MatchInfo.o:MatchInfo.h
	g++ -Wall -c MatchInfo.cpp
mybet:
	g++ -Wall main.o MatchInfo.o -o mybet
clean:
	rm *.o
