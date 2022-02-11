/*
 * Example usage
 *
 */
#include <stdio.h>
#include <stdbool.h>

#include "command_line.h"

extern void dump_cmd_line(cmd_line);

int main(int argc, char** argv) {

    cmd_line cl = create_cmd_line("This is some test text that will appear at the top\nto demonstrate the functionality.");

    add_bool_param(cl, "tboolp", "-a", "Required true bool param", true, CF_REQD|CF_NONE);
    add_bool_param(cl, "fboolp", "-b", "Required false bool param", false, CF_REQD|CF_NONE);
    add_str_param(cl, "plart", "-s", "Required srting param", "astring", CF_REQD);
    add_num_param(cl, "number", "-i", "Optional some number or other", 123, 0);
    add_none_param(cl, "nonething", "-n", "Optional none parameter", CF_NONE);

    parse_cmd_line(cl, argc, argv);

    const char* str = get_str_param(cl, "plart");
    fprintf(stdout, "string: %s\n", str);

    int num = get_num_param(cl, "number");
    fprintf(stdout, "number: %d\n", num);

    dump_cmd_line(cl);
    return 0;
}
