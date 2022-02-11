OBJS	=	command_line.o memory.o
CONFIG	=	-DUSE_EXCESS=1 -DEXCESS_REQUIRED=1

all: test_cl libcmd.a

.c.o:
	gcc -Wall -Wextra -g $(CONFIG) -c $< -o $@

test_cl: $(OBJS)
	gcc -Wall -Wextra -g $(CONFIG) -o test_cl test_cl.c $(OBJS)

libcmd.a: $(OBJS)
	ar crs libcmd.a $(OBJS)

clean:
	-rm -f test_cl libcmd.a $(OBJS)
