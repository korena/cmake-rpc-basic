#include <stdio.h>
#include <stdlib.h>

#include "printmsg.h"

/* Print a message to the console.
* Return a boolean indicating whether
* the message was actually printed. */
int printmessage(char *msg) {
    FILE *f;
    f = fopen("/dev/console", "w");
    if (f == (FILE *) NULL) {
        return (0);
    }
    fprintf(f, "%s\n", msg);
    fclose(f);
    return (1);
}
