
test_cl: command_line.c memory.c
	gcc -Wall -Wextra -g -DTESTING -DUSE_EXCESS=1 -DEXCESS_REQUIRED=1 -o test_cl command_line.c memory.c

clean:
	-rm -f test_cl
