CXX=g++
SRC=src
INC=inc
BLD=build
CXXFLAGS=-Wall -I${INC}
SRCS=${SRC}/%.cpp
INCS=${INC}/%.h
OBJS=${BLD}/

main: ${OBJS} ${SRCS} ${INCS}
	${CXX} ${CXXFLAGS} -o $@ $^

${BLD}/%.o: ${SRCS}
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -rf *.o build/*.o main
