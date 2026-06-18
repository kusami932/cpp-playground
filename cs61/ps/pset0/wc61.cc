// Objective: Reason through a nontrivial specification for an input/output program.
#include <cstdio>
#include <cctype>

int main() {
    unsigned long nc = 0, nw = 0, nl = 0;
    bool in_spaces = true;
    while (true) {
        int ch = fgetc(stdin);
        if (ch == EOF) {
            break;
        }
        ++nc;

        bool this_space = isspace((unsigned char)ch);
        if (in_spaces && !this_space) {
            ++nw;
        }
        in_spaces = this_space;

        if (ch == '\n') {
            ++nl;
        }
    }

    fprintf(stdout, "%8lu %7lu %7lu\n", nl, nw, nc);
}