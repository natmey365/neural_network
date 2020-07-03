CXX=g++
VPATH = src:inc
SRC=src
INC=inc
BLD=build
CXXFLAGS=-Wall -I${INC}
SRCS=${SRC}/%.cpp
INCS=${INC}/%.h
OBJS=${BLD}/

main: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ $<

${BLD}/%.o: ${SRCS}
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -rf *.o build/*.o main
