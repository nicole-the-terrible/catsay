#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_bubble(const char *message) {
    int len = strlen(message);
    printf(" ");
    for (int i = 0; i < len + 2; i++) printf("-");
    printf("\n");

    printf("< %s >\n", message);

    printf(" ");
    for (int i = 0; i < len + 2; i++) printf("-");
    printf("\n");
}

void print_default_cat() {
    printf("       \\     /\\_/\\\n");
    printf("        \\   ( o.o )\n");
    printf("             > ^ <\n");
}

void print_eepy_cat() {
    printf("       |\\      _,,,---,,_\n");
    printf("ZZZzz /,`.-'`'    -.  ;-;;,_\n");
    printf("     |,4-  ) )-,_. ,\\ (  `'-'\n");
    printf("    '---''(_/--'  `-'\\_)\n");
}

int main(int argc, char *argv[]) {
    int use_eepy_cat = 0;
    char message[512] = {0};

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-z") == 0) {
            use_eepy_cat = 1;
        } else {
            if (strlen(message) + strlen(argv[i]) + 1 < sizeof(message)) {
                strcat(message, argv[i]);
                if (i < argc - 1) strcat(message, " ");
            } else {
                fprintf(stderr, "Message too long!\n");
                return 1;
            }
        }
    }

    if (strlen(message) == 0) {
        printf("Usage: %s [-z] \"your message here :3c\"\n", argv[0]);
        return 1;
    }

    print_bubble(message);
    if (use_eepy_cat) {
        print_eepy_cat();
    } else {
        print_default_cat();
    }

    return 0;
}
