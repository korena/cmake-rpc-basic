#include <stdlib.h>
#include <stdio.h>
#include "printmsg.h"
#include "rprintmsg.h"


int main(int argc, char** argv)
{
    char *server;
    char *message;
    if (argc != 3) {
        fprintf(stderr, "usage: %s hostmessage\n", argv[0]);
        exit(1);
    }

    server = argv[1];
    message = argv[2];
    if (!printmessage(message)) {
        fprintf(stderr, "%s: couldn't print your message locally\n ",argv[0]);
        exit(1);
    }
    printf("Message Delivered locally!\n");

    rprintmsg_1(server, message);

    exit(0);
}
