CFLAGS := -std=c++11 -Wall -pedantic

OBJS := functions.o phone.o

main.exe : main.o $(OBJS)
	g++ $^ -o $@

%.o : %.cpp *.hpp
	g++ $(CFLAGS) -c $<

clean :
	del *.o *.exe
