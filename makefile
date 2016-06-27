CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

#CXXFLAGS += =03
LDFLAGS = -lboost_date_time

OBJS = contestant.o flavorVault.o game.o ingredient.o judgingTable.o outside.o pantry.o space.o workSpace.o main.o  

SRCS = contestant.cpp flavorVault.cpp game.cpp ingredient.cpp judgingTable.cpp outside.cpp pantry.cpp space.cpp workSpace.cpp main.cpp

HEADERS = contestant.hpp flavorVault.hpp game.hpp ingredient.hpp judgingTable.hpp outside.hpp pantry.hpp space.hpp workSpace.hpp

#target: dependencies
#	rule to build 
#	

bakeOff: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o bakeOff

${OBJS}: ${SRC}
	${CXX} ${CXXFLAGS} ${SRCS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} bakeOff
