
CC = gcc
PROG = led
OBJS = main.o

CFLAGS = -g -Wall
LIBS = -lwiringPi


$(PROG): $(OBJS)
	$(CC) $(LIBDIR) $(LIBS) $(CFLAGS) -o $(PROG) $^

tags:
	etags *.[ch]

# ファイル削除用ターゲット
.PHONY: clean
clean:
	rm -f $(PROG) $(OBJS) a.out TAGS tags

cleandir:
	rm -f $(PROG) $(OBJS) a.out TAGS tags *core *~

