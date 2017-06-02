CFLAGS := -std=c99 -Wall -pedantic

OBJS := btree.o functions.o

main.exe : main.o $(OBJS)
	gcc $^ -o $@

%.o : %.c *.h
	gcc $(CFLAGS) -c $<

clean :
	del *.o *.exe
